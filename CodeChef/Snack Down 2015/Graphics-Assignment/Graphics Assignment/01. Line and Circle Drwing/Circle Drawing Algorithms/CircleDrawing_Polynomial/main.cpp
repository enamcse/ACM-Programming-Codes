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
void setPixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    //Sleep(10);
    //glutSwapBuffers();

}

void display_Circle_Using_Polynomial(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3d(1,0,0);

    float h=150,k=150,r=100,x=0,y=0,range,i=0;

    range=r/sqrt(2);
    printf("%lf\n",range);
    while(x<=range)
    {

        y=sqrt(pow(r,2)-pow(x,2));
        setPixel((int)(h+x),(int)(k+y));
        setPixel((int)(h+y),(int)(k+x));
        setPixel((int)(h+y),(int)(k-x));
        setPixel((int)(h+x),(int)(k-y));
        setPixel((int)(h-x),(int)(k-y));
        setPixel((int)(h-y),(int)(k-x));
        setPixel((int)(h-y),(int)(k+x));
        setPixel((int)(h-x),(int)(k+y));

        x+=.05;
    }

    glutSwapBuffers();
}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("CircleDrawing Using Polynomial");
    glOrtho(0,640,0,480,0,1);
    glutDisplayFunc(display_Circle_Using_Polynomial);
    glutMainLoop();
    return EXIT_SUCCESS;
}

