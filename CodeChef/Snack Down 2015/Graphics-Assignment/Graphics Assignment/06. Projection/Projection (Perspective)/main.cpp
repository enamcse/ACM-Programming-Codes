#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>

using namespace std;

//void getV();
void Matrix_Mult(int a1[][4], int a2[][8]);
void drawLine(int a1,int b1,int a2,int b2);
void drawPolygon( float a1, float b1, float a2, float b2, float a3, float b3, float a4, float b4 );
static void display();

//int invMat[8][3]={{100,100,100},{300,100,100},{300,300,100},{100,300,100},{100,300,300},{100,100,300},{300,100,300},{300,300,300}};
//int invMat[8][3]={{0,0,0},{1,0,0},{1,1,0},{0,1,0},{0,1,1},{0,0,1},{1,0,1},{1,1,1}};
int distVar = 50;


int vMat[4][8] = {{50,150,150,50,50,50,150,150},{50,50,150,150,150,50,50,150},{50,50,50,50,150,150,150,150},{1,1,1,1,1,1,1,1}};
int persMat[4][4] = {{distVar,0,0,0},{0,distVar,0,0},{0,0,0,0},{0,0,1,distVar}};
int resMat[4][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
float finalMat[8][2];


int main(int argc, char *argv[])
{
    cout<<"This is Perspective  Projection Example"<<endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Perspective Projection");
    glClearColor(0.0, 0.0, 0.0, 10); // SET THE BACKGROUND BLACK
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}









static void display(void){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f((640/2), 0);
    glEnd();

//Y-axis
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(0,(640/2));
    glEnd();

//z-axis
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(-(640/2), -(480/2));
    glEnd();
    Sleep(10);

    glColor3f(0.5,1,0);
    glBegin(GL_POINTS);
    glVertex2f(-distVar, 0.0);
    glEnd();


    //getV();
    Matrix_Mult(persMat, vMat);

    for ( int i = 0; i < 8; i++ ) {
        for ( int j = 0; j < 2; j++ ){
            finalMat[i][j] = (float)resMat[j][i]/resMat[3][i];
        }
    }

   //glColor3f(0,0,1);
   // drawPolygon( vMat[0][0], vMat[0][1], vMat[0][1], vMat[1][1], vMat[0][2],vMat[1][2], vMat[0][3], vMat[1][3] );
  /*  glColor3f(0,0,1);
    drawPolygon( finalMat[4][0], finalMat[4][1], finalMat[5][0], finalMat[5][1], finalMat[6][0], finalMat[6][1], finalMat[7][0], finalMat[7][1] );

    drawLine( finalMat[0][0], finalMat[0][1], finalMat[5][0], finalMat[5][1] );
    drawLine( finalMat[1][0], finalMat[1][1], finalMat[6][0], finalMat[6][1] );
    drawLine( finalMat[2][0], finalMat[2][1], finalMat[7][0], finalMat[7][1] );
    drawLine( finalMat[3][0], finalMat[3][1], finalMat[4][0], finalMat[4][1] );

*/
    ///drawing front points from vMat[0] to vMat[3]
    drawLine( vMat[0][0], vMat[1][0], vMat[0][1], vMat[1][1] );
    drawLine( vMat[0][1], vMat[1][1], vMat[0][2], vMat[1][2] );
    drawLine( vMat[0][2], vMat[1][2], vMat[0][3], vMat[1][3] );
    drawLine( vMat[0][3], vMat[1][3], vMat[0][0], vMat[1][0] );
///finding the distance of front view and back view : sqrt((x1-x2)*(x1-x2))/2
///here x1 and x2 are z1 and z2
   int cube_distance = (int)(sqrt((abs(vMat[2][0] - vMat[2][7]) * abs(vMat[2][0] - vMat[2][7])) +(abs(vMat[2][0] - vMat[2][7]) * abs(vMat[2][0] - vMat[2][7]))) / 2);
///drawing fron points from vMat[3] to vMat[7]
    drawLine( vMat[0][4]+cube_distance, vMat[1][4]+cube_distance, vMat[0][5]+cube_distance, vMat[1][5]+cube_distance);
    drawLine( vMat[0][5]+cube_distance, vMat[1][5]+cube_distance, vMat[0][6]+cube_distance, vMat[1][6]+cube_distance);
    drawLine( vMat[0][6]+cube_distance, vMat[1][6]+cube_distance, vMat[0][7]+cube_distance, vMat[1][7]+cube_distance );
    drawLine( vMat[0][7]+cube_distance, vMat[1][7]+cube_distance, vMat[0][4]+cube_distance, vMat[1][4]+cube_distance );


    ///joining corner lines of two objects to get a 3D view
    drawLine( vMat[0][0], vMat[1][0], vMat[0][5]+cube_distance, vMat[1][5]+cube_distance);
    drawLine( vMat[0][1], vMat[1][1], vMat[0][6]+cube_distance, vMat[1][6]+cube_distance);
    drawLine( vMat[0][2], vMat[1][2], vMat[0][7]+cube_distance, vMat[1][7]+cube_distance);
    drawLine( vMat[0][3], vMat[1][3], vMat[0][4]+cube_distance, vMat[1][4]+cube_distance);



    glColor3f(0.5,1,0);
    drawPolygon( finalMat[0][0], finalMat[0][1], finalMat[1][0], finalMat[1][1], finalMat[2][0], finalMat[2][1], finalMat[3][0], finalMat[3][1] );
    glColor3f(1,0,1);
   drawPolygon( finalMat[4][0], finalMat[4][1], finalMat[5][0], finalMat[5][1], finalMat[6][0], finalMat[6][1], finalMat[7][0], finalMat[7][1] );

    drawLine( finalMat[0][0], finalMat[0][1], finalMat[5][0], finalMat[5][1] );
    drawLine( finalMat[1][0], finalMat[1][1], finalMat[6][0], finalMat[6][1] );
    drawLine( finalMat[2][0], finalMat[2][1], finalMat[7][0], finalMat[7][1] );
    drawLine( finalMat[3][0], finalMat[3][1], finalMat[4][0], finalMat[4][1] );

    glFlush();
}


/*void getV(){
    for(int i=0;i<3;i++){
        for(int j=0;j<8;j++){
            vMat[i][j] = invMat[j][i];
        }
    }
}*/

void Matrix_Mult(int a1[][4], int a2[][8]) {
   int i = 0;
   int j = 0;
   int k = 0;
       for(i = 0; i < 4; i++)
           for( j = 0; j < 8; j++)
               for( k = 0; k < 4; k++)
                   resMat[i][j] +=  a1[i][k] * a2[k][j];
}

void drawLine(int a1,int b1,int a2,int b2){
    double x = 640/(double)2.0;
    double y = 480/(double)2.0;

    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2f(a1/x,b1/y);
        glVertex2f(a2/x,b2/y);
    glEnd();

}


void drawPolygon( float a1, float b1, float a2, float b2, float a3, float b3, float a4, float b4 ){
    double x = 640/(double)2.0;
    double y = 480/(double)2.0;

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_POLYGON);
        glVertex2f(a1/x,b1/y);
        glVertex2f(a2/x,b2/y);
        glVertex2f(a3/x,b3/y);
        glVertex2f(a4/x,b4/y);
    glEnd();
}

