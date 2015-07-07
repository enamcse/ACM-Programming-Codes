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
    Sleep(1);
    glutSwapBuffers();

}

void display_Circle_Using_Brasenhams_Algorithm(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3d(1,0,0);

    float h=250,k=250,r=100,x=0,y=r,d=3-2*r;


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
            d=d+4*x+6;
        }
        else{
            d=d+4*(x-y)+10;
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
    glutCreateWindow("CircleDrawing Using BrasenHams Algorithm");
    glOrtho(0,640,0,480,0,1);
    glutDisplayFunc(display_Circle_Using_Brasenhams_Algorithm);
    glutMainLoop();
    return EXIT_SUCCESS;
}

