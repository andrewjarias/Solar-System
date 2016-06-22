#include <GL/freeglut.h>
#include <SOIL.h>
#include "Planets.h"
#include "Moons.h"
#include "Sun.h"
#include "Asteroid.h"
#include "Rings.h"
#include "Renderer.h"
#include "CameraMovement.h"

void myinit(void)
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	LoadTextureMap();
}

void myReshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, (GLfloat)w / (GLfloat)h, 0.02, 150.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], 0, 1, 0);	
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Space: The Final Frontier");
	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutSpecialFunc(keyPress);
	glutIdleFunc(play);
	glutMainLoop();
}