// Prikazy.cpp: implementation of the CZpracPrik class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Prikazy.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPrikazy::CPrikazy()
{

}

CPrikazy::CPrikazy(const CPrikazy &prikaz)
{
	Telo = prikaz.Telo;
	Nazev = prikaz.Nazev;
	PoleParam.Copy(prikaz.PoleParam);
	Pozice = 0;
}

CPrikazy::~CPrikazy()
{
	Telo.Empty();
	Nazev.Empty();
}

CPrikazy *CPrikazy::operator =(CPrikazy &prikaz)
{
	this->Telo = prikaz.Telo;
	Nazev = prikaz.Nazev;
	PoleParam.Copy(prikaz.PoleParam);
	Pozice = prikaz.Pozice;

	return this;
}
//DEL CPrikazy::operator =(CExpression &vyraz)
//DEL {
//DEL 	Nazev = vyraz.Jmeno;
//DEL 
//DEL 	for(int i = 0; i<=vyraz.StringParam.GetUpperBound();i++)
//DEL 	{
//DEL 		CParametrs param;
//DEL 		param.Nazev = vyraz.StringParam[i];
//DEL 		PoleParam.Add(param);
//DEL 	}
//DEL }

CString CPrikazy::ReturnLine()
{
	CString ret;

	bool give = false;
	int	k = 0;

	if (Pozice == Telo.GetLength()) return "end";

	for (Pozice; Telo[Pozice] != '\n'; Pozice++)
	{
		if (Telo[Pozice] == '\0') return "end";
		ret.Insert(k, Telo[Pozice]);
		k++;
	}

	//CExpression vyraz(ret);

	/*ret.Empty();

	if(vyraz.Knihovna!=NULL)
	{
		ret.Insert(ret.GetLength(),*vyraz.Knihovna);
		ret.Insert(ret.GetLength(),'.');
	}

	ret.Insert(ret.GetLength(),vyraz.Jmeno);

	ret.Insert(ret.GetLength(),'(');

	if((vyraz.Jmeno == MAKE) || (vyraz.Jmeno == IF )|| (vyraz.Jmeno == WHILE)||(vyraz.Jmeno == LEND)||(vyraz.Jmeno == TEND)
		||(vyraz.Jmeno == IEND)||(vyraz.Jmeno == WEND)||(vyraz.Jmeno == END))
	{
		Pozice++;
		return vyraz.Vyraz;//.StringParam.RemoveAt(0);
	}

	for(i = 0;i<=vyraz.StrParLen();i++)
		//	for(int j = 0;j<=PoleParam.GetUpperBound();j++)
	{
		for(int j = 0;j<=PoleParam.GetUpperBound();j++)
			//		for(i = 0;i<=vyraz.StrParLen();i++)
		{
			if(vyraz.StringParam[i]==PoleParam[j].Nazev)
			{
				char z[50];
				if(ret[ret.GetLength()-1]!='(')		ret.Insert(ret.GetLength(),',');
				_gcvt(PoleParam[j].Hodnota,5,z);
				ret.Insert(ret.GetLength(),z);
				give=true;
			}
		}

		float numero = atoi(vyraz.StringParam[i]);//vyraz.StringParam[i][0];

		//if((vyraz.StringParam[i][0]=='0')||(numero!=0))
		if(vyraz.NumParLen()>=i)
		if(numero == vyraz.NumberParam[i])
		{
			if(ret[ret.GetLength()-1]!='(')		ret.Insert(ret.GetLength(),',');

			ret.Insert(ret.GetLength(),vyraz.StringParam[i]);
		}
	}

	ret.Insert(ret.GetLength(),')');*/
	//	ret = GetSpaceOut(ret);
	Pozice++;
	return ret;
}

//DEL CString CPrikazy::ReturnName(CString command)
//DEL {
//DEL 	CString ret;
//DEL 	int x = command.Find('(');
//DEL 	int y = command.Find(' ');
//DEL 	if ((x>y)&&(y>0)) x=y;
//DEL 	if(x==-1) x = command.GetLength();
//DEL 	for(int i = 0;i<x;i++)
//DEL 	{
//DEL 		if(command[i]!=' ')ret.Insert(i,command[i]);
//DEL 		else return ret;
//DEL 	}	
//DEL 	return ret;
//DEL }

//DEL CString CPrikazy::ReturnParams(CString command)
//DEL {
//DEL 	//new
//DEL 	CString ret;
//DEL 
//DEL 	int k = 0;
//DEL 
//DEL 	int x = command.Find('(');
//DEL 	int y = command.Find(' ');
//DEL 	
//DEL 	if(x==-1)//vyraz neobsahuje zavorku
//DEL 	{
//DEL 		if(y>0)//ale obsahuje mezeru
//DEL 		{//vezmu od mezery do konce
//DEL 			k=0;
//DEL 			for(int i = y;i<command.GetLength();i++)
//DEL 			{
//DEL 				if(command[i]!=' ') 
//DEL 				{
//DEL 					ret.Insert(k,command[i]);
//DEL 					k++;
//DEL 				}
//DEL 			}
//DEL 		}
//DEL 		else//neni tam ani mezera
//DEL 			return command;
//DEL 	}
//DEL  	else//obsahuje zavorku
//DEL 	{
//DEL 		if((y<x)&&(y>=0)) //mezera je pred zavorkou
//DEL 		{
//DEL 			k=0;
//DEL 			for(int i = y;i<command.GetLength();i++)
//DEL 			{
//DEL 				
//DEL 				if(command[i]!=' ') 
//DEL 				{
//DEL 					ret.Insert(k,command[i]);
//DEL 					k++;
//DEL 				}
//DEL 			}	
//DEL 		}
//DEL 		else //mezera je za zavorkou
//DEL 		{	k=0;
//DEL 			for(int i = x;i<command.GetLength();i++)
//DEL 			{
//DEL 				if((command[i]!=' ')&&(command[i]!='(')&&(command[i]!=')'))	
//DEL 				{
//DEL 					ret.Insert(k,command[i]);
//DEL 					k++;
//DEL 				}
//DEL 			}
//DEL 		}
//DEL 	}
//DEL  	return ret;
//DEL }

//DEL void CPrikazy::ZpParametry(CString param)
//DEL {
//DEL // 	PomParametry.RemoveAll();
//DEL  	param.Insert(param.GetLength(),',');
//DEL  	CString p1;
//DEL  	int k = 0;
//DEL  	for(int i = 0;i<param.GetLength();i++)
//DEL  	{		
//DEL  		if(param[i]!=',')
//DEL  		{
//DEL 			p1.Insert(k,param[i]);
//DEL  			k++;
//DEL  		}
//DEL  		else 
//DEL  		{
//DEL  //			PomParametry.Add(p1);
//DEL 			p1.Empty();
//DEL  			k=0;
//DEL  		}
//DEL  	}
//DEL }

int CPrikazy::PoleParamLenght()
{
	return PoleParam.GetUpperBound();
}

CParametrs *CPrikazy::FindProm(CString prom)
{
	for (int i = 0; i <= PoleParam.GetUpperBound(); i++)
	{
		if (PoleParam[i].Nazev == prom) return &PoleParam[i];
	}
	return NULL;
}

//DEL float CPrikazy::GetParamValue(CString param)
//DEL {
//DEL 	CParametrs *pom;
//DEL 	pom = FindProm(param);
//DEL 	if(pom) return pom->Hodnota;
//DEL 	else AfxMessageBox("Promenna "+param+" neexistuje");
//DEL 	return 0;
//DEL }

CString CPrikazy::GetSpaceOut(CString ret)
{
	if (ret.IsEmpty())
		return ret;
	if (ret.Find(' ', 0) == -1)
		return ret;

	int i = 0;

	for (;;)
	{
		if (ret[i] == ' ')
			ret.Delete(i, 1);
		else
		{
			if (i == ret.GetLength())
				return ret;
			i++;
		}
		if (i == ret.GetLength())
			return ret;
	}
}
