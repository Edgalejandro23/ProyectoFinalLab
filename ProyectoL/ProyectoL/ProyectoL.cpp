//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 15.0f, 20.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
CTexture tree;
CTexture edificio;

CTexture piso;
CTexture madera;
CTexture paredE;
CTexture castillo;
CTexture techo;
CTexture caoba;
CTexture tercipelo;
CTexture lampara;
CTexture diamantes;
CTexture diamante;
CTexture marmol;
CTexture paredD;
CTexture paredF;
CTexture rombo;
CTexture cortina;
CTexture florero;
CTexture tele;
CTexture tele1;
CTexture tele2;
CTexture bola;
CTexture bola8;
CTexture puerta;
CTexture zaguan;
CTexture maderaS;



CFiguras cubo;
CFiguras sky;

//END NEW//////////////////////////////////////////


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito
//
CFiguras casa;
CFiguras mesa;
CFiguras flor;
CFiguras sillon;
CFiguras sillas;

//Animacion

float movp;
float movPuerta;
float movCor;

void ciudad ()
{

		glPushMatrix(); //Camino1
			glTranslatef(23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Camino2
			glTranslatef(-23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,-4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,4.0);
			glScalef(87,0.1,1);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,7.0);
			glRotatef(90,1,0,0);
			glRotatef(180,0,0,1);
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(piso.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,-7.0);
			glRotatef(90,1,0,0);
			//glRotatef(180,0,0,1);
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text6.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();
}

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	edificio.LoadTGA("edificio.tga");
	edificio.BuildGLTexture();
	edificio.ReleaseImage();

	piso.LoadTGA("Piso.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();

	madera.LoadTGA("madera.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	paredE.LoadTGA("paredE2.tga");
	paredE.BuildGLTexture();
	paredE.ReleaseImage();

	castillo.LoadTGA("castillo.tga");
	castillo.BuildGLTexture();
	castillo.ReleaseImage();

	techo.LoadTGA("techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	caoba.LoadTGA("caoba.tga");
	caoba.BuildGLTexture();
	caoba.ReleaseImage();

	tercipelo.LoadTGA("terciopelo1.tga");
	tercipelo.BuildGLTexture();
	tercipelo.ReleaseImage();

	lampara.LoadTGA("lampara1.tga");
	lampara.BuildGLTexture();
	lampara.ReleaseImage();

	diamantes.LoadTGA("diamantes.tga");
	diamantes.BuildGLTexture();
	diamantes.ReleaseImage();

	diamante.LoadTGA("diamante.tga");
	diamante.BuildGLTexture();
	diamante.ReleaseImage();

	marmol.LoadTGA("marmol.tga");
	marmol.BuildGLTexture();
	marmol.ReleaseImage();

	paredD.LoadTGA("paredD.tga");
	paredD.BuildGLTexture();
	paredD.ReleaseImage();

	paredF.LoadTGA("paredF.tga");
	paredF.BuildGLTexture();
	paredF.ReleaseImage();

	rombo.LoadTGA("rombo1.tga");
	rombo.BuildGLTexture();
	rombo.ReleaseImage();

	florero.LoadTGA("florero.tga");
	florero.BuildGLTexture();
	florero.ReleaseImage();

	cortina.LoadTGA("cortinaa.tga");
	cortina.BuildGLTexture();
	cortina.ReleaseImage();

	tele.LoadTGA("tele.tga");
	tele.BuildGLTexture();
	tele.ReleaseImage();

	tele1.LoadTGA("tele1.tga");
	tele1.BuildGLTexture();
	tele1.ReleaseImage();

	tele2.LoadTGA("tele2.tga");
	tele2.BuildGLTexture();
	tele2.ReleaseImage();

	bola.LoadTGA("bola1.tga");
	bola.BuildGLTexture();
	bola.ReleaseImage();

	bola8.LoadTGA("bola8.tga");
	bola8.BuildGLTexture();
	bola8.ReleaseImage();

	puerta.LoadTGA("puerta3.tga");
	puerta.BuildGLTexture();
	puerta.ReleaseImage();

	zaguan.LoadTGA("zaguan.tga");
	zaguan.BuildGLTexture();
	zaguan.ReleaseImage();

	maderaS.LoadTGA("maderaS.tga");
	maderaS.BuildGLTexture();
	maderaS.ReleaseImage();

	



	








	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
				glEnable ( GL_COLOR_MATERIAL );
					glColor3f(1, 1, 1);
					glCallList(ciudad_display_list);
				glDisable ( GL_COLOR_MATERIAL );
			glPopMatrix();
			
			glPushMatrix(); //Flecha
				glScalef(7,0.1,7);
				glDisable(GL_LIGHTING);
				fig3.prisma2(text4.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			//***********************************CASA********************************************
		

			glPushMatrix();//ParedTrasera
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(24.0, 5.5, -35.0);
				glRotatef(90, 1, 0, 0);
				glScalef(35.0, 1.0, 11.0);
				glDisable(GL_LIGHTING);
				casa.prisma2(paredF.GLindex, paredE.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			
			glPushMatrix();//ParedI
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(6.0, 5.5, -20.5);
				glRotatef(-90, 0, 0, 1);
				glScalef(11, 1.0, 30.0);
				glDisable(GL_LIGHTING);
				casa.prisma2(paredF.GLindex,paredE.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//ParedD
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(42.0, 5.5, -20.5);
				glRotatef(90, 0, 0, 1);
				glScalef(11.0, 1.0, 30.0);
				glDisable(GL_LIGHTING);
				casa.prisma2(paredD.GLindex, paredE.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			
			glPushMatrix();//Piso de cuarto
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(24.0, 0.0, -19.5);
				glScalef(35.0, 0.0, 30.0);
				glDisable(GL_LIGHTING);
				casa.prisma2(piso.GLindex,10); 
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Techo
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(24.0, 10.5, -20.0);
				glScalef(35.0, 1.0, 29.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1,1,1,techo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//CastilloI
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(25.0, 4.0, -25);
				glScalef(2.0, 8.0, 2.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1,1,1,castillo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Columna
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(16.25, 9.0, -25);
				glScalef(19.5, 2.0, 2.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, castillo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//ColumnaI
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(7.5, 4.0, -25);
				glScalef(2.0, 8.0, 2.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, castillo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//ColumnaC
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(27, 9.0, -20);
				glScalef(2.0, 2.0, 12.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, castillo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//ColumnaAD
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(35.0, 9.0, -15);
				glScalef(14.0, 2.0, 2.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, castillo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//CastilloD
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(40.5, 4.0, -15);
				glScalef(2.0, 8.0, 2.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, castillo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix();//Castillo Central Derecho
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(27.0, 4.0, -24);
			glScalef(2.0, 8.0, 4.0);
			glDisable(GL_LIGHTING);
			casa.prisma(1, 1, 1, castillo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			//***********************************barra ********************************************

			glPushMatrix();//Barra Izq
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(26.8, 1.5, -18.6);
				glScalef(0.5, 3.0, 6.7);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, madera.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//BarraM Izq
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(26.8, 3.25, -18.0);
				glScalef(2.0, 0.5, 8.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, marmol.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Barra Der
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(33.0, 1.5, -15);
				glScalef(13.0, 3.0, 0.5);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, madera.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Barra M Der
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(33.65, 3.25, -15);
				glScalef(11.7, 0.5, 2.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, marmol.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			


		//**********************************FIN barra*********************************************

			
		//***********************************MESA ********************************************
			glPushMatrix();
				glTranslatef(1.0, 0.0, 0.0);
			glPushMatrix();//PatasDS
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(11.0, 1, -18);
				glScalef(0.5, 1.5, 0.5);
				glDisable(GL_LIGHTING);
				mesa.prisma(1, 1, 1, madera.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//PatasIS
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(16.0, 1, -18);
				glScalef(0.5, 1.5, 0.5);
				glDisable(GL_LIGHTING);
				mesa.prisma(1, 1, 1, madera.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//PatasDInf
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(16.0, 1, -10);
				glScalef(0.5, 1.5, 0.5);
				glDisable(GL_LIGHTING);
				mesa.prisma(1, 1, 1, madera.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//PatasIInf
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(11.0, 1, -10);
				glScalef(0.5, 1.5, 0.5);
				glDisable(GL_LIGHTING);
				mesa.prisma(1, 1, 1, madera.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//soporteInf
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(13.5, 1.9, -9.7);
				glScalef(6.5, 0.35, 0.5);
				glDisable(GL_LIGHTING);
				mesa.prisma2(diamante.GLindex, madera.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//soporteSup
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(13.5, 1.9, -18.3);
				glScalef(6.5, 0.35, 0.5);
				glDisable(GL_LIGHTING);
				mesa.prisma2(diamante.GLindex, madera.GLindex);
				glEnable(GL_LIGHTING);

			glPopMatrix();
				glPushMatrix();//soporteLadoI
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(10.5, 1.9, -14.0);
				glScalef(0.5, 0.35, 8.1);
				glDisable(GL_LIGHTING);
				mesa.prisma2(diamantes.GLindex, madera.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//soporteLadoD
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(16.5, 1.9, -14.0);
			glScalef(0.5, 0.35, 8.1);
			glDisable(GL_LIGHTING);
			mesa.prisma2(diamantes.GLindex, madera.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Centro
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(13.5, 1.85, -14.0);
				glScalef(5.5, 0.2, 8.1);
				glDisable(GL_LIGHTING);
				mesa.prisma2(tercipelo.GLindex, madera.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//BOLA Roja
				glColor3f(1.0, 0.0, 0.0);
				glTranslatef(12.5, 2.1, -12.0);
				glScalef(0.2, 0.2, 0.2);
				glDisable(GL_LIGHTING);
				glutSolidSphere(0.5,20,20);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//BOLA 
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(13.5, 2.1, -14.0);
				glRotatef(90, 0, 1, 0);
				glScalef(0.2, 0.2, 0.2);
				glDisable(GL_LIGHTING);
				mesa.esfera(0.5,20,20,bola.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//BOLA ocho
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(14.5, 2.1, -15.0);
				glScalef(0.2, 0.2, 0.2);
				glDisable(GL_LIGHTING);
				mesa.esfera(0.5, 20, 20, bola8.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();


		glPopMatrix();

			//**********************************FIN MESA*********************************************


			//***********************************Florero ********************************************
		
		
		glPushMatrix();//Base
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(29.0, 3.5, -15.0);
			glScalef(0.5, 0.7, 0.5);
			glDisable(GL_LIGHTING);
			flor.cilindro(0.5, 1.0, 20, florero.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();


			//**********************************FIN Florero*********************************************


			//***********************************Fachada ********************************************
		glPushMatrix();//pared1
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(6.5, 5.5, -5.0);
			glRotatef(-90, 1, 0, 0);
			glScalef(2.0, 1.0, 11.0);
			glDisable(GL_LIGHTING);
			casa.prisma2(paredF.GLindex, paredE.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//pared2
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(18.0, 5.5, -5.0);
			glRotatef(-90, 1, 0, 0);
			glScalef(2.0, 1.0, 11.0);
			glDisable(GL_LIGHTING);
			casa.prisma2(paredF.GLindex, paredE.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//pared3
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(38.5, 5.5, -5.0);
			glRotatef(-90, 1, 0, 0);
			glScalef(8.0, 1.0, 11.0);
			glDisable(GL_LIGHTING);
			casa.prisma2(paredF.GLindex, paredE.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//Columna1
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(12.25, 10.0, -5.0);
			glRotatef(-90, 1, 0, 0);
			glScalef(9.55, 1.0, 2.0);
			glDisable(GL_LIGHTING);
			casa.prisma2(paredF.GLindex, paredE.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
			
			////glPushMatrix();//cortina
			////	glColor3f(1.0, 1.0, 1.0);
			////	glTranslatef(12.25, 4.5, -4.8);
			////	glScalef(9.5, 9.0, 0.2);
			////	glDisable(GL_LIGHTING);
			////	casa.prisma(1, 1, 1, cortina.GLindex);
			////	glEnable(GL_LIGHTING);
			////glPopMatrix();

		glPushMatrix();
			glTranslatef(00.0, 10.0, -0.8);
			glPushMatrix();
			glTranslatef(12.25, 0.0, -4.8);
			glScalef(9.5, 0.1, 0.1);
			casa.prisma(1, 1, 1, NULL);//A
				glPopMatrix();
				glTranslatef(12.0, -2, -4.0); //Pivote
			glRotatef(movCor, -1.0, 0.0, 0.0);
			glTranslatef(0.25, -3.5, 0.0);
			glPushMatrix();
			glScalef(9.5, 9.0, 0.2);
			glDisable(GL_LIGHTING);
			casa.prisma(1, 1, 1, cortina.GLindex);//B
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPopMatrix();
	
			glPushMatrix();//Columna Zaguan
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(26.75, 10.5, -5.0);
				glScalef(15.5, 1.0, 1.0);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, paredE.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Transparencia zaguan
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(23.0, 9.0, -5.0);
				glScalef(8.0, 2.0, 1.0);
				glDisable(GL_LIGHTING);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
				casa.prisma(1, 1, 1, rombo.GLindex);
				glEnable(GL_LIGHTING);
				glDisable(GL_ALPHA_TEST);
			glPopMatrix();

			glPushMatrix();//Transparencia zaguan
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(30.5, 9.0, -5.0);
				glScalef(8.0, 2.0, 1.0);
				glDisable(GL_LIGHTING);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
				casa.prisma(1, 1, 1, rombo.GLindex);
				glEnable(GL_LIGHTING);
				glDisable(GL_ALPHA_TEST);
			glPopMatrix();

	

			glPushMatrix();
				glTranslatef(30.0, 4.0, -4.8);
			glPushMatrix();
			glScalef(0.1, 8.0, 0.5);
			casa.prisma(1, 1, 1, NULL);//A
			glPopMatrix();
			glTranslatef(1.0, 0.0, 0.0);   //Pivote
			glRotatef(movPuerta, 0.0, 1.0, 0.0);
			glTranslatef(1.25, 0.0, 0.0);
			glPushMatrix();
			glScalef(4.5, 8.0, 0.2);
			glDisable(GL_LIGHTING);
			casa.prisma(1, 1, 1, puerta.GLindex);//B
			glEnable(GL_LIGHTING);
			glPopMatrix();

		glPopMatrix();

			glPushMatrix();//Zaguan
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(24.5, 4.0, -4.6);
				glScalef(11.0, 8.0, 0.2);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, zaguan.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			//**********************************FIN Fachada*********************************************






		//***********************************Sillas ********************************************
			glPushMatrix();//silla1
				glTranslatef(25.0, 0.0, -20.0);
			glPushMatrix();//Patas
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(0.0, 1.5, 0.0);
				glScalef(0.15, 4.0, 0.15);
				glDisable(GL_LIGHTING);
				casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Base
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(0.5, 2.525, -0.5);
				glScalef(1.3, 0.15, 2.3);
				glDisable(GL_LIGHTING);
				casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//asiento
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(0.5, 2.6, -0.5);
				glScalef(1.3, 0.15, 2.3);
				glDisable(GL_LIGHTING);
				casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo blanco
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(-0.156, 2.9, -0.5);
				glScalef(0.1, 1.5, 0.8);
				glDisable(GL_LIGHTING);
				casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo con negro
				glColor3f(1.0, 1.0, 1.0);
				glTranslatef(-0.1, 3.25, -0.5);
				glRotatef(270, 0, 0, 1);
				glScalef(0.6, 0.1, 1.0);
				glDisable(GL_LIGHTING);
				casa.prisma2(tercipelo.GLindex, maderaS.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();


			glPushMatrix();//silla2
			glTranslatef(25.0, 0.0, -18.0);
			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, 0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Base
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.525, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//asiento
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.6, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo blanco
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.156, 2.9, -0.5);
			glScalef(0.1, 1.5, 0.8);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo con negro
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.1, 3.25, -0.5);
			glRotatef(270, 0, 0, 1);
			glScalef(0.6, 0.1, 1.0);
			glDisable(GL_LIGHTING);
			casa.prisma2(tercipelo.GLindex, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();


				glPushMatrix();//silla3
			glTranslatef(25.0, 0.0, -16.0);
			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, 0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Base
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.525, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//asiento
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.6, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo blanco
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.156, 2.9, -0.5);
			glScalef(0.1, 1.5, 0.8);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo con negro
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.1, 3.25, -0.5);
			glRotatef(270, 0, 0, 1);
			glScalef(0.6, 0.1, 1.0);
			glDisable(GL_LIGHTING);
			casa.prisma2(tercipelo.GLindex, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();


			glPushMatrix();//silla4
				glTranslatef(30.0, 0.0, -13.0);
				glRotatef(90, 0, 1, 0);
			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, 0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Base
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.525, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//asiento
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.6, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo blanco
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.156, 2.9, -0.5);
			glScalef(0.1, 1.5, 0.8);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo con negro
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.1, 3.25, -0.5);
			glRotatef(270, 0, 0, 1);
			glScalef(0.6, 0.1, 1.0);
			glDisable(GL_LIGHTING);
			casa.prisma2(tercipelo.GLindex, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();

			glPushMatrix();//silla5
			glTranslatef(33.0, 0.0, -13.0);
			glRotatef(90, 0, 1, 0);
			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, 0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Base
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.525, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//asiento
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.6, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo blanco
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.156, 2.9, -0.5);
			glScalef(0.1, 1.5, 0.8);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo con negro
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.1, 3.25, -0.5);
			glRotatef(270, 0, 0, 1);
			glScalef(0.6, 0.1, 1.0);
			glDisable(GL_LIGHTING);
			casa.prisma2(tercipelo.GLindex, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();

			glPushMatrix();//silla6
			glTranslatef(36.0, 0.0, -13.0);
			glRotatef(90, 0, 1, 0);
			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, 0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -1.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Patas
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.0, 1.5, -0.0);
			glScalef(0.15, 4.0, 0.15);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Base
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.525, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//asiento
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.5, 2.6, -0.5);
			glScalef(1.3, 0.15, 2.3);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo blanco
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.156, 2.9, -0.5);
			glScalef(0.1, 1.5, 0.8);
			glDisable(GL_LIGHTING);
			casa.prisma(0.5, 1.0, 0.5, tercipelo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo con negro
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.1, 3.25, -0.5);
			glRotatef(270, 0, 0, 1);
			glScalef(0.6, 0.1, 1.0);
			glDisable(GL_LIGHTING);
			casa.prisma2(tercipelo.GLindex, maderaS.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();








			



		//**********************************FIN Sillas*********************************************






		//***********************************Sillon ********************************************
			glPushMatrix();
			glTranslatef(14,-0.5,-25);
			glScalef(1.2, 1.2, 1.2);
			glPushMatrix();//Base
				glColor3f(0.9, 0.0, 0.0);
				glTranslatef(0.0, 1.0, -0.0);
				glScalef(1.5, 0.9, 0.9);
				glDisable(GL_LIGHTING);
				casa.prisma(1, 1, 1, NULL);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Descansos
				glColor3f(1.0, 0.0, 0.0);
				glTranslatef(-0.6, 1.7, -0.3);
				glRotatef(90,1,0,0);
				glScalef(1.4, 3.9, 1.4);
				glDisable(GL_LIGHTING);
				casa.cilindro(0.2, 0.2, 20, NULL);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Descansos
				glColor3f(1.0, 0.0, 0.0);
				glTranslatef(0.6, 1.7, -0.3);
				glRotatef(90, 1, 0, 0);
				glScalef(1.4, 3.9, 1.4);
				glDisable(GL_LIGHTING);
				casa.cilindro(0.2, 0.2, 20, NULL);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo
			glColor3f(0.9, 0.0, 0.0);
			glTranslatef(0.0, 1.7, -0.5);
			glRotatef(90, 1, 0, 0);
			glScalef(4.1, 0.8, 4.2);
			glDisable(GL_LIGHTING);
			casa.cilindro(0.2, 0.2, 20, NULL);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();

			glPushMatrix();
			glTranslatef(19, -0.5, -25);
			glScalef(1.2, 1.2, 1.2);
			glPushMatrix();//Base
			glColor3f(0.9, 0.0, 0.0);
			glTranslatef(0.0, 1.0, -0.0);
			glScalef(1.5, 0.9, 0.9);
			glDisable(GL_LIGHTING);
			casa.prisma(1, 1, 1, NULL);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Descansos
			glColor3f(1.0, 0.0, 0.0);
			glTranslatef(-0.6, 1.7, -0.3);
			glRotatef(90, 1, 0, 0);
			glScalef(1.4, 3.9, 1.4);
			glDisable(GL_LIGHTING);
			casa.cilindro(0.2, 0.2, 20, NULL);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Descansos
			glColor3f(1.0, 0.0, 0.0);
			glTranslatef(0.6, 1.7, -0.3);
			glRotatef(90, 1, 0, 0);
			glScalef(1.4, 3.9, 1.4);
			glDisable(GL_LIGHTING);
			casa.cilindro(0.2, 0.2, 20, NULL);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//Respaldo
			glColor3f(0.9, 0.0, 0.0);
			glTranslatef(0.0, 1.7, -0.5);
			glRotatef(90, 1, 0, 0);
			glScalef(4.1, 0.8, 4.2);
			glDisable(GL_LIGHTING);
			casa.cilindro(0.2, 0.2, 20, NULL);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();

			//**********************************FIN Sillones*********************************************







			//***********************************Lamparas ********************************************
		glPushMatrix();//1
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(14.5, 8.5, -17.0);
			glScalef(0.7, 1.0, 0.3);
			glDisable(GL_LIGHTING);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			mesa.prisma(1, 1, 1, lampara.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();
		glPushMatrix();//1
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(14.5, 9.5, -17.0);
			glScalef(0.1, 1.0, 0.1);
			glDisable(GL_LIGHTING);
			mesa.prisma(1, 1, 1, castillo.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//2
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(14.5, 8.5, -16.5);
			glScalef(0.7, 1.0, 0.3);
			glDisable(GL_LIGHTING);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			mesa.prisma(1, 1, 1, lampara.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();
			glPushMatrix();//2
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(14.5, 9.5, -16.5);
			glScalef(0.1, 1.0, 0.1);
			glDisable(GL_LIGHTING);
			mesa.prisma(1, 1, 1, castillo.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//3
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(14.5, 8.5, -16.0);
			glScalef(0.7, 1.0, 0.3);
			glDisable(GL_LIGHTING);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			mesa.prisma(1, 1, 1, lampara.GLindex);
			glEnable(GL_LIGHTING);
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();
			glPushMatrix();//3
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(14.5, 9.5, -16.0);
			glScalef(0.1, 1.0, 0.1);
			glDisable(GL_LIGHTING);
			mesa.prisma(1, 1, 1, castillo.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//4
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(14.5, 8.5, -12.0);
		glScalef(0.7, 1.0, 0.3);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		mesa.prisma(1, 1, 1, lampara.GLindex);
		glEnable(GL_LIGHTING);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix();
		glPushMatrix();//4
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(14.5, 9.5, -12.0);
		glScalef(0.1, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		mesa.prisma(1, 1, 1, castillo.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		

		glPushMatrix();//5
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(14.5, 8.5, -11.5);
		glScalef(0.7, 1.0, 0.3);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		mesa.prisma(1, 1, 1, lampara.GLindex);
		glEnable(GL_LIGHTING);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix();
		glPushMatrix();//5
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(14.5, 9.5, -11.5);
		glScalef(0.1, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		mesa.prisma(1, 1, 1, castillo.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//6
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(14.5, 8.5, -11.0);
		glScalef(0.7, 1.0, 0.3);
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		mesa.prisma(1, 1, 1, lampara.GLindex);
		glEnable(GL_LIGHTING);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPushMatrix();//6
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(14.5, 9.5, -11.0);
		glScalef(0.1, 1.0, 0.1);
		glDisable(GL_LIGHTING);
		mesa.prisma(1, 1, 1, castillo.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


			//**********************************FIN Lamparas*********************************************








		//**********************************Television*********************************************
		glPushMatrix();
		glTranslatef(41.5, 3.0, -20.5);
		glRotatef(-90, 0, 1, 0);
		glPushMatrix();//1
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.0, 0.0);
			glScalef(6.0, 0.3, 0.3);
			glDisable(GL_LIGHTING);
			mesa.prisma(0.5, 0.5, 0.5, tele.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//1
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 3.0, 0.0);
			glScalef(6.0, 0.3, 0.3);
			glDisable(GL_LIGHTING);
			mesa.prisma(0.5, 0.5, 0.5, tele.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//2
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.56, 2.0, 0.0);
			glScalef(0.3, 4.3, 0.3);
			glDisable(GL_LIGHTING);
			mesa.prisma(0.5, 0.5, 0.5, tele.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//2
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-1.56, 2.0, 0.0);
			glScalef(0.3, 4.3, 0.3);
			glDisable(GL_LIGHTING);
			mesa.prisma(0.5, 0.5, 0.5, tele.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//Pantalla
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 2.0, 0.0);
			glScalef(3.0, 1.9, 0.1);
			glRotatef(90, 1, 0, 0);
			glDisable(GL_LIGHTING);
			mesa.prisma2(tele1.GLindex, tele.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPopMatrix();

			//**********************************Television 2*********************************************
		glPushMatrix();
			glTranslatef(17.0, 1.0, -34.3);
			glScalef(2.0, 2.0, 1.0);
			glPushMatrix();//1
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 1.0, 0.0);
			glScalef(6.0, 0.3, 0.3);
			glDisable(GL_LIGHTING);
			mesa.prisma(0.5, 0.5, 0.5, tele.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//1
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 3.0, 0.0);
			glScalef(6.0, 0.3, 0.3);
			glDisable(GL_LIGHTING);
			mesa.prisma(0.5, 0.5, 0.5, tele.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//2
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.56, 2.0, 0.0);
			glScalef(0.3, 4.3, 0.3);
			glDisable(GL_LIGHTING);
			mesa.prisma(0.5, 0.5, 0.5, tele.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//2
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-1.56, 2.0, 0.0);
			glScalef(0.3, 4.3, 0.3);
			glDisable(GL_LIGHTING);
			mesa.prisma(0.5, 0.5, 0.5, tele.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//Pantalla
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0, 2.0, 0.0);
		glScalef(3.0, 1.9, 0.1);
		glRotatef(90, 1, 0, 0);
		glDisable(GL_LIGHTING);
		fig3.prisma_anun(tele2.GLindex, 0);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPopMatrix();
		//**********************************FIN Television 2*********************************************
			







	glPopMatrix();

	glutSwapBuffers ( );

}


void animacion()
{
	
		fig3.text_izq-= 0.001;
		fig3.text_der-= 0.001;
		if(fig3.text_izq<-1)
			fig3.text_izq=0;
		if(fig3.text_der<0)
			fig3.text_der=1;

		movp += 0.01;


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 't':
			if (45.0 > movPuerta)
				movPuerta += 2.5;
			break;
		case 'T':
			if (0.0 < movPuerta)
				movPuerta -= 2.5;

		case 'y':
			if (60.0 > movCor)
				movCor += 2.5;
			break;
		case 'Y':
			if (0.0 < movCor)
				movCor -= 2.5;

	
			
			
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Final"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
