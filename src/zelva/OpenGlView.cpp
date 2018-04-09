// OpenGlView.cpp : implementation of the COpenGlView class
//

#include "stdafx.h"
#include "OpenGl.h"

#include "OpenGlDoc.h"
#include "OpenGlView.h"
#include "SpecFileDlg.h"
#include "hdibapi.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGlView

IMPLEMENT_DYNCREATE(COpenGlView, CView)

BEGIN_MESSAGE_MAP(COpenGlView, CView)
	ON_MESSAGE(WM_GOODBYE, OnGoodbye)
	//{{AFX_MSG_MAP(COpenGlView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_PRIKAZOVARADKA, OnPrikazovaradka)
	ON_COMMAND(ID_Editor, OnEditor)
	ON_COMMAND(ID_BarPoz, OnBarPoz)
	ON_COMMAND(ID_BarKriz, OnBarKriz)
	ON_COMMAND(ExportEPS, OnExportEPS)
	ON_COMMAND(ExternEps, OnExternEps)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGlView construction/destruction

COpenGlView::COpenGlView()
{
	//history = new CArray<CPoint3D, CPoint3D>;
	// TODO: add construction code here
	m_xPos = m_yPos = 0;
	zoom = -16;
	m_yAngle = -15;
	m_xAngle = 15;

	Interpret = new CMyInter;

	m_pDlg = new CCOMMANDLINE(this, Interpret);
	m_pEditorDlg = new CEditorDialog(NULL, Interpret);
	RGBkriz[0] = 1;
	RGBkriz[1] = 0;
	RGBkriz[2] = 0;

	matrix = (float*)malloc(sizeof(float) * 16);

}

COpenGlView::~COpenGlView()
{
	delete m_pDlg;
	delete m_pEditorDlg;
	delete Interpret;
}

BOOL COpenGlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	// the CREATESTRUCT cs

	//An OpenGL Window must be created with the following flags

	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COpenGlView drawing

void COpenGlView::OnDraw(CDC* pDC)
{
	COpenGlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here


	RenderGl();

	//	RenderDX();

}

void COpenGlView::RenderScene()
{
	glLoadIdentity();
	glTranslatef(m_xPos, m_yPos, zoom);
	glRotatef(m_xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(m_yAngle, 0.0f, 1.0f, 0.0f);


	if (Interpret->GetPosChange())
	{
		CreateSceneList();
	}
	else
		if ((m_pDlg->Change) || (m_pEditorDlg->Change))
		{
			CreateSceneList();
			m_pDlg->Change = false;
			m_pEditorDlg->Change = false;
		}
	glCallList(m_sceneList);
	Kriz();

}


/////////////////////////////////////////////////////////////////////////////
// COpenGlView diagnostics

#ifdef _DEBUG
void COpenGlView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGlDoc* COpenGlView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGlDoc)));
	return (COpenGlDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGlView message handlers

int COpenGlView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here

	InitializeOpenGL();



	return 0;
}

void COpenGlView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here

//First make the RC non-current for this thread by calling wglMakeCurrent and passing 0,0 as its arguments. 

	 //Make the RC non-current
	if (::wglMakeCurrent(0, 0) == FALSE)
	{
		MessageBox("Could not make RC non-current");
	}

	//Then delete the RC by calling wglDeleteContext() which deletes the context who's handle is passed as its argument.

		//Delete the rendering context
	if (::wglDeleteContext(m_hRC) == FALSE)
	{
		MessageBox("Could not delete RC");
	}

	//Then delete the DC and set it to NULL.

		//Delete the DC
	if (m_pDC)
	{
		delete m_pDC;
	}
	//Set it to NULL
	m_pDC = NULL;
	m_pDlg->DestroyWindow();
	m_pEditorDlg->DestroyWindow();


}

BOOL COpenGlView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
		//comment out the original call
		//return CView::OnEraseBkgnd(pDC);
		//Tell Windows not to erase the background
	return TRUE;

}

void COpenGlView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

//Declare a variable to store the aspect ratio i.e the width to height ratio of the Window as the viewing frustum depends on this.

	GLdouble aspect_ratio; // width/height ratio

//Return if the either the width or the height of the Window is 0

	if (0 >= cx || 0 >= cy)
	{
		return;
	}

	//The glViewport function sets the viewport. Compute the aspect ratio, select the projection matrix and clear it. Set the Viewing Volume. This means that all further commands will affect the projection matrix.

		// select the full client area
	::glViewport(0, 0, cx, cy);

	// compute the aspect ratio
	// this will keep all dimension scales equal
	aspect_ratio = (GLdouble)cx / (GLdouble)cy;

	// select the projection matrix and clear it
	::glMatrixMode(GL_PROJECTION);
	::glLoadIdentity();

	// select the viewing volume
	::gluPerspective(45.0f, aspect_ratio, .01f, 200.0f);

	//Select the Modelview matrix and initialize it. This means that all further commands will affect the Modelview matrix.

		// switch back to the modelview matrix and clear it
	::glMatrixMode(GL_MODELVIEW);
	::glLoadIdentity();
}





BOOL COpenGlView::InitializeOpenGL()
{
	//Get a DC for the Client Area
	m_pDC = new CClientDC(this);

	//Failure to Get DC
	if (m_pDC == NULL)
	{
		MessageBox("Error Obtaining DC");
		return FALSE;
	}

	//The function first obtains a DC to the client area and checks to make sure if that is not NULL. 

		//Failure to set the pixel format
	if (!SetupPixelFormat())
	{
		return FALSE;
	}

	//Create Rendering Context
	m_hRC = ::wglCreateContext(m_pDC->GetSafeHdc());

	//Failure to Create Rendering Context
	if (m_hRC == 0)
	{
		MessageBox("Error Creating RC");
		return FALSE;
	}

	//Then, it creates a rendering context from the DC obtained and checks for failure. The wglCreateContext function creates a new OpenGL rendering context, which is suitable for drawing on the device referenced by DC.

		//Make the RC Current
	if (::wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC) == FALSE)
	{
		MessageBox("Error making RC Current");
		return FALSE;
	}

	//Then, it makes the RC created the current. The wglMakeCurrent function makes a specified OpenGL rendering context the calling thread's current rendering context. All subsequent OpenGL calls made by the thread are drawn on the device identified by DC. 

		//Specify Black as the clear color
	::glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//Specify the back of the buffer as clear depth
	::glClearDepth(1.0f);

	//Enable Depth Testing
	::glEnable(GL_DEPTH_TEST);

	SetupLighting();
	CreateSceneList();
	RenderGl();
	return true;

}

BOOL COpenGlView::SetupPixelFormat()
{
	//Pixel Format Structure

	//The capabilities of the OpenGL Window depends on the pixel format selected for the OpenGL rendering Window. The properties of this format include:

	static PIXELFORMATDESCRIPTOR pfd =
	{
		//nSize which specifies the size of the structure. Should be set as below

				sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd

		//nVersion which  specifies the version of the structure

				1,                                                         // version number

		/*dwFlags a set of bit flags that specify the properties of the pixel buffer. It has been set to:

		PFD_DRAW_TO_WINDOW specifies that we want to draw to a window.

		and

		PFD_SUPPORT_OPENGL specifies that we want to use OpenGL

		and

		PFD_DOUBLEBUFFER that specifies that we want double buffering. Double Buffering is a technique where we usually draw to the back buffer and then swap it to the front. It is used for smooth rendering. */


				PFD_DRAW_TO_WINDOW |                // support window
				PFD_SUPPORT_OPENGL |                   // support OpenGL
				PFD_DOUBLEBUFFER,                        // double buffered

		//iPixelType specifies the color type of the pixel data. It has been set to RGBA which means that the pixel color is specified as RGBA values. Thus, each pixel has four separate color components - red, green, blue and alpha.

				PFD_TYPE_RGBA,                               // RGBA type

		//cColorBits specifies the number of color bit planes in each color buffer. For RGBA mode it's the size in bits of the color buffer. It has been set to 24 bit depth, which indicates 8 bits per RGB color.

				24,                                                       // 24-bit color depth

		//The next set of parameters are advanced and may be set to 0 for the current purpose.

				0, 0, 0, 0, 0, 0,                                      // color bits ignored
				0,                                                         // no alpha buffer
				0,                                                         // shift bit ignored
				0,                                                         // no accumulation buffer
				0, 0, 0, 0,                                              // accumulation bits ignored
				16,                                                       // 16-bit z-buffer
				0,                                                         // no stencil buffer
				0,                                                         // no auxiliary buffer
				PFD_MAIN_PLANE,                              // main layer
				0,                                                         // reserved
				0, 0, 0                                                  // layer masks ignored
	};

	//Once the pixel format has been set we try to get the closest pixel format available by calling the ChoosePixelFormat function. The ChoosePixelFormat function attempts to match an appropriate pixel format supported by a device context to a given pixel format specification. We also check to ensure that the index returned is non-zero.

	int m_nPixelFormat = ::ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);

	if (m_nPixelFormat == 0)
	{
		return FALSE;
	}

	//Once we obtain the closest match, we call the SetPixelFormat function which sets the pixel format of the specified device context to the format specified by the index. We also check to ensure that it worked properly.

	if (::SetPixelFormat(m_pDC->GetSafeHdc(), m_nPixelFormat, &pfd) == FALSE)
	{
		return FALSE;
	}

	//If everything has worked properly the function returns true.

	return TRUE;
}


void COpenGlView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_MouseDownPoint = CPoint(0, 0);
	ReleaseCapture();

	CView::OnLButtonUp(nFlags, point);
}

void COpenGlView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_MouseDownPoint = point;
	SetCapture();

	CView::OnLButtonDown(nFlags, point);
}

void COpenGlView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (GetCapture() == this)
	{
		//Increment the object rotation angles
		m_xAngle += ((GLfloat)(point.y - m_MouseDownPoint.y) / (GLfloat)3.6);
		m_yAngle += ((GLfloat)(point.x - m_MouseDownPoint.x) / (GLfloat)3.6);
		//Redraw the view
		InvalidateRect(NULL, FALSE);
		//Set the mouse point
		m_MouseDownPoint = point;
	}

	CView::OnMouseMove(nFlags, point);
}

void COpenGlView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_UP:	m_yPos = m_yPos + 0.1f;
		break;
	case VK_DOWN:    m_yPos = m_yPos - 0.1f;
		break;
	case VK_LEFT:       m_xPos = m_xPos - 0.1f;
		break;
	case VK_RIGHT:     m_xPos = m_xPos + 0.1f;
		break;
	case VK_SUBTRACT:  zoom = zoom - (GLfloat)0.1;
		break;
	case VK_ADD: zoom = zoom + (GLfloat)0.1;
		break;
	default:                   MessageBox("Press the arrow keys only");
		break;
	}

	InvalidateRect(NULL, FALSE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void COpenGlView::SetupLighting()
{
	//Material Properties
	GLfloat matSpecular[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat matShininess[] = { 75.0f };
	GLfloat matAmbient[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	GLfloat matDiffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };



	//Specify the material properties using the values defined using glMaterialfv - where f stands for 'floating point values' and v stands for 'vector'
	/*
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
	*/

	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShininess);
	GLfloat xx[] = { 1.0f,1.0f,1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_COLOR_INDEXES, xx);



	//Enable Lighting - just a call to glEnable. Lighting is off by default for optimization considerations.

	//Lighting Parameters

	//Enable Lighting


	/*Specify the properties of the directional light.
	OpenGL has 8 light sources in this implementation.
	We will set up the light source GL_LIGHT0, the first
	of the 8 light sources OpenGL offers to be used. */

	/*Also, note that the last parameter in case of position
	is 0. This specifies a directional light in OpenGL and
	the positional values specify the direction of the light source.*/

	//Specify a single directional light
	GLfloat ambient1[] = { 0.5f,0.5f,0.5f };
	GLfloat diffuse1[] = { 0.5f,0.5f,0.5f };
	GLfloat specular1[] = { 1.0f,0.0f,0.0f };
	GLfloat position1[] = { 0.0f,0.0f,20,0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular1);
	glLightfv(GL_LIGHT0, GL_POSITION, position1);

	//Enable the directional light.

	//glEnable(GL_LIGHT0);


	/*Specify the properties of the spot light. We will
	set up the light source GL_LIGHT1. Note that the last
	parameter in case of position is 1 - specifying a positional light source.

	One important thing to remember here is that more
	the number of lights, more the lighting calculations
	that would be performed and slower would be our Frame
	Rate. So in case of real-time OpenGL applications or applications
	with animation, make sure that lighting is used very carefully.*/

	/*The spot cutoff parameter specifies the cone of light
	that would be produced by the spot light. We do not see
	much effect in this program because lighting is essentially
	calculated per-vertex and the color is interpolated across
	vertices depending on the type of shading. In this program
	the number of vertices are too low to see the effect of a spot
	light properly. For a good spot light effect we should divide
	the polygons further. Of course this slows down the program a bit. */

	//Specify a single positional spotlight
	GLfloat ambient2[] = { 1.0f,1.5f,0.0f };
	GLfloat diffuse2[] = { 1.0f,2.0f,0.0f };
	GLfloat position2[] = { 1.0f,0.0f,20,1 };
	GLfloat direction2[] = { 0.0f,0.0f,-5.0f };

	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1);

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT1, GL_POSITION, position2);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction2);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 20.0f);



	//Enable the positional light
	glEnable(GL_LIGHT1);
}

void COpenGlView::Kriz()
{
	obj = gluNewQuadric();

	glBegin(GL_LINES);
	glColor3f(RGBkriz[0], RGBkriz[1], RGBkriz[2]);//cerv

	//glVertex3i(0.0f, -15.0f, 0.0f);
	glVertex3i(0, -15, 0);
	//glVertex3f(0.0f, 15.0f, 0.0f);
	glVertex3f(0, 15, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(RGBkriz[0], RGBkriz[1], RGBkriz[2]);
	glVertex3f(-15.0f, 0.0f, 0.0f);
	glVertex3f(15.0f, 0.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(RGBkriz[0], RGBkriz[1], RGBkriz[2]);
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(0.0f, .0f, 10.0f);
	glEnd();
	Cone(180, 1, 0, 0, 0, 10);
	Cone(90, 1, 0, 0, 15, 0);
	Cone(270, 1, 90, 15, 0, 0);
}

void COpenGlView::OnPrikazovaradka()
{
	if (m_pDlg->GetSafeHwnd() == 0)
	{
		m_pDlg->Create();
		m_pDlg->ShowWindow(SW_SHOW);
	}
	else
		m_pDlg->ShowWindow(SW_SHOW);
}

LRESULT COpenGlView::OnGoodbye(WPARAM wParam, LPARAM lParam)
{
	m_pDlg->DestroyWindow();
	m_pEditorDlg->DestroyWindow();
	return 0L;
}


void COpenGlView::Cone(float rx, float ry, float rz, float x, float y, float z)
{
	glEnable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rx, ry, rz, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	gluCylinder(obj, 0, 0.05, 0.1, 40, 20);
	glPopMatrix();
	glDisable(GL_LIGHTING);
}

void COpenGlView::OnEditor()
{
	// TODO: Add your command handler code here
	if (m_pEditorDlg->GetSafeHwnd() == 0)
	{
		m_pEditorDlg->Create();
		m_pEditorDlg->ShowWindow(SW_SHOW);
	}
	else
	{
		m_pEditorDlg->ShowWindow(SW_SHOW);
	}
}

void COpenGlView::OnBarPoz()
{
	// TODO: Add your command handler code here
	CBarvy barvy;
	barvy.DoModal();
	::glClearColor(barvy.m_Red, barvy.m_Green, barvy.m_Blue, 0.0f);
	Invalidate();


}

void COpenGlView::OnBarKriz()
{
	// TODO: Add your command handler code here
	CBarvy barvy;
	barvy.DoModal();
	RGBkriz[0] = barvy.m_Red;
	RGBkriz[1] = barvy.m_Green;
	RGBkriz[2] = barvy.m_Blue;
	Invalidate();
}

//DEL void COpenGlView::InitializeDX()
//DEL {
//DEL /*	if( NULL == ( g_pD3D = Direct3DCreate8( D3D_SDK_VERSION ) ) )
//DEL     return;
//DEL 
//DEL 	if( FAILED( g_pD3D->GetAdapterDisplayMode( D3DADAPTER_DEFAULT, &d3ddm ) ) )
//DEL     return;
//DEL 
//DEL 	ZeroMemory( &d3dpp, sizeof(d3dpp) );
//DEL 	d3dpp.Windowed   = TRUE;
//DEL 	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
//DEL 	d3dpp.BackBufferFormat = d3ddm.Format;
//DEL 	
//DEL 	if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, this->m_hWnd,
//DEL                                   D3DCREATE_SOFTWARE_VERTEXPROCESSING|D3DCREATE_DISABLE_DRIVER_MANAGEMENT,
//DEL                                   &d3dpp, &g_pd3dDevice ) ) )
//DEL 	return;*/
//DEL }

//DEL void COpenGlView::RenderDX()
//DEL {	
//DEL 	g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,0), 1.0f, 0 );
//DEL 
//DEL 	g_pd3dDevice->BeginScene();
//DEL 
//DEL 	// Rendering of scene objects happens here.
//DEL 	CUSTOMVERTEX Vertices[] = 
//DEL 	{
//DEL 		{-5.0, -5.0, 0.0},
//DEL 		{ 0.0,  5.0, 0.0},
//DEL 		{ 5.0, -5.0, 0.0},
//DEL 		{10.0,  5.0, 0.0},
//DEL 		{15.0, -5.0, 0.0},
//DEL 		{20.0,  5.0, 0.0}
//DEL 	};
//DEL 	
//DEL 	
//DEL 	
//DEL 	//
//DEL 	// It is assumed that d3dDevice is a valid
//DEL 	// pointer to a IDirect3DDevice8 interface.
//DEL 	//
//DEL 	g_pd3dDevice->DrawPrimitive( D3DPT_LINELIST, 0, 3 );
//DEL 
//DEL 
//DEL 	// End the scene.
//DEL 	g_pd3dDevice->EndScene();
//DEL 
//DEL 
//DEL 	g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
//DEL 
//DEL 	ValidateRect( NULL );
//DEL 
//DEL }

//DEL void COpenGlView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	
//DEL 	CView::OnPrepareDC(pDC, pInfo);
//DEL //	InitializeDX();
//DEL }

void COpenGlView::RenderGl()
{
	//First clear the buffers

	// Clear out the color & depth buffers
	::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Call the RenderScene function which performs any rendering operation. 
	RenderScene();
	//Flush the rendering pipeline.

	// Tell OpenGL to flush its pipeline
	::glFinish();

	//Swap the contents of the back buffer if double buffering is being used.

	// Now Swap the buffers
	::SwapBuffers(m_pDC->GetSafeHdc());
}

//DEL void COpenGlView::CleanDX()
//DEL {
//DEL     if( g_pd3dDevice != NULL)
//DEL         g_pd3dDevice->Release();
//DEL     if( g_pD3D != NULL)
//DEL         g_pD3D->Release();
//DEL }

void COpenGlView::CreateSceneList()
{
	GLUquadricObj* obj, *obj2;
	obj = gluNewQuadric();
	obj2 = gluNewQuadric();

	glDeleteLists(m_sceneList, 1);

	m_sceneList = glGenLists(1);
	//	PocRot = 0;

	glNewList(m_sceneList, GL_COMPILE);

	glPushMatrix();
	glGetFloatv(GL_MODELVIEW_MATRIX, matrix);

	CreateSL();

	glPushMatrix();

	glRotatef(-90, 0, 1, 0);

	glEnable(GL_LIGHTING);

	gluCylinder(obj, 0, 0.17, 0.5, 10, 7);

	GLfloat xx[] = { 0.0f,0.0f,1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_COLOR_INDEXES, xx);
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, (GLfloat)(-0.2), 0);

	gluDisk(obj2, 0.1, 0.2, 5, 5);
	glPopMatrix();

	glDisable(GL_LIGHTING);

	glPopMatrix();
	glPopMatrix();
	glEndList();

	gluDeleteQuadric(obj);
	gluDeleteQuadric(obj2);
}

void COpenGlView::CreateSL()
{
	CString ret;
	float * mat;

	int pom = Interpret->GetHistLength();

	for (int i = 0; i <= pom; i++)
	{
		ret = Interpret->GetPrvekData(i);

		CString nameRet;

		int ind = 0;
		nameRet = GetData(&ind, ret);

		if (nameRet == "KROK")
		{
			ind++;
			int StartPoint = ret[ind];//char 48 is zero, 49 is 1, but this should be bool and if 1 tthen true 

			ind += 2;
			nameRet = GetData(&ind, ret);
			double krok = atof(nameRet);

			if (StartPoint != 49)
			{
				float Color1;
				float Color2;
				float Color3;

				ind += 1;
				nameRet = GetData(&ind, ret);
				Color1 = (float)atof(nameRet);

				ind += 1;
				nameRet = GetData(&ind, ret);
				Color2 = (float)atof(nameRet);

				ind += 1;
				nameRet = GetData(&ind, ret);
				Color3 = (float)atof(nameRet);

				glBegin(GL_LINES);
				glColor3f(Color1, Color2, Color3);
				glVertex3d(0, 0, 0);
				glVertex3d(krok, 0, 0);
				glEnd();
				glTranslated(krok, 0, 0);
			}

			if (StartPoint == 49)
			{
				glTranslated(krok, 0, 0);
			}
		}

		if (nameRet == "ROTACE")
		{
			ind += 1;
			nameRet = GetData(&ind, ret);
			double angle = atof(nameRet);

			ind += 1;
			nameRet = GetData(&ind, ret);
			double x = atof(nameRet);

			ind += 1;
			nameRet = GetData(&ind, ret);
			double y = atof(nameRet);

			ind += 1;
			nameRet = GetData(&ind, ret);
			double z = atof(nameRet);

			glRotatef((GLfloat)angle, (GLfloat)x, (GLfloat)y, (GLfloat)z);
		}

		if (nameRet == "PRESUN")
		{
			glLoadMatrixf(matrix);

			ind += 1;
			nameRet = GetData(&ind, ret);
			double x = atof(nameRet);

			ind += 1;
			nameRet = GetData(&ind, ret);
			double y = atof(nameRet);

			ind += 1;
			nameRet = GetData(&ind, ret);
			double z = atof(nameRet);

			glTranslated(x, y, z);
		}

		if (nameRet == "TURTLE")
		{
			ind += 1;
			CString Value = GetData(&ind, ret);

			if (Value == "BEGIN")
			{
				glPushMatrix();
				mat = (float*)malloc(sizeof(float) * 16);
				///glGetFloatv(GL_MODELVIEW_MATRIX, mat);
				MatrixHist.Add((void*)mat);

			}
			if (Value == "END")
			{
				mat = (float*)MatrixHist.GetAt(MatrixHist.GetUpperBound());
				MatrixHist.RemoveAt(MatrixHist.GetUpperBound());
				//glLoadMatrixf(mat);
				free((void*)mat);
				glPopMatrix();
			}
		}
	}
}

CString COpenGlView::GetData(int *index, CString in)
{
	CString ret;

	int c;

	c = *index;

	while (in[c] != '#')
	{
		ret.Insert(c, in[c]);
		c++;
		if (c >= in.GetLength())
		{
			*index = c;
			return ret;
		}
	}
	*index = c;
	return ret;
}

//DEL void COpenGlView::OnExportBMP() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL /*	
//DEL 	CRect region;
//DEL 	this->GetUpdateRect(this->GetSafeHwnd(),&region,)
//DEL 	CopyScreenToBitmap(LPRECT lpRect)
//DEL */
//DEL 
//DEL 
//DEL 
//DEL }

void COpenGlView::OnExportEPS()
{
	// TODO: Add your command handler code here
	ShowHideDlg(SW_HIDE);
	int x = 0;
	while (x < 10000)
	{
		x++;
	}
	OnExternEps();
	ShowHideDlg(SW_SHOW);
}

CString COpenGlView::FileDlg()
{
	CString File;
	static char BASED_CODE szFilter[] = "PostScript (*.eps)|*.eps|All Files (*.*)|*.*||";
	CSpecFileDlg dlgFile(FALSE, NULL, "*.eps", OFN_OVERWRITEPROMPT, szFilter);
	int nModal = dlgFile.DoModal();
	if (nModal == IDOK)  File = dlgFile.GetPathName();
	return File;
}

void COpenGlView::ShowHideDlg(UINT x)
{
	if (m_pEditorDlg->GetSafeHwnd() != 0)
	{
		m_pEditorDlg->ShowWindow(x);
	}
	if (m_pDlg->GetSafeHwnd() != 0)
	{
		m_pDlg->ShowWindow(x);
	}
}

void COpenGlView::OnExternEps()
{
	// TODO: Add your command handler code here
	HDIB screen;


	screen = CopyWindowToDIB(this->GetSafeHwnd(), PW_WINDOW);


	//screen = CopyRectToDIB(this->GetSafeHwnd(), &Rect);


	CString filename = FileDlg();

	if (filename.IsEmpty())
	{
		AfxMessageBox("Nebylo zadano jmeno souboru");
		return;
	}

	LPBITMAPINFOHEADER lpBI;

	lpBI = (LPBITMAPINFOHEADER) ::GlobalLock((HGLOBAL)screen);



	CString TextSirka, TextVyska;

	TextSirka.Format("%i", lpBI->biWidth);
	TextVyska.Format("%i", lpBI->biHeight);

	CString Text = "%!PS-Adobe-2.0 EPSF-1.2\n"
		"%%BoundingBox: 0 0 " + TextSirka + " " + TextVyska + "\n"
		"%%Creator: Zelvi grafika - Martin Vybiral\n"
		"%%Title: Zelvi grafika Obrazek\n"
		"%%CreationDate: 0\n"
		"%%EndComments\n"
		"/width " + TextSirka + " def\n"
		"/height " + TextVyska + " def\n"
		"/pixwidth " + TextSirka + " def\n"
		"/pixheight " + TextVyska + " def\n"
		"/picstr width string def\n"
		"/psppic {\n"
		"gsave width height 8\n"
		"[width 0 0 height 0 height neg]\n"
		"{currentfile picstr readhexstring pop}\n"
		"false 3 colorimage grestore } def\n"
		"0 height neg translate pixwidth pixheight scale\n"
		"psppic\n";
	CFile file(filename, CFile::modeCreate | CFile::modeWrite);
	file.Write((LPCTSTR)Text, Text.GetLength());

	char *data;
	data = (char *)lpBI;
	CString Hexa;
	int Sirka = lpBI->biWidth * 3;
	int Sirka2 = lpBI->biSizeImage / lpBI->biHeight;
	int Vyska = lpBI->biHeight;
	int Pom;

	int offset = lpBI->biSize;

	for (int i = 0; i < Vyska; i++)
	{
		Text = "";

		for (int j = 0; j < Sirka; j += 3)
		{
			Pom = offset + i * Sirka2;
			Hexa.Format("%02X%02X%02X", data[Pom + j + 2] & 0x000000FF,
				data[Pom + j + 1] & 0x000000FF,
				data[Pom + j] & 0x000000FF);
			Text += Hexa;
		}
		Text += "\n";
		file.Write((LPCTSTR)Text, Text.GetLength());

	}
	Text = "%%Trailer";
	file.Write((LPCTSTR)Text, Text.GetLength());

	_fcloseall();
}
