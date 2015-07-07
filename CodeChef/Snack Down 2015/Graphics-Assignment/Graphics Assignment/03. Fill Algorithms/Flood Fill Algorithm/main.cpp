#include<graphics.h>
#include<windows.h>
//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include <GL/glut.h>
//#endif
//#include <stdlib.h>
//#include<stdio.h>
#include<iostream>
//#include<math.h>
//#include<string.h>
using namespace std;


int xx[]={-1,1, 0, 0};
int yy[]={ 0,0,-1, 1};


void Flood_Fill(int x, int y, int FC, int OC)
{
    int Current_Color;
    Current_Color = getpixel(x, y);

    if(Current_Color==OC)
    {
        putpixel(x, y, FC);
        //delay(1);
        for(int i=0;i<4;i++)
        {
            Flood_Fill(x+xx[i], y+yy[i], FC, OC);
        }

    }
    return;
}
void Show_Identity(void)
{
    outtextxy(10, 10, "Name: Rajib Chandra Das");
    outtextxy(10, 30, "Reg : #2009331008");
    outtextxy(10, 100, "Now, I am Implementing Flood Fill Algorithm........");
}

void display(void)
{
    int Fill_Color, boundary_color, Operation_Color;
    int x, y;
    boundary_color = 7; //White Color = 7
    setcolor(boundary_color);
    x=280;
    y=300;
    Show_Identity();



    circle(x, y, 40);
    Fill_Color = 4;     //Red color = 4
    Operation_Color = getpixel(x, y);
    Flood_Fill(x, y, Fill_Color, Operation_Color);

    rectangle(200,250,350,350);
    Fill_Color = 2;         //Green Color = 2
    Operation_Color = getpixel(205,255);
    Flood_Fill(205,255,Fill_Color, Operation_Color);

    rectangle(190, 250, 200, 500);
    Fill_Color = 5;         //Pink Color = 5
    Operation_Color = getpixel(195,255);
    Flood_Fill(195,255,Fill_Color, Operation_Color);

    outtextxy(200, 550, "Diagram: Our National Flag");

    return;

}




int main(int argc, char *argv[])
{
    initwindow(1000,700, "Flood Fill Algorithm");
    display();
    system("PAUSE");
    return EXIT_SUCCESS;
}

