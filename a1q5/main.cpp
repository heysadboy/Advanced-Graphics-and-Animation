#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <bits/stdc++.h>

using namespace std;

float scale = 2.0f;
float transx = 0.0f;
float transy = 0.0f;
float eyeX = 0.0f, eyeY = 0.0f, eyeZ = 10.0f;
float centerX = 0.0f, centerY = 0.0f, centerZ = 0.0f;
float upX = 0.0f, upY = 1.0f, upZ = 0.0;

float initialx1 = -1.0f, initialy1 = -1.0f, initialx2 = 1.0f;
float initialy2 = -1.0f, initialx3 = 0.0f, initialy3 = 1.0f;
float angle = 0.0;
int rotateX = 0, rotateY = 0, rotateZ = 0;
int window_width = 800, window_height = 500;


//To handle the mouse click events
void mouseclick(int button, int state, int x, int y)
{
	switch(button) {
		case 0: //left click
			scale += 0.09f;
			cout<<" scale "<<scale<<endl;
			break;
		case 2: //right click
			scale -= 0.09f;
			cout<<" scale "<<scale<<endl;
			break;
    }
}

//To draw traingle with pts as three coordinate points
void drawtriangle()
{
	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(initialx1, initialy1, 0.0f);
		glVertex3f(initialx2, initialy2, 0.0f);
		glVertex3f(initialx3, initialy3, 0.0f);
	glEnd();
}



void changeDimension(int width, int height) {

	float width_by_height_ratio;

	if( height == 0)
		width_by_height_ratio = width*1.0;
	else
		width_by_height_ratio = width*1.0/height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45.0f, width_by_height_ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void display(void) {
	//Clearing of the Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();


	// Setting the camera
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ );

	glScalef(scale, scale, scale);
	glTranslatef(transx, transy, 0);
	glRotatef(angle, rotateX, rotateY, rotateZ);

	drawtriangle();

	glutSwapBuffers();
}

void rotatein(int direction){
    angle += 1.0;
    //rotateX = rotateY = rotateZ = 0;
    if( direction == 0 ){ rotateX = 1; rotateY = 0; rotateZ = 0;}
    else if( direction == 1 ){ rotateX = 0; rotateY = 1; rotateZ = 0;}
    else if( direction == 2 ){ rotateX = 0; rotateY = 0; rotateZ = 1;}
}

void rotateout(int direction){
    angle -= 1.0;
    //rotateX = rotateY = rotateZ = 0;
    if( direction == 0 ){ rotateX = 1; rotateY = 0; rotateZ = 0;}
    else if( direction == 1 ){ rotateX = 0; rotateY = 1; rotateZ = 0;}
    else if( direction == 2 ){ rotateX = 0; rotateY = 0; rotateZ = 1;}
}

void moveup()
{
	transy += 0.09f;
}

void movedown()
{
	transy -= 0.09f;
}

void moveleft()
{
	transx -= 0.09f;
}

void moveright()
{
	transx += 0.09f;
}

void processSpecialKeys(int key, int x, int y)
{
    if( key == GLUT_KEY_UP )
        moveup();
    else if( key == GLUT_KEY_DOWN )
        movedown();
    else if( key == GLUT_KEY_LEFT )
        moveleft();
    else if( key == GLUT_KEY_RIGHT)
        moveright();
    else if( key == GLUT_KEY_F1) //X direction
        rotatein(0);
    else if( key == GLUT_KEY_F2)
        rotateout(0);

    else if( key == GLUT_KEY_F3) //y direction
        rotatein(1);
    else if( key == GLUT_KEY_F4)
        rotateout(1);

    else if( key == GLUT_KEY_F5) //z direction
        rotatein(2);
    else if( key == GLUT_KEY_F6)
        rotateout(2);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(window_width, window_height);
	glutCreateWindow("Question 5 (a)");

	glutDisplayFunc( display );
	glutReshapeFunc(changeDimension);

	glutIdleFunc( display );

   	glutSpecialFunc(processSpecialKeys);

	//To handle mouse click and scrolling things
	glutMouseFunc(mouseclick);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;

}
