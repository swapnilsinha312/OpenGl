#include <bits/stdc++.h>
using namespace std;
#include <windows.h>
#include <GL/glut.h>
#include <string>

int iter=3;
int minX,minY,maxX,maxY;
int angle=60*(22/7)/180;

void init(){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}

void drawLine(int x0,int y0,int x1,int y1)
{
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
}

void kochCurve(float x0, float y0, float x1, float y1, float n)
{
    float x2 = ((2*x0)+x1)/3;
    float y2 = ((2*y0)+y1)/3;
    float x3 = ((2*x1)+x0)/3;
    float y3 = ((2*y1)+y0)/3;

    float x = x2 + ((x3-x2)*cos(angle)) + ((y3-y2)*sin(angle));
    float y = y2 - ((x3-x2)*sin(angle)) + ((y3-y2)*cos(angle));

    if(n>0){
        kochCurve(x0,y0,x2,y2,n-1);
        kochCurve(x2,y2,x,y,n-1);
        kochCurve(x,y,x3,y3,n-1);
        kochCurve(x3,y3,x1,y1,n-1);
    }
    else{
        drawLine(x0,y0,x3,y3);
        drawLine(x,y,x2,y2);
        drawLine(x,y,x3,y3);
        drawLine(x3,y3,x1,y1);
        glEnd();
    }

glFlush();
}

void display(void)
{
    glClearColor (0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    minX=maxX=-450;minY==-400;maxY=400;
    for(int i=0;i<5;i++)
    {
        kochCurve(minX,minY,maxX,maxY,i);
        minX+=200;maxX+=200;
    }
    glEnd();
    glFlush();
}


int main(int argc,char *argv[]){

glutInit(&argc, argv);
glutCreateWindow("Violet");
glutInitWindowPosition(-100,-100);
glutInitWindowSize(800, 600);
glutReshapeWindow(800,600);
glutDisplayFunc(display);
init();
glutMainLoop();
return 0;
}
