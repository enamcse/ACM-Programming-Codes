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

void setPixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    Sleep(10);
    glutSwapBuffers();

}

void display_Line_With_Brasenhams_Algorithm(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3d(0,0,1); //red color

    int x1p, y1p, x2p, y2p;

    x1p = (int) (x1+0.5);
    x2p = (int) (x2+0.5);
    y1p = (int) (y1+0.5);
    y2p = (int) (y2+0.5);
    float m=(y2-y1)/(x2-x1);
    if(m<0||m>1)
    {
        cout<<"Sorry Input format is not correct: \nBrasenhames algorithm works when\n0 < Slop < 1"<<endl;
        exit(0);
        return;
    }


    int x, y;
    x=x1p;
    y=y1p;
    int dx, dy, dT, dS, d;
    dx=x2p-x1p;
    dy=y2p-y1p;
    dT=2*(dy-dx);
    dS=2*dy;
    d = 2*dy-dx;
    setPixel(x, y);
    while(x<x2p)
    {
        x++;
        if(d<0)
            d=d+dS;
        else
        {
            y++;
            d=d+dT;
        }
        setPixel(x, y);
    }
    glutSwapBuffers();
}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Brasenham's Algorithm for Line Drawing");
    glOrtho(0,640,0,480,0,1);
    cout<<"Enter four points (x1, y1  and  x2, y2): ";
    cin>>x1>>y1>>x2>>y2;
    glutDisplayFunc(display_Line_With_Brasenhams_Algorithm);
    //cout<<"rajib"<<endl;
    glutMainLoop();

    return EXIT_SUCCESS;
}
