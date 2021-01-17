#include <stdio.h>     // - Just for some ASCII messages
#include "visuals.h"   // Header file for our OpenGL functions
#include "gl/glut.h"   // - An interface and windows 

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);


	glutInitWindowSize(1200, 700);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("SolarSystem");

	Setup();

	glutDisplayFunc(Render);
	glutReshapeFunc(Resize);
	glutIdleFunc(Idle);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}
