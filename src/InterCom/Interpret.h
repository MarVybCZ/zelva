// Interpret.h: interface for the CInterpret class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTERPRET_H__C8B74035_FB63_4161_B20F_1F25328D04FF__INCLUDED_)
#define AFX_INTERPRET_H__C8B74035_FB63_4161_B20F_1F25328D04FF__INCLUDED_

#include "Turtle.h"	// Added by ClassView
#include "Library.h"
#include "Expression.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CInterpret  
{
protected:	
	FILE *soubor;	

public:
	
/********************************************************************
odstrani soubor z pameti
	lib		: in CString cesta k souboru
	return	: void
********************************************************************/
	void UnLoad(CString lib);	
	
/********************************************************************
Zpracuje vsechny prikazy
	ret		: in CString libovolny retezec
	x		: in int 0 pro zelvi a uzivateli prikazy(z command linu)
			other pro cokoli
	return	: void 
********************************************************************/
	void ZpracujPrikaz(CString ret, int x); //zpracuje prikaz ze souboru (1) nebo z lajny (0)

/********************************************************************
Nahraje soubor do pameti
	File	: in CString cesta souboru	
	return	: void 
********************************************************************/
	void LoadFile(CString File);

	CTurtle *Zelva;
	CInterpret();
	CArray<CLibrary, CLibrary> PoleKnihoven;
	virtual ~CInterpret();	

/********************************************************************
Najde v pameti pozadovany prikaz
	prikaz	: in CString jmeno prikazu
	knihovna: in CString* jmeno knihovny ve ktere prikaz je
	return	: CPrikazy* nalezeny prikaz neuspech vraci NULL
********************************************************************/
	CPrikazy *FindPrikaz(CString prikaz, CString *knihovna);

protected:
/********************************************************************
Vraci chybovou hlasku 
	prik	: in CString prikaz ve kterem nastala chyba
	return	: void 
********************************************************************/
	void Chyba(CString prik);

/********************************************************************
Vyhodnoti matematicky vyraz
	ret		: in CString matematicky vyraz
	PoleParam: in CArray<CParametrs, CParametrs>* pointer na pole 
			parametru na kterych se ma vyraz vyhodnotit
	return	: double hodnota vyrazu neuspech vraci 0
********************************************************************/
	double Evaluate(CString ret,CArray<CParametrs, CParametrs> *PoleParam);

/********************************************************************
Vyhodnoti direktivu IfElse
	vyraz	: in CExpression* podminka pro vyhodnoceni	
	return	: void
********************************************************************/
	void IfElse(CExpression *vyraz);

/********************************************************************
Nastavy novou hodnotu promenne nebo vytvori novou promennou
	vyraz	: in CExpression*	
	return	: void
********************************************************************/
	void Make(CExpression *vyraz);

	int ActualLibrary;//index actualne zpracovavane knihovny
	
/********************************************************************
Prida knihovnu do pole knihoven
	cesta	: in CString cesta k souboru
	return	: bool - true if succesfull, otherwise false
********************************************************************/
	bool AddLibrary(CString cesta);

/********************************************************************
Najde pozadovanou knihovnu
	lib		: in CString* jmeno knihovny
	index	: out int* index hledane knihovny
	return	: CLibrary* pointer na nalezenou knihovnu 
			neuspech vraci NULL
********************************************************************/
	CLibrary * FindLib(CString *lib, int *index);

/********************************************************************
Obsluhuje direktivu turtle .. tend	
	return	: void
********************************************************************/
	void TurtleFnc();

	CPrikazy *ActualCommand;//pointer na aktualne zpracovavany prikaz
	CString ErrMes;

/********************************************************************
Obsluhuje prikaz while(exp)	.. wend
	vyraz	: in CString podminka pro vykonani
	return	: void
********************************************************************/
	void While(CString param);

/********************************************************************
Obsluhuje direktivu Loop(exp) .. lend
	param	: in CString podminka pro vykonani
	return	: void
********************************************************************/
	void Loop(CString param);

/********************************************************************
Obsluhuji vykonavani prikazu 
	vyraz	: in CExpression prikaz ktery se ma vykonat
	return	: bool true kdyz nasel prikaz false kdyz nenasel
********************************************************************/
	bool ForInterpret(CExpression vyraz);
	bool ForTurtle(CExpression vyraz); //obsahuje prikazy a volani pro zelvu
	bool UserCommand(CExpression vyraz); //zjisti a provede uzivatelem definovany prikaz
	
/********************************************************************
Obsluhuje direktivu define prik(param) .. end
Zajistuje definovani uzivatelskych prikazu
	param	: in CString prikaz
	return	: void
********************************************************************/
	void Define(CString param);

/********************************************************************
Nacitaji blok/radek ze souboru
	soub	: in FILE* ukazatel na soubor
	return	: CString vraci blok nebo radek
********************************************************************/
	CString NactiBlok(FILE *soub);
	CString NactiRadek(FILE *soub);
};

#endif // !defined(AFX_INTERPRET_H__C8B74035_FB63_4161_B20F_1F25328D04FF__INCLUDED_)
