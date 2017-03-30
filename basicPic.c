
/* Copyright (c) Mark J. Kilgard, 1997. */

/* This program is freely distributable without licensing fees
and is provided without guarantee or warrantee expressed or
implied. This program is -not- in the public domain. */

/* This program was requested by Patrick Earl; hopefully someone else
will write the equivalent Direct3D immediate mode program. */
#define M_PI 3.14159265358979323846
#include "glut.h" //<GL/glut.h>
#include <math.h>
GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };  /* Red diffuse light. */
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };  /* Infinite light location. */
GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
	{ -1.0, 0.0, 0.0 },{ 0.0, 1.0, 0.0 },{ 1.0, 0.0, 0.0 },
	{ 0.0, -1.0, 0.0 },{ 0.0, 0.0, 1.0 },{ 0.0, 0.0, -1.0 } };
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
	{ 0, 1, 2, 3 },{ 3, 2, 6, 7 },{ 7, 6, 5, 4 },
	{ 4, 5, 1, 0 },{ 5, 6, 2, 1 },{ 7, 4, 0, 3 } };
GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */

void renderSqaure(void) {
	
}

void display(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Clear the background of our window to red  
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)  
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations  
	
	///////////////////Background///////////////////////
	glBegin(GL_QUADS); 
	// Sky  
	glColor3f(0.0f, 0.f, 1.f);
	glVertex3f(-1.f, -1.f, 0.0f); // The bottom left corner  
	glVertex3f(-1.f, 1.f, 0.0f); // The top left corner  
	glVertex3f(1.f, 1.f, 0.0f); // The top right corner  
	glVertex3f(1.0f, -1.f, 0.0f); // The bottom right corner  	

	//Ground
	glColor3f(0.0f, 1.f, 0.f);
	glVertex3f(-1.f, -1.f, 0.0f); // The bottom left corner  
	glVertex3f(-1.f, -0.7f, 0.0f); // The top left corner  
	glVertex3f(1.f, -0.7f, 0.0f); // The top right corner  
	glVertex3f(1.0f, -1.f, 0.0f); // The bottom right corner 

	glEnd();

	//sun
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	float x, y, ray;
	ray = 0.0;
	x = 0.75;
	y = 0.75;
	float radius = 0.2f;
	for (int i = 0; i < 360; i++)
	{
		float degInRad = (i*M_PI*2) / (360);
		glVertex3f(x - cos(degInRad)*radius, y - sin(degInRad)*radius, 0.f);
	}
	glEnd();
	//rays
	for (int i = 0; i < 7; i++) {
		ray = (i*51.4285714286*M_PI * 2) / (360);
		glLineWidth(5);
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(x, y, 0.f);
		glVertex3f(x - cos(ray)*radius*2, y - sin(ray)*radius*2, 0.f);
		glEnd();

	}
	///////////////////Background-End///////////////////

	///////////////////Foreground///////////////////////
	// house
	glBegin(GL_QUADS); 
	glColor3f(169.f / 255.f, 169.f / 255.f, 169.f / 255.f);
	glVertex3f(0.1f, -0.85, 0.0f); // The bottom left corner  
	glVertex3f(0.1f, 0.f, 0.0f); // The top left corner  
	glVertex3f(0.9f, 0.f, 0.0f); // The top right corner  
	glVertex3f(0.9f, -0.85, 0.0f); // The bottom right corner 
	glEnd();


	// door + bars
	glBegin(GL_QUADS); 
	glColor3f(0, 0, 0);
	glVertex3f(0.4f, -0.85, 0.0f); // The bottom left corner  
	glVertex3f(0.4f, -0.5f, 0.0f); // The top left corner  
	glVertex3f(0.6f, -0.5f, 0.0f); // The top right corner  
	glVertex3f(0.6f, -0.85, 0.0f); // The bottom right corner 

	glColor3f(105.f / 255.f, 105.f / 255.f, 105.f / 255.f);
	glVertex3f(0.4175f, -0.85, 0.0f); // The bottom left corner  
	glVertex3f(0.4175f, -0.5f, 0.0f); // The top left corner  
	glVertex3f(0.44f, -0.5f, 0.0f); // The top right corner  
	glVertex3f(0.44f, -0.85, 0.0f); // The bottom right corner 

	glVertex3f(0.465f, -0.85, 0.0f); // The bottom left corner  
	glVertex3f(0.465f, -0.5f, 0.0f); // The top left corner  
	glVertex3f(0.4875f, -0.5f, 0.0f); // The top right corner  
	glVertex3f(0.4875f, -0.85, 0.0f); // The bottom right corner 

	glVertex3f(0.5125f, -0.85, 0.0f); // The bottom left corner  
	glVertex3f(0.5125f, -0.5f, 0.0f); // The top left corner  
	glVertex3f(0.535f, -0.5f, 0.0f); // The top right corner  
	glVertex3f(0.535f, -0.85, 0.0f); // The bottom right corner 

	glVertex3f(0.56f, -0.85, 0.0f); // The bottom left corner  
	glVertex3f(0.56f, -0.5f, 0.0f); // The top left corner  
	glVertex3f(0.5825f, -0.5f, 0.0f); // The top right corner  
	glVertex3f(0.5825f, -0.85, 0.0f); // The bottom right corner 

	
	glEnd();


	//windows + bars
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(0.20f, -0.35, 0.0f); // The bottom left corner  
	glVertex3f(0.20f, -0.1f, 0.0f); // The top left corner  
	glVertex3f(0.45f, -0.1f, 0.0f); // The top right corner  
	glVertex3f(0.45f, -0.35, 0.0f); // The bottom right corner

	float barWidth = 0.0225;
	float barStart = 0.2175;
	for (int i = 0; i < 5; i++) {
		glColor3f(105.f / 255.f, 105.f / 255.f, 105.f / 255.f);
		glVertex3f(barStart, -0.35, 0.0f); // The bottom left corner  
		glVertex3f(barStart, -0.1f, 0.0f); // The top left corner  
		glVertex3f(barStart + barWidth, -0.1f, 0.0f); // The top right corner  
		glVertex3f(barStart + barWidth, -0.35, 0.0f); // The bottom right corner
		barStart += 0.0475;
	}

	glColor3f(0, 0, 0);
	glVertex3f(0.55f, -0.35, 0.0f); // The bottom left corner  
	glVertex3f(0.55f, -0.1f, 0.0f); // The top left corner  
	glVertex3f(0.8f, -0.1f, 0.0f); // The top right corner  
	glVertex3f(0.8f, -0.35, 0.0f); // The bottom right corner 
	barStart = 0.55 + 0.0175;
	for (int i = 0; i < 5; i++) {
		glColor3f(105.f / 255.f, 105.f / 255.f, 105.f / 255.f);
		glVertex3f(barStart, -0.35, 0.0f); // The bottom left corner  
		glVertex3f(barStart, -0.1f, 0.0f); // The top left corner  
		glVertex3f(barStart + barWidth, -0.1f, 0.0f); // The top right corner  
		glVertex3f(barStart + barWidth, -0.35, 0.0f); // The bottom right corner
		barStart += 0.0475;
	}
	glEnd();

	

	//nose hole (prison/house/skull thing)
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
	glVertex3f(0.465f, -0.435, 0.0f); // The bottom left corner  
	glVertex3f(0.5f, -0.4f, 0.0f); // The top  
	glVertex3f(0.535f, -0.435, 0.0f); // The bottom right corner 
	barStart = 0.55 + 0.0175;
	glEnd();

	//person - head
	glColor3f(0.0f, 0.0f, 0.0f);

	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	x = -0.35;
	y = -0.35;
	radius = 0.075f;
	for (int i = 0; i < 360; i++)
	{
		float degInRad = (i*M_PI * 2) / (360);
		glVertex3f(x - cos(degInRad)*radius, y - sin(degInRad)*radius, 0.f);
	}
	glEnd();

	
	//person body 

	ray = (55 * M_PI * 2) / (360);
	glBegin(GL_LINES);
	glVertex3f(x - cos(ray)*radius, y - sin(ray)*radius, 0.f);
	glVertex3f(x - cos(ray)*radius * 2, y - sin(ray)*radius * 2.5, 0.f);
	glVertex3f(x - cos(ray)*radius * 2, y - sin(ray)*radius * 2.5, 0.f);
	glVertex3f(-0.415, -0.55, 0.f);
	glVertex3f(-0.415, -0.55, 0.f); 
	glVertex3f(-0.415, -0.65, 0.f);
	glVertex3f(x - cos(ray)*radius * 2, y - sin(ray)*radius * 2.5, 0.f); 
	glVertex3f(-0.445, -0.55, 0.f);
	glVertex3f(-0.445, -0.55, 0.f);
	glVertex3f(-0.475, -0.75, 0.f);
	glVertex3f(-0.475, -0.75, 0.f);
	glVertex3f(-0.435, -0.8, 0.f);
	glVertex3f(-0.435, -0.8, 0.f);
	glVertex3f(-0.445, -0.95, 0.f);

	glVertex3f(-0.475, -0.75, 0.f);
	glVertex3f(-0.485, -0.95, 0.f);
	
	glEnd();


	///////////////////Foreground-End///////////////////
	

	
	glFlush(); // Flush the OpenGL buffers to the window  
}
void
init(void)
{
	
}

int
main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500); // Set the width and height of the window  
	glutInitWindowPosition(100, 100); // Set the position of the window 
	glutCreateWindow("red 3D lighted cube");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;             /* ANSI C requires main to return int. */
}
