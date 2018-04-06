// Expression.cpp: implementation of the CExpression class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Expression.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExpression::CExpression(CString ret, CPrikazy *prik)
{		
	int i = 0;
	bool sys = false;
	
	Prikaz = prik;

	if(!ret.IsEmpty())
		if(ret.Find(' ',0)>-1)
			ret = GetSpaceOut(ret);


	if(ret.Find(DEFINE,0)!=-1)
	{	
		ret.Insert(6,' ');
		sys = true;
	}
	if(ret.Find(INCLUDE,0)!=-1)
	{
		ret.Insert(7,' ');
		sys = true;
	}

	int tecka	= ret.Find(Tecka,0);
	int mezera	= ret.Find(Mezera,0);
	int zavorka1 = ret.Find(LZavorka,0); 
	int zavorka2 = ret.Find(PZavorka,0); 

	int zz2 = ret.Find(PZavorka,zavorka2+1);

	while(zz2!=-1)
	{
		zz2 = ret.Find(PZavorka,zavorka2+1);
		if(zz2!=-1)
			zavorka2 = zz2;
		//else break;
			
	}
	





	Knihovna = NULL;
	
	if(zavorka1!=-1)//obsahuje '('
	{
		if((tecka!=-1)) //retezec obsahuje '.'
		{
			if(tecka<zavorka1) //tecka je pred zavorkou
			{
				Knihovna = new CString;
				*Knihovna = GetFromTo(0,tecka,ret);
				Jmeno = GetFromTo(tecka+1,zavorka1,ret);

				if(zavorka2!=-1) //nechyby ')'
				{
					Param = GetFromTo(zavorka1+1,zavorka2,ret);
				}
				else 
				{
					Param = GetFromTo(zavorka1+1,ret.GetLength(),ret);
				}
			}
			else //tecka je za zavorkou
			{
				Jmeno = GetFromTo(0,zavorka1,ret);
				Param = GetFromTo(zavorka1+1,zavorka2,ret);
			}
		}
		else
		{
			if((mezera!=-1)&&(mezera<zavorka1)) //retezec obsahuje mezeru
			{
				//if(mezera<zavorka1)//mezera je pred zavorkou
				{
					Jmeno = GetFromTo(0,mezera,ret);
					Param = GetFromTo(mezera+1,ret.GetLength(),ret);
				}
			}
			else//mezera je za zavorkou nebo neni vubec
			{
				Jmeno = GetFromTo(0,zavorka1,ret);
				Param = GetFromTo(zavorka1+1,zavorka2,ret);
			}
		}
	}
	else //neobsahuje '('
	{
		if(mezera!=-1) //obsahuje mezeru
		{
			Jmeno = GetFromTo(0,mezera,ret);
			Param = GetFromTo(mezera+1,ret.GetLength(),ret);
		}
		else
			Jmeno = ret;
	}
	if(!sys)
		GetParam(0,Param);
}
CExpression::CExpression(CExpression &vyraz)
{
	Prikaz = vyraz.Prikaz;
	Jmeno = vyraz.Jmeno;
	Knihovna = vyraz.Knihovna;
	Param = vyraz.Param;
	PoleParam.Copy(vyraz.PoleParam);	
}


CExpression::~CExpression()
{
	PoleParam.RemoveAll();
}

CString CExpression::GetFromTo(int from, int to, CString ret)
{
	CString retez;
	int index = 0;

	for(int i = from;i<to;i++)
	{
		if(ret[i]!=' ')
		{
			retez.Insert(index,ret[i]);
			index++;
		}
	}

	return retez;

}

void CExpression::GetParam(int poz, CString ret)
{
	CString pom;

	CParametrs param;

	int k = 0;

	ret.Insert(ret.GetLength(),' ');

	for(int i = 0;i<ret.GetLength();i++)
	{		
		if((ret[i]!=',')&&(ret[i]!=' '))
		{			
			pom.Insert(k,ret[i]);
			k++;
		}
		else 
		{
			if(!pom.IsEmpty())
			{
				param.Nazev = pom;// StringParam.Add(pom);				
				param.Hodnota = Evaluate(pom);
				PoleParam.Add(param);
			}
			pom.Empty();
			k=0;
		}
	}
}

//DEL bool CExpression::IsOk(CString co, char znak)
//DEL {
//DEL 	if(co=="cislo")
//DEL 	{
//DEL 		if(((znak>47)&&(znak<58))||(znak==Tecka)) return true;
//DEL 		else return false;
//DEL 	}
//DEL 	if(co=="znak")
//DEL 	{
//DEL 		if((znak>64)&&(znak<123)) return true;
//DEL 		else return false;
//DEL 	}
//DEL 	if(co=="both")
//DEL 	{
//DEL 		if((znak>47)&&(znak<58) || (znak>64)&&(znak<123) || (znak==Tecka) ) return true;
//DEL 	}
//DEL 	return false;
//DEL }

int CExpression::NumParLen() //velikost NumberParam.GetUpperBound()
{
//	return NumberParam.GetUpperBound();
	return PoleParam.GetUpperBound();
}

//DEL int CExpression::StrParLen() //StringParam.GetUpperBound()
//DEL {
//DEL //	return StringParam.GetUpperBound();
//DEL 	return PoleParam.GetUpperBound();
//DEL }

CString CExpression::GetSpaceOut(CString ret)
{
	int i = 0;
	
	for(;;)
	{
		if(ret[i]==' ')
			ret.Delete(i,1);
		else 
		{			
			if(i == ret.GetLength())
				return ret;
			i++;			
		}
		if(i == ret.GetLength())
				return ret;
	}
}

double CExpression::Evaluate(CString ret)
{
	if(!Prikaz)
		return atof(ret);
	
	double number = 0;
	CString retez;
	IMaPaInter *MathParser;
	MathParser = new IMaPaInter;
	
	BSTR pom;
	
//	ret.Insert(ret.GetLength(),' ');
	
	for(int i = 0;i<=Prikaz->PoleParam.GetUpperBound();i++)
	{
		pom = Prikaz->PoleParam[i].Nazev.AllocSysString();
		MathParser->AddString(&pom, &Prikaz->PoleParam[i].Hodnota);
		SysFreeString(pom);
	}
	pom = ret.AllocSysString();
	
	number = MathParser->Parse(&pom);	

	SysFreeString(pom);
	CString ErrMes = MathParser->GetErrorMes();
/*	if(!ErrMes.IsEmpty())
		AfxMessageBox(ErrMes);*/
	
	MathParser->ReleaseDispatch();
	delete MathParser;
	return number;
}
