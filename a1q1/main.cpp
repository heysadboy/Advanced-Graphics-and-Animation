#include <GL/glut.h>
#include<bits/stdc++.h>

using namespace std;

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void RenderToDisplay()
{
    int l,lenghOfQuote, i;
    char str[80];
    strcpy(str,"Have courage and be kind");
    cout<<str;
    lenghOfQuote = (int)strlen(str);

    for (i = 0; i < lenghOfQuote; i++)
    {
        glColor3f(1.0, 0.0, 0.0);
        glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]);
    }

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);

    glVertex3f(150.0f, 200.0f, 0.0f);
    glColor3f(0.940, 0.37, 0.47);
    glVertex3f(450.0f, 200.0f, 0.0f);
    glColor3f(0.940, 0.37, 0.47);
    glVertex3f(450.0f, 400.0f, 0.0f);
    glColor3f(0.69, 0.27, 0.57);
    glVertex3f(150.0f, 400.0f, 0.0f);
    glColor3f(0.69, 0.27, 0.57);

    glEnd();

    RenderToDisplay();

    glFlush();

}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0,0);

    glLineWidth(3);

    glutCreateWindow("Assignment Q2");
    init2D(0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutMainLoop();

}
