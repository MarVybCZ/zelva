// Interpret.cpp: implementation of the CInterpret class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Interpret.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInterpret::CInterpret()
{
	Zelva = new CTurtle();
	ActualCommand = new CPrikazy;
	ActualLibrary = -1;
}

CInterpret::~CInterpret()
{
	delete ActualCommand;
	delete Zelva;
}

/********************************************************************
nahraje do interpretu soubor
	File	: in CString - cesta k pozadovanemu souboru
	return	: void
********************************************************************/
void CInterpret::LoadFile(CString File)
{
	CString message;
	CString blok;
	CString ret;
	int lib = -1;
	FILE *soub;
	bool Acess = false;

	for (int i = 0; i <= PoleKnihoven.GetUpperBound(); i++)
	{
		if (PoleKnihoven[i].Cesta == File)
		{
			int x = AfxMessageBox("Soubor je jiz nahran \n chcete ho reloadnout?", MB_YESNO, 0);
			if (x == IDNO) return;

		}
	}

	soub = soubor;

	if ((fopen_s(&soubor, File, "r")) != NULL)
	{
		message = "The file '" + File + "' was not opened.";
		Acess = false;
	}
	else
	{
		message = "The file '" + File + "' was opened.";
		Acess = true;
	}
	//AfxMessageBox( message,MB_OK, 0);

	if (Acess)
	{
		if (ActualLibrary > -1) lib = ActualLibrary;
		AddLibrary(File);

		while (!feof(soubor))
		{
			blok = NactiRadek(soubor);
			ZpracujPrikaz(blok, 1);
		}
		fclose(soubor);

		if (lib > -1)	ActualLibrary = lib;

	}

	soubor = soub;
	//	Cesta = File;
}

/********************************************************************
nacte radek ze souboru
	soub	: in *FILE - source file
	return	: CString jeden radek ze souboru
********************************************************************/
CString CInterpret::NactiRadek(FILE *soub)
{
	char znak;
	CString retezec;
	do
	{
		znak = fgetc(soub);
		if (feof(soub))
		{
			return retezec;
		}
		else
		{
			if ((znak != '\n') && (znak != 13)) retezec.Insert(retezec.GetLength(), znak);
		}
	} while (znak != '\n');
	return retezec;
}

/********************************************************************
nacte ze souboru define .. end blok
	soub	: in *FILE - zdrojovy soubor
	velikost: in -1 pro define .. end directive / else pocet radku
	return	: CString retezec
********************************************************************/
CString CInterpret::NactiBlok(FILE *soub)
{
	bool x = true;
	CString retezec;
	CString radek;

	do
	{
		radek = NactiRadek(soub);
		radek = CPrikazy::GetSpaceOut(radek);
		if ((!feof(soub)) && (radek != END))
		{
			retezec += radek;
			retezec += '\n';
		}
		if (radek == END)
			return retezec;
		if (feof(soub))
			return NOEND;
	} while (radek != "end");

	return retezec;
}

/********************************************************************
vyhodnoti define direcktivu
	param	: in CString param - define 'ctverec()'
	return	: void
********************************************************************/
void CInterpret::Define(CString param)
{
	CPrikazy pom;
	CPrikazy *findpom;

	CExpression vyraz(param);

	//	pom = vyraz;
		//misto predchoziho radku
	pom.Nazev = vyraz.Jmeno;
	for (int i = 0; i <= vyraz.PoleParam.GetUpperBound(); i++)
	{
		CParametrs param;
		param.Nazev = vyraz.PoleParam[i].Nazev;
		pom.PoleParam.Add(param);
	}
	//az po sem

	pom.Telo = NactiBlok(soubor);
	if (pom.Telo == NOEND)
	{
		CString err;
		err = "Prikaz: "; err += pom.Nazev;
		err += "\nParametry: "; err += vyraz.Param;
		err += "\nDefine nema prislusici 'end'";
		AfxMessageBox(err, 0);
		return;
	}

	findpom = PoleKnihoven[ActualLibrary].Find(pom.Nazev);
	if (findpom != NULL)
	{
		CString x = "pom.Nazev =" + pom.Nazev;
		AfxMessageBox("Prikaz jiz existuje", 0);
	}
	else
		PoleKnihoven[ActualLibrary].Add(&pom);
}

/********************************************************************
vrati pointer na hledany uzivatelem definovany prikaz
	prikaz	: in CString - nazev prikazu
	khinovna: in *CString - nazev knihovny = NULL
	return	: *CPrikazy
********************************************************************/
CPrikazy *CInterpret::FindPrikaz(CString prikaz, CString *knihovna = NULL)
{
	CPrikazy *pomprik = NULL;

	if (knihovna == NULL)
	{
		for (int i = 0; i <= PoleKnihoven.GetUpperBound(); i++)
		{
			pomprik = PoleKnihoven[i].Find(prikaz);
			if (pomprik != NULL) return pomprik;
		}
	}
	else
	{
		for (int i = 0; i <= PoleKnihoven.GetUpperBound(); i++)
		{
			if (PoleKnihoven[i].Nazev == *knihovna)
				pomprik = PoleKnihoven[i].Find(prikaz);
			if (pomprik != NULL) return pomprik;
		}
	}
	return NULL;
}

/********************************************************************
zpracuje prikazy pro zelvu
	vyraz	: in CExpression
	return	: bool 'true' ok / else 'else'
********************************************************************/
bool CInterpret::ForTurtle(CExpression vyraz)
{
	CString prik = vyraz.Jmeno;
	/*CArray<double, double> param;
	CArray<CString, CString> Stparam;

	param.Copy(vyraz.NumberParam);
	Stparam.Copy(vyraz.StringParam);

	*/

	if (prik == FORWARD)
	{
		if (vyraz.PoleParam.GetSize() > 0)
		{
			Zelva->Forward(vyraz.PoleParam[0].Hodnota); //param[0]);
			return true;
		}
		else return false;
	}
	if (prik == SETCOL)
	{
		if (vyraz.PoleParam.GetSize() >= 3)
		{
			//Zelva->SetColor(param[0],param[1],param[2]);
			Zelva->SetColor(vyraz.PoleParam[0].Hodnota, vyraz.PoleParam[1].Hodnota, vyraz.PoleParam[2].Hodnota);
			return true;
		}
		else return false;
	}
	if (prik == CLEAR)
	{
		Zelva->clear();
		return true;
	}
	if (prik == SETPOS)
	{
		if (vyraz.PoleParam.GetSize() >= 3)
		{
			//Zelva->setposition(param[0],param[1],param[2]);
			Zelva->setposition(vyraz.PoleParam[0].Hodnota, vyraz.PoleParam[1].Hodnota, vyraz.PoleParam[2].Hodnota);
			return true;
		}
		else return false;
	}
	if (prik == HOME)
	{
		Zelva->home();
		return true;
	}/*
	if(prik == "back")
	{
		Zelva->back();
		return true;
	}*/
	if (prik == TRANS)
	{
		if (vyraz.PoleParam.GetSize() >= 4)
		{
			//Zelva->Trans(param[0],param[1],param[2],param[3]);
			Zelva->Trans(vyraz.PoleParam[0].Hodnota, vyraz.PoleParam[1].Hodnota, vyraz.PoleParam[2].Hodnota, vyraz.PoleParam[3].Hodnota);
			return true;
		}
		else return false;
	}
	if (prik == LeftR)
	{
		if (vyraz.PoleParam.GetSize() > 0)
		{
			Zelva->LR(vyraz.PoleParam[0].Hodnota);//param[0]);
			return true;
		}
		else return false;
	}
	if (prik == UpD)
	{
		if (vyraz.PoleParam.GetSize() > 0)
		{
			Zelva->UD(vyraz.PoleParam[0].Hodnota);
			return true;
		}
		else return false;
	}
	if (prik == Clock)
	{
		if (vyraz.PoleParam.GetSize() > 0)
		{
			Zelva->CL(vyraz.PoleParam[0].Hodnota);
			return true;
		}
		else return false;
	}
	if (prik == PENUP)
	{
		Zelva->PenFnc(true);
		return true;
	}
	if (prik == PENDOWN)
	{
		Zelva->PenFnc(false);
		return true;
	}

	/*if(retvalue)
	{
		HistZelvy.Insert(HistZelvy.GetLength(), vyraz.Vyraz);
		HistZelvy.Insert(HistZelvy.GetLength(),'\n');
	}*/
	return false;
}

/********************************************************************
Zpracuje vsechny prikazy
	ret		: in CString libovolny retezec
	x		: in int 0 pro zelvi a uzivateli prikazy other pro cokoli
	return	: void
********************************************************************/
void CInterpret::ZpracujPrikaz(CString ret, int x)
{
	CPrikazy pom;
	CString prik;
	CString param;

	if (ret.IsEmpty()) return;

	CExpression vyraz(ret, ActualCommand);

	if (x == 0)
	{
		if (ForTurtle(vyraz))
		{
			InvalidateRect(NULL, FALSE, FALSE);
			return;
		}
		if (UserCommand(vyraz))
		{
			InvalidateRect(NULL, FALSE, FALSE);
			return;
		}
		AfxMessageBox("Spatny prikaz", MB_OK, 0);
	}
	else
	{
		if (ForTurtle(vyraz))
		{
			//InvalidateRect(NULL,FALSE,FALSE);
			return;
		}
		if (ForInterpret(vyraz))
		{
			//InvalidateRect(NULL,FALSE,FALSE);
			return;
		}
		if (UserCommand(vyraz))
		{
			//InvalidateRect(NULL,FALSE,FALSE);
			return;
		}
		//	if(prik!=""){
		prik = "Vyraz: "; prik += vyraz.Jmeno;
		prik += "\nParametry: "; prik += vyraz.Param;
		prik += "\nSyntakticka chyba";
		AfxMessageBox(prik, MB_OK, 0);

	}
	//InvalidateRect(NULL,FALSE,FALSE);
}

/********************************************************************
zpracuje interperem definovane prikazy
	vyraz	: in CExpression
	return	: bool - true o.k. false if failur
********************************************************************/
bool CInterpret::ForInterpret(CExpression vyraz)
{
	CString prik = vyraz.Jmeno;
	CString param = vyraz.Param;

	if (prik == DEFINE)
	{
		Define(param);
		return true;
	}
	if (prik == WHILE)
	{
		While(param);
		return true;
	}
	if (prik == LOOP)
	{
		Loop(param);
		return true;
	}
	if (prik == INCLUDE)
	{
		LoadFile(param);
		return true;
	}
	if (prik == MAKE)
	{
		Make(&vyraz);
		return true;
	}
	if (prik == IF)
	{
		IfElse(&vyraz);
		return true;
	}
	if (prik == TURTLE)
	{
		TurtleFnc();
		return true;
	}
	return false;
}

/********************************************************************
zpracuje uzivatelem definovany prikaz
	vyraz	: in CExpression
	return	: bool - if succesfull true else false
********************************************************************/
bool CInterpret::UserCommand(CExpression vyraz)
{
	CPrikazy *pom, pom2;

	CString prik = vyraz.Jmeno;

	CString prikaz;

	pom = FindPrikaz(prik, vyraz.Knihovna);

	if (pom != NULL)
	{
		if (vyraz.NumParLen() >= 0)
		{
			for (int i = 0; i <= vyraz.NumParLen(); i++)
			{
				int ppl = pom->PoleParamLenght();
				int npl = vyraz.NumParLen();
				if ((i > ppl) || (i > npl))
				{
					CString hlaska = "Pocet pararametru je " + ppl;
					CString hlaska2 = " \n pocet vstupnich parametru je " + npl;
					hlaska.Insert(hlaska.GetLength(), hlaska2);
					AfxMessageBox(hlaska);
					break;
				}
				for (int xx = 0; xx <= pom->PoleParamLenght(); xx++)
				{
					if (vyraz.NumParLen() == pom->PoleParamLenght())
					{
						//						int xxx = pom->PoleParam[xx].Hodnota;
						//						int yyy = vyraz.PoleParam[xx].Hodnota;
						//						CString xxxx = pom->PoleParam[xx].Nazev;
						//						CString yyyy = vyraz.PoleParam[xx].Nazev;

						pom->PoleParam[xx].Hodnota = vyraz.PoleParam[xx].Hodnota;//Hodnota=vyraz.NumberParam[i];
					}
					else AfxMessageBox("Nesouhlasi pocet parametru");
				}
			}
		}

		pom->Pozice = 0;

		pom2 = *ActualCommand;
		*ActualCommand = *pom;

		while (prikaz != END)
		{
			prikaz = ActualCommand->ReturnLine();
			if (prikaz == "false")
			{
				AfxMessageBox("Kriticka chyba", MB_OK, 0);
				return false;
			}
			//return true;
			if (prikaz == "end")
			{
				*ActualCommand = pom2;
				return true;
			}
			ZpracujPrikaz(prikaz, 1);
		}
		*ActualCommand = pom2;
	}
	else return false;
}

/********************************************************************
vyhodnoti loop(num) directivu
	param	: in CString - matematicky vyraz
	return	: double hodnota vyrazu
********************************************************************/
void CInterpret::Loop(CString param)
{
	CString prik;
	CPrikazy &Prik = *ActualCommand;

	int x = (int)Evaluate(param, &Prik.PoleParam);
	int poz = Prik.Pozice;
	int kon = Prik.Pozice;
	for (int i = 0; i < x; i++)
	{
		do
		{
			prik = Prik.ReturnLine();
			if (prik == END)
			{
				Chyba(LOOP);
				return;
			}

			if (prik != LEND)ZpracujPrikaz(prik, 1);
		} while (prik != LEND);
		kon = Prik.Pozice;
		Prik.Pozice = poz;
	}
	Prik.Pozice = kon;
	if (x <= 0)
		do
		{
			prik = Prik.ReturnLine();
			if (prik == END)
			{
				AfxMessageBox("Neocekavany end\nprikaz: loop");
				return;
			}
		} while (prik != LEND);
}

/********************************************************************
vyhodnoti while(expr) direktivu
	*vyraz	: in CExpression
	return	: void
********************************************************************/
void CInterpret::While(CString param)
{
	CString prik;
	CPrikazy &Prik = *ActualCommand;

	int poz = Prik.Pozice;
	int kon = Prik.Pozice;
	while (Evaluate(param, &Prik.PoleParam))
	{
		do
		{
			prik = Prik.ReturnLine();
			if (prik == END)
			{
				Chyba(WHILE);
				return;
			}
			if (prik != WEND)ZpracujPrikaz(prik, 1);
		} while (prik != WEND);
		kon = Prik.Pozice;
		Prik.Pozice = poz;
	}
	Prik.Pozice = kon;
}

/********************************************************************
prida knihovnu do pole knihoven
	cesta	: in CString cesta k souboru
	return	: bool - true if succesfull, otherwise false
********************************************************************/
bool CInterpret::AddLibrary(CString cesta)
{
	CString nazev;

	//ActualLibrary = NULL;

	int tecka = cesta.Find(Tecka);
	int index;
	if (tecka != -1)
	{
		index = tecka - 1;
	}
	else index = cesta.GetLength();

	for (int i = index; i >= 0; i--)
	{
		if (cesta[i] != 92)//92 ASCII kod '\'
			nazev.Insert(0, cesta[i]);
		else break;
	}

	for (int i = 0; i <= PoleKnihoven.GetUpperBound(); i++)
	{
		if (PoleKnihoven[i].Cesta == cesta)
		{
			ActualLibrary = i;
			return false;
		}
	}
	for (int i = 0; i <= PoleKnihoven.GetUpperBound(); i++)
	{
		if (PoleKnihoven[i].Nazev == nazev)
		{
			return false;
		}
	}
	CLibrary pom(cesta, nazev);
	PoleKnihoven.Add(pom);
	//if(!ActualLibrary)
	ActualLibrary = PoleKnihoven.GetUpperBound();
	return true;
}

/********************************************************************
provede funkci make(var, var | expression)
	*vyraz	: in CExpression
	return	: void
********************************************************************/
void CInterpret::Make(CExpression *vyraz)
{
	CParametrs *pom;

	if (vyraz->PoleParam.GetSize() != 2)
	{
		AfxMessageBox("fce make nemuze probehnout");
		return;
	}

	pom = ActualCommand->FindProm(vyraz->PoleParam[0].Nazev);//StringParam[0]);

	if (!pom)
	{
		CParametrs pom1;
		pom1.Nazev = vyraz->PoleParam[0].Nazev;//StringParam[0];
		ActualCommand->PoleParam.Add(pom1);
		pom = &ActualCommand->PoleParam[ActualCommand->PoleParamLenght()];
	}
	pom->Hodnota = Evaluate(vyraz->PoleParam[1].Nazev, &ActualCommand->PoleParam);
}

/********************************************************************
zpracuje if else statement
	*vyraz	: in - CExpression
	return	: void
********************************************************************/
void CInterpret::IfElse(CExpression *vyraz)
{
	bool hodnota;
	CString ret;
	int xx = vyraz->NumParLen();
	if (xx != 0)//StrParLen()!=0)
	{
		AfxMessageBox("If else spatny pocet parametru");
		return;
	}
	hodnota = Evaluate(vyraz->PoleParam[0].Nazev, &ActualCommand->PoleParam);
	if (!ErrMes.IsEmpty())
	{
		AfxMessageBox(ErrMes);
		return;
	}

	if (hodnota)
	{
		ret = ActualCommand->ReturnLine();
		while ((ret != ELSE) && (ret != IEND))
		{
			if (ret == END)
			{
				Chyba("If Else");
				return;
			}
			ZpracujPrikaz(ret, 1);
			ret = ActualCommand->ReturnLine();
		}
		if (ret == ELSE)
		{
			ret = ActualCommand->ReturnLine();
			while (ret != IEND)
			{
				if (ret == END)
				{
					Chyba("If Else");
					return;
				}
				ret = ActualCommand->ReturnLine();
			}
		}
	}
	else
	{
		ret = ActualCommand->ReturnLine();
		while ((ret != ELSE) && (ret != IEND))
		{
			if (ret == END)
			{
				Chyba("If Else");
				return;
			}
			ret = ActualCommand->ReturnLine();
		}
		if (ret == ELSE)
		{
			ret = ActualCommand->ReturnLine();
			while (ret != IEND)
			{
				if (ret == END)
				{
					Chyba("If Else");
					return;
				}
				ZpracujPrikaz(ret, 1);
				ret = ActualCommand->ReturnLine();
			}
		}
	}
}

double CInterpret::Evaluate(CString ret, CArray<CParametrs, CParametrs> *PoleParam)
{
	double number = 0;
	CString retez;
	IMaPaInter *MathParser;
	MathParser = new IMaPaInter;

	BSTR pom;

	//	ret.Insert(ret.GetLength(),' ');

	for (int i = 0; i <= PoleParam->GetUpperBound(); i++)
	{
		CParametrs *param;
		param = &PoleParam->GetAt(i);

		pom = param->Nazev.AllocSysString();
		MathParser->AddString(&pom, &param->Hodnota);
		SysFreeString(pom);
	}
	pom = ret.AllocSysString();

	number = MathParser->Parse(&pom);
	SysFreeString(pom);

	ErrMes = MathParser->GetErrorMes();

	MathParser->ReleaseDispatch();
	delete MathParser;
	return number;
}

CLibrary *CInterpret::FindLib(CString *lib, int *index)
{
	for (int i = 0; i <= PoleKnihoven.GetUpperBound(); i++)
	{
		if ((PoleKnihoven[i].Nazev == *lib) || (PoleKnihoven[i].Cesta == *lib))
		{
			*index = i;
			return &PoleKnihoven[i];
		}
	}
	*index = -1;
	return NULL;
}

/********************************************************************
odstrani knihovnu z pameti programu
	lib		: in CString - nazev knihovny, nebo cesta ke knihovne
	return	: void
********************************************************************/
void CInterpret::UnLoad(CString lib)
{
	int index;
	CLibrary *xx = FindLib(&lib, &index);
	if (!xx) return;
	PoleKnihoven.RemoveAt(index);
}

/********************************************************************
Obsluhuje direktivu turtle .. tend
	return	: void
********************************************************************/
void CInterpret::TurtleFnc()
{
	CString prik;
	CPrikazy &Prik = *ActualCommand;
	CTurBlok *bod;

	//CPtrArray *xxx;

	bod = new CTurBlok("BEGIN");

	Zelva->history.Add((void*)bod);
	do
	{
		prik = Prik.ReturnLine();
		if (prik == END)
		{
			Chyba("turtle .. tend");
			break;
		}
		if (prik != TEND)ZpracujPrikaz(prik, 1);
	} while (prik != TEND);

	bod = new CTurBlok("END");
	Zelva->history.Add((void*)bod);
}

void CInterpret::Chyba(CString prik)
{
	CString xxx = "Neocekavany 'end'\nPrikaz: ";
	xxx += prik;
	AfxMessageBox(xxx);
}
