#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
using namespace std;

float itri[3][2];
float ctri[3][2];
int ch;
int angle=45;
int sx=0,sy=0;
float tx=0,ty=0;

void input_data()
{
cout<<"Enter 1 for rotating, 2 for translating, and 3 for scaling ";
cin>>ch;
if(ch==1){cout<<"Enter angle ";cin>>angle;}
if (ch==2){cout<<"Enter scaling factor for x and y coordinates(int) ";cin>>sx>>sy;}
if (ch==3){cout<<"Enter scaling factor for x and y coordinates (float) ";cin>>tx>>ty;}
}

void init()
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);

}


void line(float x1,float y1,float x2,float y2)
{

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd( );
}

void print(float a[3][2])
{
    glColor3f(1.0, 1.0, 0.0);
    for(int i=0;i<3;i++)
    {
        if (i==2) line(a[i][0],a[i][1],a[0][0],a[0][1]);
        else line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    }

}

void aa(float tx, float ty)
{
    glColor3f(1.0, 1.0, 0.0);
     for(int i=0;i<3;i++)
    {
        ctri[i][0]= itri[i][0]+tx;
        ctri[i][1]= itri[i][1]+ty;
    }
    print(ctri);

}

void aa(int tx,int ty)
{
    glColor3f(1.0, 1.0, 0.0);
     for(int i=0;i<3;i++)
    {
        ctri[i][0]= itri[i][0]*tx;
        ctri[i][1]= itri[i][1]*ty;
    }
    print(ctri);
}

void aa(float A)
{

    int i; float d;
    d = (float)(3.14*d/180);
    A=A*d;

    for(i=0;i<3;i++)
    {
        ctri[i][0] = itri[i][0]*cos(A) - itri[i][1]*sin(A);
        ctri[i][1]= itri[i][0]*sin(A)+ itri[i][1]*cos(A);
    }
    print(ctri);
}

void disp()
{
    glClearColor (0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

    //original Figure
    itri[0][0] = 0; itri[0][1] = 0; itri[1][0] = 0; itri[1][1] = 100; itri[2][0] = 100; itri[2][1] = 0;
    print(itri);
    if(ch==1)aa(angle);
    if(ch==2)aa(sx,sy);
    if(ch==3)aa(tx,ty);
    glFlush();
}

int main(int argc, char ** argv)
{
input_data();
glutInit(&argc, argv);
glutCreateWindow("Violet");
glutInitWindowPosition(-100,-100);
glutInitWindowSize(800, 600);
glutReshapeWindow(800,600);
glutDisplayFunc(disp);
init();
glutMainLoop();
return 0;
}
