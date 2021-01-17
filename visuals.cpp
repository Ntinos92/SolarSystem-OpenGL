#include <stdio.h>     // - Just for some ASCII messages
#include <math.h>
#include <fstream>
#include <time.h>
#include "gl/glut.h"   // - An interface and windows management library
#include "visuals.h"   // Header file for our OpenGL functions
model md;
bool animate = true;
static double radius = 30;
static double radius1 = 0;
int tx = 0;
int ty = 0;
float Y = 0.0;
float v = 40.0;

using namespace std;

void Planet1(float Ypsos)
{ 
	
	glPushMatrix();
	glTranslatef(11, -5, -2);
	glRotatef(Ypsos, 0, 0, -250);
	glTranslatef(-350, 0, 0);
	glRotatef(30, 1, 1, 1);


	glPushMatrix();
	
	glColor3f(1, 1, 0);
	DisplayModel(md);
	//glutSolidSphere(30, 100, 100);
	glPopMatrix();

	


	glPopMatrix();
}

void Planet2(float Ypsos)
{



	glPushMatrix();
	glTranslatef(11, -5, -2);
	glRotatef(Ypsos, 0, 0, -200);
	glTranslatef(350, 0, 0);
	glRotatef(30, 1, 1, 1);


	glPushMatrix();

	glColor3f(1, 0, 0);
	//glutSolidSphere(30, 100, 100);
	DisplayModel(md);
	glPopMatrix();


	glPopMatrix();
}

void Planet3(float Ypsos)
{

	glPushMatrix();
	glTranslatef(11, -5, -2);
	glRotatef(Ypsos, 0, 0, -350);
	glTranslatef(350, 0, 0);
	glRotatef(30, 1, 1, 1);


	glPushMatrix();

	glColor3f(0, 0.5, 0.6);
	DisplayModel(md);
	//glutSolidSphere(30, 100, 100);
	glPopMatrix();


	glPopMatrix();
	glFlush();
}

void Planet4(float Ypsos)
{

	glPushMatrix();
	glTranslatef(11, -5, -2);
	glRotatef(Ypsos, 0, 0, -350);
	glTranslatef(350, 0, 0);
	glRotatef(30, 1, 1, 1);


	glPushMatrix();

	glColor3f(0, 1, 0);
	DisplayModel(md);
	//glutSolidSphere(30, 100, 100);
	glPopMatrix();


	glPopMatrix();
	glFlush();
}

void Sun(double rad){

	glPushMatrix();
	
	glPushMatrix();
	glColor4f(1.4, 1.4, 0, 1);
	glutSolidSphere(30, 100, 100);
	glPopMatrix();

	glPushMatrix();
	
	glColor4f(1.5, 1, 0, 0.5);
	glutSolidSphere(rad, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1, 1, 0, 0.2);
	glutSolidSphere(rad + 1.5, 100, 100);
	glPopMatrix();

	glPopMatrix();

}


void stars(double rad)
{
	glPushMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glutSolidSphere(rad, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1, 1, 1, 0.5);
	glutSolidSphere(rad + 1.5, 100, 100);
	glPopMatrix();
	glPopMatrix();

}

void Render()
{
	//CLEARS FRAME BUFFER ie COLOR BUFFER& DEPTH BUFFER (1.0)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clean up the colour of the window
	// and the depth buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(tx, ty, 0);
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		glPushMatrix();
		glTranslatef((rand() % 1400) - 700, (rand() % 1000) - 500, -400);
		stars(radius1);
		glPopMatrix();
	}
	
	glTranslatef(0, 0, -100);

	glPushMatrix();
	glTranslatef(0, 0, -250);
	glScalef(2, 2, 2);
	Sun(radius);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, -1040);
	//glTranslatef(0, 0, -250);
	glScalef(1.005, 1.005, 1.005);
	//glScalef(1.2, 1.2, 1.2);
	Planet1(Y);
	glPopMatrix();
	
	glPushMatrix();
	//glTranslatef(-150, 0, -250);
	//glScalef(0.75, 0.75, 0.75);
	glTranslatef(-150, 0, -1040);
	glScalef(1.0025, 1.0025, 1.0025);
	Planet2(Y);
	glPopMatrix();
	
	glPushMatrix();
	//glTranslatef(0, 0, -250);
	//glScalef(0.5, 0.5, 0.5);
	glTranslatef(0, 0, -1040);
	glScalef(1.0025, 1.0025, 1.0025);
	Planet3(Y);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(0, -100, -250);
	//glScalef(0.5, 0.5, 0.5);
	glTranslatef(0, -150, -1040);
	glScalef(1.0025, 1.0025, 1.0025);
	Planet4(Y);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();             // All drawing commands applied to the 
	// hidden buffer, so now, bring forward
	// the hidden buffer and hide the visible one

}

//-----------------------------------------------------------

void Resize(int w, int h)
{
	// define the visible area of the window ( in pixels )
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);

	// Setup viewing volume

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-400, 400, -400, 400, -500, 500);
	gluPerspective(80.0, (float)w / (float)h, 1.0, 500.0);
}

void Idle()
{
	if (animate){
		if (radius <= 31 && radius >= 30)
		{
			radius += 1;
		}
		else
		{
			radius -= 1;
		}

		if (radius1 <= 1 && radius1 >= 0)
		{
			radius1 += 1;
		}
		else
		{
			radius1 -= 1;
		}

		Y = Y + 2;
	}
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 'q': exit(0);
		break;
	case 'a': tx -= 1;
		break;
	case 'd': tx += 1;
		break;
	case 'w': ty += 1;
		break;
	case 's': ty -= 1;
		break;
	case 'p': animate = !animate;
		break;
	default: break;
	}

	glutPostRedisplay();

}

void Setup()  // TOUCH IT !! 
{
	ReadFile(&md);

	//Parameter handling
	glShadeModel(GL_FLAT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);  //renders a fragment if its z value is less or equal of the stored value
	glClearDepth(1);

	// polygon rendering mode
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	//Set up light source
	GLfloat light_position[] = { 0.0, 30.0, 50.0, 0.0 };
	//GLfloat light_position2[] = { 200.0, 80.0, -350.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
	GLfloat ambientLight[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat diffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specularLight[] = { 1.0, 1.0, 1.0, 1.0 };


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	GLfloat light_position1[] = { 200.0, 80.0, -350.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);

	GLfloat ambientLight1[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat diffuseLight1[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specularLight1[] = { 1.0, 1.0, 1.0, 1.0 };


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight1);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_CULL_FACE);

	glFrontFace(GL_CCW);


	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}


void ReadFile(model *md)
{

	ifstream obj_file("planet.txt"); 

	if (obj_file.fail())
		exit(1);

	obj_file >> md->vertices;
	obj_file >> md->normals;	
	obj_file >> md->faces;

	for (int i = 0; i < md->vertices; i++){ 

		obj_file >> md->obj_points[i].x;
		obj_file >> md->obj_points[i].y;
		obj_file >> md->obj_points[i].z;

	}

	for (int i = 0; i < md->normals; i++){ 

		obj_file >> md->obj_normal[i].x;
		obj_file >> md->obj_normal[i].y;
		obj_file >> md->obj_normal[i].z;

	}
	for (int i = 0; i < md->faces; i++){

		obj_file >> md->obj_faces[i].vtx[0][0];
		obj_file >> md->obj_faces[i].vtx[0][1];
		obj_file >> md->obj_faces[i].vtx[1][0];
		obj_file >> md->obj_faces[i].vtx[1][1];
		obj_file >> md->obj_faces[i].vtx[2][0];
		obj_file >> md->obj_faces[i].vtx[2][1];

	}

	obj_file.close();
}


void DisplayModel(model md)
{

	glPushMatrix();
	glBegin(GL_TRIANGLES);

	for (int i = 0; i < md.faces; i++){

		glVertex3f(md.obj_points[md.obj_faces[i].vtx[0][0] - 1].x, md.obj_points[md.obj_faces[i].vtx[0][0] - 1].y, md.obj_points[md.obj_faces[i].vtx[0][0] - 1].z);
		glVertex3f(md.obj_points[md.obj_faces[i].vtx[1][0] - 1].x, md.obj_points[md.obj_faces[i].vtx[1][0] - 1].y, md.obj_points[md.obj_faces[i].vtx[1][0] - 1].z);
		glVertex3f(md.obj_points[md.obj_faces[i].vtx[2][0] - 1].x, md.obj_points[md.obj_faces[i].vtx[2][0] - 1].y, md.obj_points[md.obj_faces[i].vtx[2][0] - 1].z);
		
	}

	glEnd();
	glPopMatrix();

}
