#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void rectangle()
{
    glBegin(GL_POLYGON);
    glColor3f(0.4,0,0.8);
    glVertex3f(150.0f, 200.0f, 0.0f);
    glColor3f(0.4,0,0.8);
    glVertex3f(450.0f, 200.0f, 0.0f);
    glColor3f(0.6,0,0.6);
    glVertex3f(450.0f, 400.0f, 0.0f);
    glColor3f(0.6,0,0.6);
    glVertex3f(150.0f, 400.0f, 0.0f);
    glEnd();
}

void text()
{
    char menu[80];
    strcpy(menu,"Have courage and be kind");
    int len;
    len = strlen(menu);

    glColor3f(1,1,1);

    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();

    gluOrtho2D( 0, 600, 0, 600 );

    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();

    glLoadIdentity();

    glRasterPos2i(190, 300);


    for ( int i = 0; i < len; ++i )
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, menu[i]);
    }

    glPopMatrix();

    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    rectangle();
    text();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Assignment 1 Question 2");
    init2D(0.0f, 0.0f, 0.0f);
    glutDisplayFunc(display);

    glutMainLoop();
}
