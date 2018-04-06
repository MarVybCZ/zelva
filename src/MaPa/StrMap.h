// StrMap.h: interface for the CStrMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRMAP_H__BD1845C8_9792_4B73_BE4A_BC2F30D393A6__INCLUDED_)
#define AFX_STRMAP_H__BD1845C8_9792_4B73_BE4A_BC2F30D393A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStrMap  
{
public:
	CStrMap( int extrabytes=sizeof(double));
	virtual ~CStrMap();
	
public:
	void CreateFromChain( int extrabytes, char *strchain, void *data );
	void AddString(const char *str, void *data);
	void ShrinkMem();
	void Clear();
	void SetCapacity(int NewCapacity );
	int IndexOf(char *str, void **data );
	int Replace( char *str,void *data );
	char* GetString(int index, int *len, void **data );
	void FillFromChain(char *strchain, void *data );
	int IndexOf(char *str, int len, void **data );
	void AddStr(const char *str, int len, void *data );
	int Replace( char *str, int len, void *data );
private:
	void Trim(int NewCount );
	void TrimClear(int NewCount );
	int   FCount, FCapacity;
    int   FExtraLen, FRecordLen;
    char *FList;


};

#endif // !defined(AFX_STRMAP_H__BD1845C8_9792_4B73_BE4A_BC2F30D393A6__INCLUDED_)
