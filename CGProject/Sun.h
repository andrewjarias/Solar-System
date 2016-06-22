#pragma once

class Sun {
private:
	GLUquadric* sun;
	GLfloat rotate;

public:
	Sun(GLUquadric* sun1) {
		sun1 = gluNewQuadric();
		gluQuadricDrawStyle(sun1, GLU_FILL);
		gluQuadricOrientation(sun1, GLU_OUTSIDE);
		gluQuadricTexture(sun1, GL_TRUE);
		gluQuadricNormals(sun1, GLU_SMOOTH);
		sun = sun1;
		rotate = 0;
	}

	void drawSun(int days, float radius, int edges) {
		GLfloat color[] = { 1.0, 1.0, 1.0, 1.0 };
		glMaterialfv(GL_FRONT, GL_EMISSION, color);
	
		GLfloat rotation = 0;
		rotate = (GLfloat)(days % 1440) / 4;
		glRotatef(rotate, 0.0, 1.0, 0.0);
		gluQuadricTexture(sun, 1);
		gluSphere(sun, 9.0, 40, 40);
		glMaterialfv(NULL, NULL, color);
	}

	void sunRotation(int days) {
		rotate = (GLfloat)(days % 1440) / 4;
		glRotatef(rotate, 0.0, 1.0, 0.0);
	}

	void rotationReset() {
		rotate = -rotate;
		glRotatef(rotate, 0.0, 1.0, 0.0);
	}

	GLfloat getRotate() {
		return rotate;
	}
};