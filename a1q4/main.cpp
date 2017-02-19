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

void sky()
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0.224, 0.902);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glColor3f(0, 0.224, 0.902);
    glVertex3f(600.0f, 0.0f, 0.0f);
    glColor3f(0.8, 0.933, 1);
    glVertex3f(600.0f, 600.0f, 0.0f);
    glColor3f(0.8, 0.933, 1);
    glVertex3f(0.0f, 600.0f, 0.0f);
    glEnd();
}

void grass()
{
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glColor3f(0, 1, 0);
    glVertex3f(600.0f, 0.0f, 0.0f);
    glColor3f(0, 0.3, 0);
    glVertex3f(600.0f, 200.0f, 0.0f);
    glColor3f(0, 0.3, 0);
    glVertex3f(0.0f, 200.0f, 0.0f);
    glEnd();
}

void frontwall()
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0.4, 0);
    glVertex3f(80.0f, 120.0f, 0.0f);
    glColor3f(1, 0.4, 0);
    glVertex3f(220.0f, 120.0f, 0.0f);
    glColor3f(0.4, 0.102, 0);
    glVertex3f(220.0f, 300.0f, 0.0f);
    glColor3f(0.4, 0.102, 0);
    glVertex3f(150.0f, 350.0f, 0.0f);
    glColor3f(0.4, 0.102, 0);
    glVertex3f(80.0f, 300.0f, 0.0f);
    glEnd();

}

void sidewall()
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0.4, 0);
    glVertex3f(220.0f, 120.0f, 0.0f);
    glColor3f(1, 0.4, 0);
    glVertex3f(450.0f, 200.0f, 0.0f);
    glColor3f(0.4, 0.102, 0);
    glVertex3f(450.0f, 360.0f, 0.0f);
    glColor3f(0.4, 0.102, 0);
    glVertex3f(220.0f, 300.0f, 0.0f);
    glEnd();
}

void gate()
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(110.0f, 120.0f, 0.0f);
    glColor3f(0, 0, 0);
    glVertex3f(190.0f, 120.0f, 0.0f);
    glColor3f(0, 0, 0);
    glVertex3f(190.0f, 250.0f, 0.0f);
    glColor3f(0, 0, 0);
    glVertex3f(110.0f, 250.0f, 0.0f);
    glEnd();
}

void roof1()
{
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(220.0f, 300.0f, 0.0f);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(450.0f, 360.0f, 0.0f);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(380.0f, 400.0f, 0.0f);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(150.0f, 350.0f, 0.0f);
    glEnd();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    grass();
    frontwall();
    gate();
    sidewall();
    roof1();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Assignment 1 Question 3");
    init2D(0.0f, 0.0f, 0.0f);
    glutDisplayFunc(display);

    glutMainLoop();
}
