#pragma once
#include <cmath>
#include <time.h>


class Asteroid {
private:
	GLUquadric *asteroid;
	float speed, scaleX, scaleY, scaleZ;

public:
	Asteroid(GLUquadric *asteroid1) {
		asteroid1 = gluNewQuadric();
		gluQuadricDrawStyle(asteroid1, GLU_FILL);
		gluQuadricOrientation(asteroid1, GLU_OUTSIDE);
		gluQuadricTexture(asteroid1, GL_TRUE);
		gluQuadricNormals(asteroid1, GLU_SMOOTH);
		asteroid = asteroid1;
		srand(time(NULL));
	}

	void drawAsteroid(float x) {
		glTranslatef(x, 0.0, 0.0);
		glRotatef(.5, 0.0, 0.0, 1.0);
		glScalef(.04, .02, .05);
		glColor3f(0.0, 1.0, 0.5);
		gluSphere(asteroid, 1, 40, 40);
	}
};