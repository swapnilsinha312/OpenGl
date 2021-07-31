#include<iostream>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<string>
#include <bits/stdc++.h>

using namespace std;

float x2,x1,y2,y1;
int m=0;
int flag=0,c=1;
const int maxx=20;
int top=-1;
struct Stack
{ string value="";};

Stack elem[maxx];

 float minX=-350;float minY=-150;
 float maxX=-300;float maxY=-100;

void InitGL()
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
}

void drawLine(float x0, float y0, float x1, float y1)
{   glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(x0, y0);glVertex2i(x1, y1);
	glEnd();
}

void drawRect(float x0,float y0,float x1,float y1)
{
    drawLine(x0,y0,x0,y1);
    drawLine(x0,y1,x1,y1);
    drawLine(x1,y1,x1,y0);
    drawLine(x1,y0,x0,y0);
}
void dispText(float x, float y,string str){
	 int len = str.length();
     char char_array[len + 1];
     strcpy(char_array, str.c_str());
     glRasterPos2f(x, y);
     for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, char_array[i]);
     }
     glEnd();
}

void disp_stack()
{
    int size= top+1;
    int fx1=minX; int fx2= maxX;
    int fy1= minY+size*50; int fy2= maxY+size*50;
    for(int i=0;i<size;i++)
        {   drawRect(minX,minY+i*50,maxX,maxY+i*50);
            dispText(minX+10,minY+i*50+10,elem[i].value);
        }
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
    minX+=60;maxX+=60;
}

void push(string x)
{ 	if(top<=maxx)
    { elem[++top].value= x;
    }
    else {cout<<"Stack is full"; dispText(0.0,0.0,"Stack is full");}
}

string pop(){
    if (top < 0){cout << "Stack Underflow";
                    return 0;
    }
    if(top==0) {dispText(0.0,0.0,"Empty");cout<<"empty ";top--;}
	else {string x = elem[top].value; elem[top--].value="";
		  return x;}
    }

void disp(){

    if(flag==0){
        glClear(GL_COLOR_BUFFER_BIT);
        dispText(-500,450,"Use Terminal for performing operations");
    }

if(c==1 || c==2){
    disp_stack();
    flag=1;
    cout<<"\nEnter\n"
        <<"1. To Push Element\n"
        <<"2. To Pop Element\n"
        <<"Anything Else to Exit\n";
    cin>>c;
    if(c==1){cout<<"Enter element ";string b;cin>>b;push(b);}
    else if(c==2){pop();}
        glEnd();
    }
    else {
        cout<<"You've chosen to exit";
        glEnd();
        Sleep(3000);
        exit(0);
    }

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutCreateWindow("Violet");
    glutInitWindowPosition(0,-300);
    glutInitWindowSize(800,600);
    glutReshapeWindow(800,600);
    glutDisplayFunc(disp);
    InitGL();
    glutMainLoop();

    return 0;
}
