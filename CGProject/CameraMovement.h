#pragma once
#include "Renderer.h"

GLfloat eye[] = { 0, 2, -35 };
GLfloat at[] = { 0, 0, 0 };
GLfloat yRot = 0;
int planetNum = 0;
int zMove = 0;
bool pause = true;


bool getPause() {
	return pause;
}

void setPause(bool pause1) {
	pause = pause1;
}

float getXPos(Planets p) {
	return p.getX();
}

float getZPos(Planets p) {
	return p.getZ() + zMove;
}

int getPlanetNum() {
	return planetNum;
}

void keyPress(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		pause = true;
		eye[1] = 0;
		planetNum--;
		if (planetNum <= 0)
			planetNum = 0;
		break;
	case GLUT_KEY_RIGHT:
		pause = true;
		yRot = 0;
		eye[1] = 0;
		planetNum++;
		if (planetNum >= 8)
			planetNum = 8;
		break;
	case GLUT_KEY_UP:
		if (planetNum == 0) {
			pause = true;
			yRot--;
			if (yRot <= -90) {
				yRot = -90;
			}
		}
		break;
	case GLUT_KEY_DOWN:
		if (planetNum == 0) {
			pause = true;
			yRot++;
			if (yRot >= 90) {
				yRot = 90;
			}
		}
		break;
	case GLUT_KEY_SHIFT_R:
		if (!pause)
			pause = true;
		else {
			pause = false;
			planetNum = 0;
			eye[1] = 2;
			yRot = 0;
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
}