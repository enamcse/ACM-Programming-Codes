#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

#define pi 3.1416
void setPixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    //Sleep(1);
    //glutSwapBuffers();

}

void display_Circle_Using_Triangle_Formula(void)
{
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3d(1,0,0);

    float h=0,k=0,r=70,x,y,range,i=0,Q=0;

    range=pi/4;

    while(Q<=range){

        x=r*cos(Q);

        y=r*sin(Q);

        setPixel((int)(h+x),(int)(k+y));
        setPixel((int)(h+y),(int)(k+x));
        setPixel((int)(h+y),(int)(k-x));
        setPixel((int)(h+x),(int)(k-y));
        setPixel((int)(h-x),(int)(k-y));
        setPixel((int)(h-y),(int)(k-x));
        setPixel((int)(h-y),(int)(k+x));
        setPixel((int)(h-x),(int)(k+y));

        Q+=.0005;
    }

    glutSwapBuffers();

}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("CircleDrawing Using Triangle_Formula");
    gluOrtho2D(-320,320,-240,240);
    glutDisplayFunc(display_Circle_Using_Triangle_Formula);
    glutMainLoop();
    return EXIT_SUCCESS;
}

