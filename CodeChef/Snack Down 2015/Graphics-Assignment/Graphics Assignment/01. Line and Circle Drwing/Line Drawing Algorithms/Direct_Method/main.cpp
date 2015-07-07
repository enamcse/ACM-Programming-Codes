#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

float x1, x2, y1, y2;
void drawLine(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    Sleep(10);
    glutSwapBuffers();

}

void display_Line_With_DirectMethod(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3d(1,0,0);       //Red color code
    float b;
    float x=x1, y=y1;
    float m;
    m=(y2-y1)/(x2-x1);
    b=y1-m*x1;
    if(x1==x2)
    {
        x=x1;
        y=y1;
        while(y<=y2)
        {
            drawLine(x, y);
            y++;
        }
    }
    else if(m<=1)
    {
        while(x<=x2)
        {
            y=m*x+b;
            cout<<x<<" "<<y<<endl;
            drawLine(x, y);
            x++;
        }

    }
    else
    {
        while(y<=y2)
        {
            x=(y-b)/m;
            cout<<x<<" "<<y<<endl;
            drawLine(x, y);
            drawLine(x, y);
            y++;
        }

    }
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,700);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Direct Method for Line Drawing");
    gluOrtho2D(-500,500,-350,350);
    cout<<"Enter four points (x1, y1  and  x2, y2): ";
    cin>>x1>>y1>>x2>>y2;
    glutDisplayFunc(display_Line_With_DirectMethod);
    cout<<"rajib"<<endl;
    glutMainLoop();

    return EXIT_SUCCESS;
}
