#include<graphics.h>
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
#include<string.h>
using namespace std;


int xx[]={-1,1, 0, 0};
int yy[]={ 0,0,-1, 1};


void Boundary_Fill(int x, int y, int FC, int BC)
{
    int Current_Color;
    Current_Color = getpixel(x, y);

    if(Current_Color!=FC&&Current_Color!=BC)
    {
        putpixel(x, y, FC);
        delay(1);
        for(int i=0;i<4;i++)
        {
            Boundary_Fill(x+xx[i], y+yy[i], FC, BC);
        }

    }
    return;
}
void Show_Identity(void)
{
    outtextxy(10, 10, "Name: Rajib Chandra Das");
    outtextxy(10, 30, "Reg : #2009331008");
    outtextxy(10, 100, "Now, I am Implementing Boundary Fill Algorithm........");
}
void display(void)
{
    int Fill_Color, boundary_color;
    int x, y;
    boundary_color = 7; //White Color = 7
    setcolor(boundary_color);
    Show_Identity();
    x=280;
    y=300;
    circle(x, y, 40);
    Fill_Color = 4;     //Red color = 4
    Boundary_Fill(x, y, Fill_Color, boundary_color);

    setcolor(5);
    rectangle(200,250,350,350);
    Fill_Color = 2;         //Green Color = 2
    Boundary_Fill(205,255,Fill_Color, 5);

    rectangle(190, 250, 200, 500);
    Fill_Color = 5;         //Pink Color = 5
    Boundary_Fill(195,255,Fill_Color, boundary_color);
    outtextxy(200, 550, "Diagram: Our National Flag");
    return;

}




int main(int argc, char *argv[])
{
    initwindow(1000,700, "Boundary Fill Algorithm");
    display();
    system("PAUSE");
    return EXIT_SUCCESS;
}

