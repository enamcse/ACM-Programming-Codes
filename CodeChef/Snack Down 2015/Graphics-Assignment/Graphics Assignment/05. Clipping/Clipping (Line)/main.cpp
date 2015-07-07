
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
using namespace std;

int xMin,xMax,yMin,yMax,ix1,ix2,iy1,iy2;

void DrawLine(double x1, double y1, double x2, double y2)
{
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    glutSwapBuffers();
}
int FindBit(int x, int y)
{
    int mask=0;
    if(y>yMax)  mask = mask | (1<<4);
    if(y<yMin)  mask = mask | (1<<3);
    if(x>xMax)  mask = mask | (1<<2);
    if(x<xMin)  mask = mask | (1<<1);
    return mask;
}
POINT clip(int x, int y,double m)
{
    int mask = FindBit(x,y);
    int xi, yi;
    xi=x;yi=y;
    if(mask&(1<<4))
    {
        yi=yMax;
        xi=x+(yi-y)/m;
    }
    else if(mask&(1<<3))
    {
        yi=yMin;
        xi=x+(yi-y)/m;
    }
    else if(mask&(1<<2))
    {
        xi=xMax;
        yi=y+m*(xi-x);
    }
    else if(mask&(1<<1))
    {
        xi=xMin;
        yi=y+m*(xi-x);
    }

    POINT p;
    p.x=xi;
    p.y=yi;
    return p;



}
void Apply_CohenSutherLand(int x1,int y1,int x2,int y2)
{
    int msk1, msk2, flag;
    flag=0;
    double m = (double) (y2-y1)/ (double)(x2-x1);
    while(true)
    {
        msk1=FindBit(x1,y1);
        msk2=FindBit(x2,y2);
        if(msk1==0&&msk2==0)
        {
            flag=1;
            break;
        }

        POINT p1 = clip(x1,y1,m);
        POINT p2 = clip(x2,y2,m);
        x1=p1.x;y1=p1.y;
        x2=p2.x;y2=p2.y;

    }
    if(flag) DrawLine(x1,y1,x2,y2);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int x1, x2, y1, y2;
    x1 = ix1;y1 = iy1;x2 = ix2;y2 = iy2;
    xMin = 100;xMax = 300;yMin = 100;yMax = 300;
    glColor3d(1,0,0);       //Red Color code
    DrawLine(xMin,yMin,xMax,yMin);
    DrawLine(xMin,yMax,xMax,yMax);
    DrawLine(xMin,yMin,xMin,yMax);
    DrawLine(xMax,yMin,xMax,yMax);

    DrawLine(x1,y1,x2,y2);
    glColor3d(1,1,1);       //White Color code
    Apply_CohenSutherLand(x1,y1,x2,y2);
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    //glutInit(&argc,argv);
    glutInitWindowSize(1000,700);
    glutInitWindowPosition(850,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Line Clipping with Cohen-SutherLand Algorithm");
    gluOrtho2D(-200,800,-200,500);
    cout<<"Enter x1,y1 and x2,y2 to draw a line"<<endl;
    cin>>ix1>>iy1>>ix2>>iy2;
    glutDisplayFunc(display);
    cout<<"rajib"<<endl;
    glutMainLoop();
    cout<<"rajib2"<<endl;
    return EXIT_SUCCESS;
}

//50 200 200 320
//50 200 420 -50
//50 200 320 50
