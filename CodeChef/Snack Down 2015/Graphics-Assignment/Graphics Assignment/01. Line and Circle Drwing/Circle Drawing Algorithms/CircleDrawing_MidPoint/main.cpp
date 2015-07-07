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
    Sleep(5);
    glutSwapBuffers();

}

void display_Circle_Using_Midpoint(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3d(1,0,0);

    float h=250,k=250,r=150,x=0,y=r,d=1-r;


    while(x<=y){

        setPixel((int)(h+x),(int)(k+y));
        setPixel((int)(h+y),(int)(k+x));
        setPixel((int)(h+y),(int)(k-x));
        setPixel((int)(h+x),(int)(k-y));
        setPixel((int)(h-x),(int)(k-y));
        setPixel((int)(h-y),(int)(k-x));
        setPixel((int)(h-y),(int)(k+x));
        setPixel((int)(h-x),(int)(k+y));

        if(d<0){
            d=d+2*x+3;
        }
        else{
            d=d+2*(x-y)+5;
            y--;
        }
        x++;
    }

    glutSwapBuffers();

}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("CircleDrawing Using Midpoint_Algorithm");
    glOrtho(0,640,0,480,0,1);
    glutDisplayFunc(display_Circle_Using_Midpoint);
    glutMainLoop();
    return EXIT_SUCCESS;
}

