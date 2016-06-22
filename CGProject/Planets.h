#pragma once
#include <cmath>

#define PI 3.14159265

class Planets {
private:
	GLUquadric* planet;
	GLfloat rotation, sunRotation;
	float distance;
	double x, y, z;
	float xPt, zPt;

public:
	Planets(GLUquadric* planet1) {
		planet1 = gluNewQuadric();
		gluQuadricDrawStyle(planet1, GLU_FILL);
		gluQuadricOrientation(planet1, GLU_OUTSIDE);
		gluQuadricTexture(planet1, GL_TRUE);
		gluQuadricNormals(planet1, GLU_SMOOTH);
		planet = planet1;
		GLfloat rotation = 0;
	}

	void drawPlanet(GLuint num, int hours, float dist, float radius, float x, float y, float z, int sunRotate) {
		GLfloat rotation = 0;
		distance = dist;
		sunRotation = (sunRotate % 1440) / 4;
		rotation = (GLfloat)(hours % 720) / 2;
		glTranslatef(dist, 0.0, 0.0);
		glRotatef(rotation, x, y, z);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		glScalef(-radius, radius, radius);
		gluQuadricTexture(planet, num);
		gluSphere(planet, 1.0, 40, 40);
	}

	float getX() {
		float rad = sunRotation * PI / 180;
		xPt = cos(rad) * distance;
		return xPt;
	}

	float getZ() {
		float rad = sunRotation * PI / 180;
		zPt = sin(rad) * distance;
		return -zPt;
	}
};