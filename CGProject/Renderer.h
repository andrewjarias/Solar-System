#pragma once
#include "CameraMovement.h"
#include <iostream>
using namespace std;

int hours = 0;
int days = 0;
int years = 0;
GLuint s, m1, v, e, m2, j, st, u, n, a, moon, sta, satRi, jupRi, uraRi;
unsigned char *earthImage, *sunImage, *merImage, *venImage, *marImage, *jupImage, *satImage, *uraImage, *nepImage, *moonImage, *asteroidImage, *starImage, *satRingImage, *jupRingImage, *uraRingImage;
GLUquadric *su, *me, *ve, *ea, *ma, *ju, *sa, *ur, *ne, *mo, *ast, *satR, *jupR, *uraR, *star = gluNewQuadric();
Planets mercury(me), venus(ve), earth(ea), mars(ma), jupiter(ju), saturn(sa), uranus(ur), neptune(ne);
Moon earthMoon(mo);
Rings satRing(satR), jupRing(jupR), uraRing(uraR);
Sun sun(su);
Asteroid asteroid(ast);
GLfloat lightnone[] = { 0.05, 0.05, 0.05, 1.0 };

void getPlanetPos() {
	if (planetNum == 0) {
		eye[0] = 0;
		at[0] = 0;
		eye[2] = -35;
		at[2] = 0;
	}
	else if (planetNum == 1) {
		eye[0] = getXPos(mercury);
		at[0] = getXPos(mercury);
		eye[2] = getZPos(mercury) - .3;
		at[2] = getZPos(mercury);
	}
	else if (planetNum == 2) {
		eye[0] = getXPos(venus);
		at[0] = getXPos(venus);
		eye[2] = getZPos(venus) - .4;
		at[2] = getZPos(venus);
	}
	else if (planetNum == 3) {
		eye[0] = getXPos(earth);
		at[0] = getXPos(earth);
		eye[2] = getZPos(earth) - .4;
		at[2] = getZPos(earth);
	}
	else if (planetNum == 4) {
		eye[0] = getXPos(mars);
		at[0] = getXPos(mars);
		eye[1] = 0;
		at[1] = 0;
		eye[2] = getZPos(mars) - .3;
		at[2] = getZPos(mars);
	}
	else if (planetNum == 5) {
		eye[0] = getXPos(jupiter);
		at[0] = getXPos(jupiter);
		eye[1] = .1;
		at[1] = .1;
		eye[2] = getZPos(jupiter) - 2.0;
		at[2] = getZPos(jupiter);
	}
	else if (planetNum == 6) {
		eye[0] = getXPos(saturn);
		at[0] = getXPos(saturn);
		eye[1] = .1;
		at[1] = .1;
		eye[2] = getZPos(saturn) - 2.0;
		at[2] = getZPos(saturn);
	}
	else if (planetNum == 7) {
		eye[0] = getXPos(uranus) + .1;
		at[0] = getXPos(uranus);
		eye[1] = 0;
		at[1] = 0;
		eye[2] = getZPos(uranus) - 1.1;
		at[2] = getZPos(uranus);
	}
	else if (planetNum == 8) {
		eye[0] = getXPos(neptune);
		at[0] = getXPos(neptune);
		eye[1] = .1;
		at[1] = .1;
		eye[2] = getZPos(neptune) - 1.1;
		at[2] = getZPos(neptune);
	}
}

void EnableLighting(void)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	GLfloat light1_position[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };	/* bright white */
	GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light1_ambient[] = { 1.0, 1.0, 1.0, 1.0 }; /* soft white */
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	//glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);
}

void LoadTextureMap()
{
	int width, height, channels;

	sunImage = SOIL_load_image("sunmap.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &s);
	glBindTexture(GL_TEXTURE_2D, s);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		sunImage);
	SOIL_free_image_data(sunImage);

	earthImage = SOIL_load_image("earth.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &e);
	glBindTexture(GL_TEXTURE_2D, e);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		earthImage);
	SOIL_free_image_data(earthImage);

	merImage = SOIL_load_image("mercurymap.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &m1);
	glBindTexture(GL_TEXTURE_2D, m1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		merImage);
	SOIL_free_image_data(merImage);

	venImage = SOIL_load_image("venusmap.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &v);
	glBindTexture(GL_TEXTURE_2D, v);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		venImage);
	SOIL_free_image_data(venImage);

	marImage = SOIL_load_image("mars_1k_color.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &m2);
	glBindTexture(GL_TEXTURE_2D, m2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		marImage);
	SOIL_free_image_data(marImage);

	jupImage = SOIL_load_image("jupitermap.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &j);
	glBindTexture(GL_TEXTURE_2D, j);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		jupImage);
	SOIL_free_image_data(jupImage);

	satImage = SOIL_load_image("saturnmap.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &st);
	glBindTexture(GL_TEXTURE_2D, st);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		satImage);
	SOIL_free_image_data(satImage);

	uraImage = SOIL_load_image("uranusmap.png", &width, &height, &channels, SOIL_LOAD_AUTO);
	glGenTextures(1, &u);
	glBindTexture(GL_TEXTURE_2D, u);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		channels, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGBA, // format
		GL_UNSIGNED_BYTE, // type
		uraImage);
	SOIL_free_image_data(uraImage);

	nepImage = SOIL_load_image("neptunemap.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &n);
	glBindTexture(GL_TEXTURE_2D, n);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		nepImage);
	SOIL_free_image_data(nepImage);

	moonImage = SOIL_load_image("moonmap1k.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &moon);
	glBindTexture(GL_TEXTURE_2D, moon);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		moonImage);
	SOIL_free_image_data(moonImage);

	asteroidImage = SOIL_load_image("ceres.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &a);
	glBindTexture(GL_TEXTURE_2D, a);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		asteroidImage);
	SOIL_free_image_data(asteroidImage);

	starImage = SOIL_load_image("stars.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &sta);
	glBindTexture(GL_TEXTURE_2D, sta);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		starImage);
	SOIL_free_image_data(starImage);

	satRingImage = SOIL_load_image("ringsSat.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &satRi);
	glBindTexture(GL_TEXTURE_2D, satRi);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		satRingImage);
	SOIL_free_image_data(satRingImage);

	uraRingImage = SOIL_load_image("ringsUra.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &uraRi);
	glBindTexture(GL_TEXTURE_2D, uraRi);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		uraRingImage);
	SOIL_free_image_data(uraRingImage);

	jupRingImage = SOIL_load_image("ringsSat.png", &width, &height, 0, SOIL_LOAD_RGB);
	glGenTextures(1, &jupRi);
	glBindTexture(GL_TEXTURE_2D, jupRi);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // level, 0 = base, no minimap,
		GL_RGB, // internalformat
		width, // width
		height, // height
		0, // border, always 0 in OpenGL ES
		GL_RGB, // format
		GL_UNSIGNED_BYTE, // type
		jupRingImage);
	SOIL_free_image_data(jupRingImage);
}

void play() {
	hours++;
	if (!getPause()) {
		if (hours % 1 == 0)
			days++;
		if (hours % 360 == 0)
			years++;
	}
	glutPostRedisplay();
}

void display(void) {
	glLoadIdentity();
	getPlanetPos();
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], 0, 1, 0);
	glRotatef(yRot, 1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, sta);
	gluQuadricDrawStyle(star, GLU_FILL);
	gluQuadricOrientation(star, GLU_INSIDE);
	gluQuadricTexture(star, GL_TRUE);
	gluQuadricNormals(star, GLU_SMOOTH);
	gluQuadricTexture(star, sta);
	gluSphere(star, 60, 40, 40);
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, s);
	sun.drawSun(days, 9.0, 30);  //sun
	glDisable(GL_TEXTURE_2D);
	EnableLighting();

	glMaterialfv(GL_FRONT, GL_EMISSION, lightnone);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, e);
	earth.drawPlanet(1, hours, 10.8, 0.09, 0, 1, 0, days); //earth
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, moon);
	earthMoon.drawMoon(0, 1.7, 0.0, 0.1, 1.0, 1.0, 1.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();

	sun.rotationReset();
	sun.sunRotation(days * 4.14);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m1);
	mercury.drawPlanet(1, hours * .071, 9.7, 0.04, 0, 1, 0, days * 4.14); //mercury
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	sun.rotationReset();
	sun.sunRotation(days * 1.61);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, v);
	venus.drawPlanet(1, hours * -.004, 10.34, 0.09, 0, 1, 0, days * 1.61); //venus
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	sun.rotationReset();
	sun.sunRotation(days * .53);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m2);
	mars.drawPlanet(1, hours, 11.7, 0.045, 0, 1, 0, days * .53); //mars
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	sun.rotationReset();
	sun.sunRotation(days * .28);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, j);
	jupiter.drawPlanet(1, hours * 2.5, 14.0, 0.9, 0, 1, 0, days * .28); //jupiter
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, jupRi);
	jupRing.drawRings(1, 1, 1.15, 1.20, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	sun.rotationReset();
	sun.sunRotation(days * .23);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, st);
	saturn.drawPlanet(1, hours  * 2.5, 18.0, 0.75, 0, 1, 0, days * .23); //saturn
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, satRi);
	satRing.drawRings(1, 1, 1.05, 1.55, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	sun.rotationReset();
	sun.sunRotation(days * .21);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, u);
	uranus.drawPlanet(1, hours * 1.41, 21.5, 0.32, 1, 0, 0, days * .21); //uranus
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, uraRi);
	uraRing.drawRings(1, 1, 1.05, 1.30, 90);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	sun.rotationReset();
	sun.sunRotation(days * .205);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, n);
	neptune.drawPlanet(1, hours * 1.42, 24.0, 0.3, 0, 1, 0, days * .205); //neptune
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, uraRi);
	uraRing.drawRings(1, 1, 1.05, 1.15, 0);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	for (int i = 1; i <= 30; i++) {
		sun.rotationReset();
		sun.sunRotation(.2 * i * days);
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, a);
		asteroid.drawAsteroid(12.25);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	glPopMatrix();
	glFlush();
}