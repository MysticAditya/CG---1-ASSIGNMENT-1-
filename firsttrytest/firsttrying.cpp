/*/
//Jeff Chastine
#include <Windows.h>
#include <GL\glew.h>
#include <freeglut.h>
#include <iostream>
#ifdef __APPLE__
#else
#endif


using namespace std;



void makeatriangle() 
{

	// This function is used to clear all the previously drawn things on the window...
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Function used to draw the triangle
	glBegin(GL_TRIANGLES);

	// Vertices Of the Triangle (Used for drawing the triangle)...
	
	// First Vertex...
	glVertex3f(-0.5, -0.5, 0.0);
	
	// Second Vertex...
	glVertex3f(0.5, 0.0, 0.0);
	
	// Third Vertex...
	glVertex3f(0.0, 0.5, 0.0);


	glEnd();

	glutSwapBuffers();

}

int main(int argc, char **argv)
{

	// Skeleton for the main function...
	void glutInit(int argc, char argv);

	// At which Position the Window should be created...
	glutInitWindowPosition(300, 300);

	// What size should the window be...
	glutInitWindowSize(1200, 800);

	// This command helps us to determine the Color, No of buffers and the depth of the buffer...
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	// Name of the window to be created...
	glutCreateWindow("Assignment Perspective");

	// Function defined to create a triangle...
	glutDisplayFunc(makeatriangle);

	// Function used to start the event cycle...
	glutMainLoop();

	return 1;

}*/

//Jeff Chastine
#include <Windows.h>
#include <GL\glew.h>
#include <freeglut.h>
#include <iostream>

using namespace std;

unsigned char a;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void changetopoint()

{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Function used to draw the triangle
	glBegin(GL_POINTS);

	glVertex3f(0.2f, 0.1f, 0.4f);

	glVertex3f(0.1f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.4f, 0.4f);

	glVertex3f(0.6f, 0.2f, 0.4f);

	glVertex3f(0.6f, 0.6f, 0.4f);

	glEnd();

	glutSwapBuffers();
}

void changetoline()

{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_LINES);

	glVertex3f(0.2f, 0.1f, 0.4f);

	glVertex3f(0.1f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.4f, 0.4f);

	glVertex3f(0.6f, 0.2f, 0.4f);

	glVertex3f(0.6f, 0.6f, 0.4f);

	glEnd();

	glutSwapBuffers();

}

void changetolinestrip()

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_LINE_STRIP);

	glVertex3f(0.2f, 0.1f, 0.4f);

	glVertex3f(0.1f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.4f, 0.4f);

	glVertex3f(0.6f, 0.2f, 0.4f);

	glVertex3f(0.6f, 0.6f, 0.4f);

	glEnd();

	glutSwapBuffers();

}

void changetolineloop()

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);

	glVertex3f(0.2f, 0.1f, 0.4f);

	glVertex3f(0.1f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.4f, 0.4f);

	glVertex3f(0.6f, 0.2f, 0.4f);

	glVertex3f(0.6f, 0.6f, 0.4f);

	glEnd();

	glutSwapBuffers();

}

void changetoquadstrip()

{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUAD_STRIP);

	glVertex3f(0.2f, 0.1f, 0.4f);

	glVertex3f(0.1f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.2f, 0.4f);

	glVertex3f(0.4f, 0.4f, 0.4f);

	glVertex3f(0.6f, 0.2f, 0.4f);

	glVertex3f(0.6f, 0.6f, 0.4f);

	glEnd();

	glutSwapBuffers();

}

void renderer()

{
	switch (a)
	{
	case 'q':
		changetopoint();
		break;
	case 'w':
		changetoline();
		break;
	case 'e':
		changetolinestrip();
		break;
	case 'r':
		changetolineloop();
		break;
	case 't':
		changetoquadstrip();
		break;
	}
	glutPostRedisplay();
}

void keyboardinputs(unsigned char key, int x, int y)

{

	a = key;

}

int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(800, 600);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Hello, GL");
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(renderer);
	glutKeyboardFunc(keyboardinputs);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;
}