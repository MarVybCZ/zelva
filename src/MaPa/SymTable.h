// SymTable.h: interface for the CSymTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYMTABLE_H__FA559796_C7C4_41EE_93BC_A9D3FDCDF0DE__INCLUDED_)
#define AFX_SYMTABLE_H__FA559796_C7C4_41EE_93BC_A9D3FDCDF0DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSymTable  
{
public:	
	virtual ~CSymTable();
	public:
	typedef struct {
		char Sym[4];
		char Len;
		char Index;
		char More;
	} SymbolRec;
	

	void PrepareSymbols( char *symbols );
	int FindSymbol( char *str, int *nchars );
protected:
	CSymTable(){};
private:
	SymbolRec* table[256];
};

class CMathSymTable: public CSymTable{
public:
	CMathSymTable();
	virtual ~CMathSymTable(){};


};

#endif // !defined(AFX_SYMTABLE_H__FA559796_C7C4_41EE_93BC_A9D3FDCDF0DE__INCLUDED_)
