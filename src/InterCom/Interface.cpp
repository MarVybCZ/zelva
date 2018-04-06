// Interface.cpp : Implementation of CInterface
#include "stdafx.h"
#include "InterCom.h"
#include "Interface.h"

/////////////////////////////////////////////////////////////////////////////
// CInterface

STDMETHODIMP CInterface::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IInterface
	};
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i], riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CInterface::Load(BSTR cesta)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		Interpret->LoadFile(cesta);

	return S_OK;
}


STDMETHODIMP CInterface::UnLoad(BSTR cesta)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// TODO: Add your implementation code here
		Interpret->UnLoad(cesta);

	return S_OK;
}

STDMETHODIMP CInterface::GetPosChange(BOOL *xx)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// TODO: Add your implementation code here
		*xx = Interpret->Zelva->Pos;

	return S_OK;
}

STDMETHODIMP CInterface::GetLibName(int x, BSTR *name)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		CString pom;
	if ((x >= 0) && (x <= Interpret->PoleKnihoven.GetUpperBound()))
	{
		pom = Interpret->PoleKnihoven[x].Nazev;
		BSTR xxx;
		xxx = pom.AllocSysString();
		*name = xxx;

		SysFreeString(xxx);

		return S_OK;
	}
	else return S_FALSE;

	return S_OK;
}

STDMETHODIMP CInterface::GetLibPath(int x, BSTR *path)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		CString pom;
	if ((x >= 0) && (x <= Interpret->PoleKnihoven.GetUpperBound()))
	{
		BSTR xxx;
		pom = Interpret->PoleKnihoven[x].Cesta;

		xxx = pom.AllocSysString();

		*path = xxx;
		SysFreeString(xxx);

		return S_OK;
	}
	else return S_FALSE;

	return S_OK;
}

STDMETHODIMP CInterface::GetComName(int i, int j, BSTR *name)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// TODO: Add your implementation code here

		CString jm;
	int z = Interpret->PoleKnihoven.GetUpperBound();
	if ((i >= 0) && (i <= z))
	{
		if ((j >= 0) && (j <= Interpret->PoleKnihoven[i].ClenPrGetUpB()))
		{
			jm = Interpret->PoleKnihoven[i].ClenPrikazy[j].Nazev;
			jm += '(';
			for (int ParInd = 0; ParInd <= Interpret->PoleKnihoven[i].ClenPrikazy[j].PoleParamLenght(); ParInd++)
			{
				jm += Interpret->PoleKnihoven[i].ClenPrikazy[j].PoleParam[ParInd].Nazev;
				jm += ',';
			}
			if (jm[jm.GetLength() - 1] != '(')
				jm.Delete(jm.GetLength() - 1, 1);
			jm += ')';

			BSTR x;
			x = jm.AllocSysString();

			*name = x;

			SysFreeString(x);
			return S_OK;
		}
		else return S_FALSE;
	}
	else return S_FALSE;


	return S_OK;
}

STDMETHODIMP CInterface::ZpracujPrikaz(BSTR ret, int x, BSTR *outet)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		Interpret->ZpracujPrikaz(ret, x);

	return S_OK;
}

STDMETHODIMP CInterface::GetHistLength(int *length)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// TODO: Add your implementation code here
		*length = Interpret->Zelva->history.GetUpperBound();

	return S_OK;
}

STDMETHODIMP CInterface::GetPrvekData(int x, BSTR *data)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// TODO: Add your implementation code here
		CPrvek *xxx;

	CKrok *krok;
	CRotace *rot;
	CPresun *pre;
	CTurBlok *tur;

	CString ret;
	char z[25];

	xxx = (CPrvek*)Interpret->Zelva->history[x];
	if (xxx->Nazev == "KROK")
	{
		krok = (CKrok*)Interpret->Zelva->history[x];
		ret += "KROK#";
		if (krok->StartPoint) {
			ret += "1";
		}
		else {
			ret += "0";
		}

		//ret += krok->StartPoint;
		ret += "#";

		_gcvt(krok->krok, 10, z);
		ret += z; ret += "#";

		_gcvt(krok->Color[0], 10, z);
		ret += z; ret += "#";

		_gcvt(krok->Color[1], 10, z);
		ret += z; ret += "#";

		_gcvt(krok->Color[2], 10, z);
		ret += z;
	}
	if (xxx->Nazev == "ROTACE")
	{
		rot = (CRotace*)Interpret->Zelva->history[x];
		ret += "ROTACE#"
			;
		_gcvt(rot->angle, 10, z);
		ret += z; ret += "#";

		_gcvt(rot->x, 10, z);
		ret += z; ret += "#";

		_gcvt(rot->y, 10, z);
		ret += z; ret += "#";

		_gcvt(rot->z, 10, z);
		ret += z;
	}
	if (xxx->Nazev == "PRESUN")
	{
		pre = (CPresun*)Interpret->Zelva->history[x];
		ret += "PRESUN#";
		_gcvt(pre->x, 10, z);
		ret += z; ret += "#";

		_gcvt(pre->y, 10, z);
		ret += z; ret += "#";

		_gcvt(pre->z, 10, z);
		ret += z;
	}
	if (xxx->Nazev == "TURTLE")
	{
		tur = (CTurBlok*)Interpret->Zelva->history[x];
		ret += "TURTLE#";
		ret += tur->Value;
	}

	BSTR xx;
	xx = ret.AllocSysString();
	*data = xx;
	SysFreeString(xx);

	return S_OK;
}

//DEL STDMETHODIMP CInterface::GetFilePos(BSTR *Child, BSTR *Parent, int *pos)
//DEL {
//DEL 	AFX_MANAGE_STATE(AfxGetStaticModuleState())
//DEL 
//DEL 	// TODO: Add your implementation code here
//DEL /*	CPrikazy *pom;
//DEL 	int x = 0;
//DEL 	CString xxx = *Parent;
//DEL 	CString xx = *Child;
//DEL 	pom = Interpret->FindPrikaz(xx,&xxx);
//DEL 
//DEL 	if(pom)
//DEL 	x = pom->FilePosition;
//DEL 	pos = &x;*/
//DEL 
//DEL 	return S_OK;
//DEL }
