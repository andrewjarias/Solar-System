#pragma once

class Rings {
private:
	GLUquadric* rings;

public:
	Rings(GLUquadric* rings1) {
		rings1 = gluNewQuadric();
		gluQuadricDrawStyle(rings1, GLU_FILL);
		gluQuadricOrientation(rings1, GLU_OUTSIDE);
		gluQuadricTexture(rings1, GL_TRUE);
		gluQuadricNormals(rings1, GLU_SMOOTH);
		rings = rings1;
	}

	void drawRings(GLuint num, float scale, float iRad, float oRad, float rotate) {
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; /* bright white */
		GLfloat mat_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
		GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 }; /* same as diffuse */
		GLfloat mat_shininess = 10.0;
		glMaterialfv(GL_FRONT_LEFT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
		glScalef(-scale, scale, scale);
		glRotatef(rotate, 0, 1, 0);
		gluQuadricTexture(rings, num);
		gluDisk(rings, iRad, oRad, 40, 40);
	}
};