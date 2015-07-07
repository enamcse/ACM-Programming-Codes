#include <windows.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <cctype>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define SIZE 8

typedef struct Vertex_Structure
{
    int x;
    int y;
};

typedef struct Edge_Structure
{
    int ymin;
    int ymax;
    double xmin;
    double inverse_slop;
    int sym;
};

int Y_Minimum = 1<<20;
int Y_Maximum = -(1<<20);

Vertex_Structure Point[SIZE] ={{50,0},{20,70},{60,130},{150,150},{230,100},{200,0},{150,0},{100,30}};   // 8 points
Edge_Structure Edge[SIZE];
void DrawLine(double x1, double  y1, double x2, double y2)
{
    glBegin(GL_LINES);
        glColor3f(5, 200, 0);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
    Sleep(10);
    glFlush();
    glutSwapBuffers();

    return;
}

void Draw_BoundaryLines()
{
    int i, j, m, n;
    int x1, y1, x2, y2;
    for(i=0;i<SIZE;i++)
    {
        if(i==SIZE-1)
            j=0;
        else
            j=i+1;

        x1=Point[i].x;
        y1=Point[i].y;
        x2=Point[j].x;
        y2=Point[j].y;
        DrawLine(x1, y1, x2, y2);

    }
}
void Find_Minimum_And_Maximum_Y(void)
{
    for(int i=0;i<SIZE;i++)
    {
        Y_Maximum = max(Y_Maximum, Point[i].y);
        Y_Minimum = min(Y_Minimum, Point[i].y);
    }
    return;
}
void Print_Edge_List(void)
{
    cout<<"Edge     Ymin        Ymax           X               1/m"<<endl;
    for(int i=0;i<SIZE;i++)
    {
        cout<<i+1<<"         "<<Edge[i].ymin<<"           "<<Edge[i].ymax<<"           "<<Edge[i].xmin<<"          "<<Edge[i].inverse_slop<<endl<<endl;

    }
}

void FillUP(int ind,int s,double x_min,int y_min,int y_max)
{
    Edge[ind].sym=s;
    Edge[ind].xmin= (double)x_min;
    Edge[ind].ymin=y_min;
    Edge[ind].ymax=y_max;

}

void Create_EdgeList(void)
{
    int i,j, n;
    for(i=0;i<SIZE;i++)
    {
        if(i==SIZE-1)
            j=0;
        else
            j=i+1;

        if(Point[i].y==Point[j].y)
        {
            Edge[i].sym=0;
            continue;
        }

        if(Point[i].y<Point[j].y)
        {
            FillUP(i,1,Point[i].x,Point[i].y,Point[j].y);
        }
        else
        {
            FillUP(i,2,Point[j].x,Point[j].y,Point[i].y);
        }
        Edge[i].inverse_slop = (Point[j].x - Point[i].x) / (Point[j].y*1.0-Point[i].y*1.0)*1.0;
    }

    Print_Edge_List();
    return;

}
bool com(Edge_Structure a,Edge_Structure b)
{
	return a.xmin<b.xmin;
}
void Run_ScanLine_Operation(void)
{
    int i, j, n=0;
    int x1, y1, x2, y2;
    vector<Edge_Structure> E;
    for(i=Y_Minimum;  i<Y_Maximum;  i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(Edge[j].sym==0) continue;
            if(i==Edge[j].ymin)
                E.push_back(Edge[j]);

        }
        n=E.size();
        for(j=0;j<n;j++)
        {
            if(i==E[j].ymax)
            {
                E.erase(E.begin()+j);
                j--;
            }
        }

        n=E.size();
        sort(E.begin(), E.end(), com);
        for(j=0;j<n;j+=2)
        {
            x1=E[j].xmin;
            E[j].xmin=E[j].xmin+E[j].inverse_slop;
            y1=i;
            x2=E[j+1].xmin;
            E[j+1].xmin=E[j+1].xmin+E[j+1].inverse_slop;
            y2=i;
            DrawLine(x1,y1,x2,y2);

        }

    }

    return;

}
void display_ScanLine()
{
    glClear(GL_COLOR_BUFFER_BIT);       //It clears the whole window
    gluOrtho2D(-500,500,-350,350);      // Move the origin into the middle of the window....
    int i, j, m, n;
    int x1, y1, x2, y2;
    //Draw_BoundaryLines();
    Find_Minimum_And_Maximum_Y();
    Create_EdgeList();
    Run_ScanLine_Operation();

    //glFlush();
    glutSwapBuffers();
    return;
}
int main()
{
    cout<<"Region Filling Using Scan-Line Method"<<endl;
    //cout<<"SSSS"<<endl;
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); //Sets the initial Display mode. Glut_Double : It can use double buffer, GLUT_RGB: It can use RGB values as work, GLUT_Depth: It can select window with Depth buffer
    glutInitWindowSize(1000, 700);                         // Initialize window size: 1000 x 700 Pixels
    glutInitWindowPosition(100, 100);                       // Initial window position
    glutCreateWindow("Scan Line Algorithm");                // Initialize window title
    glClearColor(0,0,0,0.0);                                //clear the window with color black (RGB 0,0,0)

    glutDisplayFunc(display_ScanLine);                      //Call the function to display
    glutMainLoop();                                         // It normally keep active the window


    return 0;
}
