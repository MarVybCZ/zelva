// Turtle.cpp: implementation of the CTurtle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Turtle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define pi 3.1415926535



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTurtle::CTurtle()
{
	CKrok *bod;
	bod = new CKrok;

	Pos = false;
	//phistory = &history;
	history.RemoveAll();
	
	bod->krok = 0;
	
	bod->StartPoint = true;	

	Pen = false;
	history.Add((void*)bod);	

	SetColor(1,1,1);
}


CTurtle::~CTurtle()
{
	CPrvek *bod;
	while(history.GetUpperBound()>=0)
	{
		bod = (CPrvek*)history[0];
		history.RemoveAt(0);
		delete bod;
	}
	history.RemoveAll();
}

void CTurtle::Forward(double x)
{
	CKrok *bod;
	bod = new CKrok;

	bod->Color[0] = PenColor[0];
	bod->Color[1] = PenColor[1];
	bod->Color[2] = PenColor[2];

	bod->krok = x;

	if(Pen)
		bod->StartPoint = true;
	else 
		bod->StartPoint = false;

	history.Add((void*)bod);
}

void CTurtle::SetColor(double x, double y, double z)
{
	/*CKrok *Pozice;
	Pozice = HistUpperBound();*/
	//Pozice->Color[0] = 
		PenColor[0] = x;
	//Pozice->Color[1] = 
		PenColor[1] = y;
	//Pozice->Color[2] = 
		PenColor[2] = z;	
}

//DEL void CTurtle::CreateSceneList()
//DEL {/*
//DEL 
//DEL 	GLUquadricObj* obj;
//DEL 	obj = gluNewQuadric();
//DEL 	glDeleteLists(m_sceneList,1);		
//DEL 
//DEL 
//DEL 	
//DEL 	
//DEL 	m_sceneList = glGenLists(1);
//DEL 	PocRot = 0;
//DEL 
//DEL 	glNewList(m_sceneList, GL_COMPILE);		
//DEL 
//DEL 		glPushMatrix();
//DEL 		glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
//DEL 		PocRot = CreateSL(&history);
//DEL 		//yyy = HistUpperBound();
//DEL 		//glLoadMatrixf(matrix);
//DEL 
//DEL 		
//DEL 
//DEL 		glPushMatrix();
//DEL 			glEnable(GL_LIGHTING);
//DEL 			//glTranslatef(yyy->pozice.x, yyy->pozice.y, yyy->pozice.z);
//DEL 			glRotatef(-90,0, 1, 0);
//DEL 			glColor3f(1.0f,1.0f,0.0f);
//DEL 			gluCylinder(obj, 0, 0.10, 0.3, 15, 10);
//DEL 			glDisable(GL_LIGHTING);
//DEL 		glPopMatrix();
//DEL 
//DEL 		/*for(int i=0;i<=PocRot;i++)
//DEL 		{			
//DEL 			glPopMatrix();
//DEL 		//}		
//DEL 	glEndList();		*/
//DEL }

void CTurtle::clear()
{
	CPrvek *bod;
	
	for(int i = history.GetUpperBound();i>=1;i--)
	{
		bod = (CPrvek *)history[i];
		history.RemoveAt(i);
		delete bod;
	}
	Pos= false;
//	glDeleteLists(m_sceneList,1);

/*	celkemLR = 0;
	celkemUD = 0;
	celkemCL = 0;*/
}

//DEL float CTurtle::computeRad(float x)
//DEL {
//DEL 	float pom = 180.000000000000000/x;
//DEL 	float rad = pi/pom;
//DEL 	return rad;
//DEL }

void CTurtle::setposition(double x, double y, double z)
{
	CPresun *pom;
	pom = new CPresun(x,y,z);	
	history.Add((void*)pom);
	Pos = true;
}

void CTurtle::home()
{	
	setposition(0,0,0);
}

//DEL void CTurtle::back()
//DEL {
//DEL 	/*if(phistory->GetUpperBound()>0)
//DEL 	{
//DEL 		CPoint3D pp = phistory->GetAt(phistory->GetUpperBound()-1);		
//DEL 		pp.StartPoint=true;
//DEL 		phistory->Add(pp);		
//DEL 	}*/
//DEL }

void CTurtle::Trans(double angle,double x,double y, double z)
{
	CRotace *bod;
	bod = new CRotace(angle,x,y,z);	
	history.Add((void*)bod);
}

void CTurtle::CL(double angle)
{
//	celkemCL +=angle;
	Trans(angle,1,0,0);
}

void CTurtle::UD(double angle)
{
//	celkemUD +=angle;
	Trans(angle,0,0,1);
}

void CTurtle::LR(double angle)
{
//	celkemLR +=angle;
	Trans(angle,0,1,0);
}

void CTurtle::PenFnc(bool pen)
{
	Pen = pen;
}

//DEL CPrvek *CTurtle::HistUpperBound(int *index)
//DEL {
//DEL 	CPrvek *pom;
//DEL 	int xxx;
//DEL 	
//DEL 	xxx = history.GetUpperBound();
//DEL 
//DEL 	try
//DEL 	{
//DEL 		if(index) *index = xxx;
//DEL 		if(xxx==-1) 
//DEL 		{
//DEL 			pom = new CPrvek;
//DEL 			return pom;
//DEL //			AfxMessageBox(5,MB_OK);
//DEL 		}
//DEL 		pom = (CPrvek*) history.GetAt(xxx);	
//DEL 	}
//DEL 	catch(CException *exp)
//DEL 	{
//DEL 		exp->ReportError(MB_OK,5);
//DEL 	}
//DEL 	return pom;
//DEL }

//DEL int CTurtle::CreateSL(CPtrArray *pole)
//DEL {
//DEL 	//CPoint3D::SPozice *pozice;
//DEL 	
//DEL /*	CPrvek * xxx;
//DEL 	double * mat;
//DEL 
//DEL 	int pocetR = 0;
//DEL 
//DEL 	int pom = pole->GetUpperBound();
//DEL 	
//DEL 	
//DEL 	for(int i=0;i<=pom;i++)
//DEL 	{	
//DEL 		xxx = (CPrvek *)pole->GetAt(i);
//DEL 		
//DEL 		if(xxx->Nazev == "KROK" )
//DEL 		{
//DEL 			CKrok *yyy;
//DEL 			yyy = (CKrok *)pole->GetAt(i);
//DEL 			
//DEL 			if(!yyy->StartPoint)
//DEL 			{
//DEL 				glBegin(GL_LINES);
//DEL 					glColor3f(yyy->Color[0], yyy->Color[1], yyy->Color[2]);
//DEL 					glVertex3f(0, 0, 0);
//DEL 					glVertex3f(yyy->krok, 0, 0);
//DEL 				glEnd();				
//DEL 				glTranslatef(yyy->krok,0,0);
//DEL 			}
//DEL 			
//DEL 			if(yyy->StartPoint)
//DEL 			{				
//DEL 				glTranslatef(yyy->krok,0,0);
//DEL 			}
//DEL 		}
//DEL 
//DEL 		if(xxx->Nazev == "ROTACE")
//DEL 		{
//DEL 			CRotace *yyy;
//DEL 			yyy = (CRotace *)pole->GetAt(i);
//DEL 			glRotatef(yyy->angle, yyy->x, yyy->y, yyy->z);
//DEL 		}		
//DEL 		
//DEL 		if(xxx->Nazev == "PRESUN")
//DEL 		{
//DEL 			CPresun *yyy;
//DEL 			yyy = (CPresun *)pole->GetAt(i);			
//DEL 			//pocetR = 1;
//DEL 			glLoadMatrixf(matrix);			
//DEL 			glTranslatef(yyy->x, yyy->y, yyy->z);			
//DEL 		}
//DEL 		
//DEL 		if(xxx->Nazev == "TURTLE")
//DEL 		{
//DEL 			CTurBlok *yyy;
//DEL 			yyy  = (CTurBlok *)pole->GetAt(i);
//DEL 			if(yyy->Value == "BEGIN" )
//DEL 			{
//DEL 				glPushMatrix();
//DEL 				mat = (double*)malloc(sizeof(double)*16);
//DEL 				///glGetdoublev(GL_MODELVIEW_MATRIX, mat);
//DEL 				MatrixHist.Add((void*) mat);
//DEL 				
//DEL 			}
//DEL 			if(yyy->Value == "END" )
//DEL 			{
//DEL 				mat = (double*)MatrixHist.GetAt(MatrixHist.GetUpperBound());
//DEL 				MatrixHist.RemoveAt(MatrixHist.GetUpperBound());
//DEL 				//glLoadMatrixf(mat);
//DEL 				free((void*)mat);
//DEL 				glPopMatrix();
//DEL 			}
//DEL 		}
//DEL 
//DEL 		/*if(yyy->hist.GetUpperBound()>-1)
//DEL 		{
//DEL 			int ppp = CreateSL(&yyy->hist);
//DEL 			for(int kk=0;kk<ppp;kk++)
//DEL 			{			
//DEL 				glPopMatrix();
//DEL 			}
//DEL 		}//*/
//DEL 	//}	
//DEL ////////////////////////////////////////////////////////////////////////////////////////////////
//DEL 		/*pracuje tak ze udela caru delky krok, a pak se transportuje do pozice (krok,0,0) kdyz rotace tak rotace*/	
//DEL 
//DEL 	return 0;//pocetR;
//DEL }

//DEL CPtrArray *CTurtle::GetHistory()
//DEL {
//DEL 	return &history;
//DEL }
