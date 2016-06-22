#pragma once

class Moon {
private:
	GLUquadric *moon;

public:
	Moon(GLUquadric *moon1) {
		moon1 = gluNewQuadric();
		gluQuadricDrawStyle(moon1, GLU_FILL);
		gluQuadricOrientation(moon1, GLU_OUTSIDE);
		gluQuadricTexture(moon1, GL_TRUE);
		gluQuadricNormals(moon1, GLU_SMOOTH);
		moon = moon1;
	}

	void drawMoon(int hours, float x, float z, float radius, float r, float g, float b) {
		glTranslatef(x, 0.0, z);
		glRotatef((GLfloat)((hours % 720) / 2), 0.0, 1.0, 0.0);
		glColor3f(r, g, b);
		gluQuadricTexture(moon, 1);
		gluSphere(moon, radius, 30, 30);
	}
};