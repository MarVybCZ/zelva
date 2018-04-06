// Turtle.h: interface for the CTurtle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TURTLE_H__243DA868_584C_467C_853F_8ADF11906656__INCLUDED_)
#define AFX_TURTLE_H__243DA868_584C_467C_853F_8ADF11906656__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "Point3D.h"
//#include "MyTree.h"
#include "TurBlok.h"
#include "Krok.h"
#include "Presun.h"
#include "Rotace.h"

class CTurtle  
{
public:
	bool Pos;//true kdyz byl pouzit prikaz setposition
	
	double PenColor[3];//barva
	
	void PenFnc(bool pen);//obsluhuje pendown penup
	void CL(double angle);//rotace kolem vlastni osy
	void UD(double angle);//rotace nahoru, dolu
	void LR(double angle);//rotace doleva doprava
	void Trans(double angle,double x,double y, double z);//zmena pozice
	void home();//navrat na vychozi pozice
	void setposition(double x, double y, double z);//nastaveni pozice
	void clear();//smazani obrazu
	int m_sceneList;
	void SetColor(double x, double y, double z);//zmena barvy
	void Forward(double x);

	CTurtle();
	virtual ~CTurtle();

	CPtrArray history;
protected:
	
	bool Pen; // true pen up / false pen down
//	int StSpCount;
};

#endif // !defined(AFX_TURTLE_H__243DA868_584C_467C_853F_8ADF11906656__INCLUDED_)
