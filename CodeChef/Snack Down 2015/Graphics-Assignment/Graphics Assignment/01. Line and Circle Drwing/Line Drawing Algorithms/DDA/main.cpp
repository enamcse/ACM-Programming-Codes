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

SYSTEMTIME st;
double start, end, total;
void drawLine(int x,int y);
void Apply_DDA(void)
{
    float dx,dy;
    dx=x2-x1;
    dy=y2-y1;

    int steps;

    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);

    float xinc=dx/steps;

    float yinc=dy/steps;

    float x=x1;

    float y=y1;

    drawLine(x,y);
    for(int k=0;k<steps;k++)
    {
        x=x+xinc;
        y=y+yinc;
        drawLine(int(x),int(y));
    }

}
void display_Line_With_DDA(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    GetLocalTime(&st);
    start=st.wMilliseconds;

    Apply_DDA();

    GetLocalTime(&st);
    end=st.wMilliseconds;
    total = end-start;
    cout<<start<<" "<<end<<endl;
    cout<<total<<endl;
    glutSwapBuffers();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("DDA Method for Line Drawing");
    glOrtho(0,640,0,480,0,1);
    cout<<"Enter four points (x1, y1  and  x2, y2): ";
    cin>>x1>>y1>>x2>>y2;
    glutDisplayFunc(display_Line_With_DDA);
    cout<<"rajib"<<endl;
    glutMainLoop();

    return EXIT_SUCCESS;
}
