// Lexer.h: interface for the CLexer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEXER_H__0DB1224B_F518_45AF_9345_7D2C9E73C94A__INCLUDED_)
#define AFX_LEXER_H__0DB1224B_F518_45AF_9345_7D2C9E73C94A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdlib.h>

#include "SymTable.h"

typedef unsigned char uchar;

typedef enum {
    CH_LETTER = 0x01, CH_DIGIT = 0x02, CH_SEPARAT = 0x04,
    CH_SYMBOL = 0x08, CH_QUOTE = 0x10,
    CH_UNKNOWN= 0x7E, CH_FINAL = 0x7F
} hqCharType;

typedef enum {
    TOK_ERROR, TOK_NONE, TOK_FINAL, TOK_INT, TOK_FLOAT, TOK_SYMBOL,
    TOK_NAME, TOK_STRING
} hqTokenType;


class CLexer  
{
public:	
	CLexer():str_(NULL){
	};
	virtual ~CLexer(){
	if(str_)
		free(str_);
	};
	char* GetCurrentPos();
	
	// input params
    int		cssn;	// Comment Start Symbol Number. -1 if none
    char    *ComEnd;	// End of comment
    CSymTable *SymTable;
    hqCharType *CharTypeTable;

    // output params
    char       *Name;
    int		NameLen;
    double	ExtValue;
    int		IntValue;
    hqTokenType PrevTokenType;
    hqCharType	CharType;
    int		NoIntegers;
	int SetParseString(const char *str );
	hqTokenType GetNextToken();
private:
    char *SS, *str_;
};

/* Misc */

void InitCharTypeTable( hqCharType *CharTypeTable, int CharTypes );

extern char const Win1251UpcaseTbl[];




#endif // !defined(AFX_LEXER_H__0DB1224B_F518_45AF_9345_7D2C9E73C94A__INCLUDED_)
