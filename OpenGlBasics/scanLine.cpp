#include<iostream>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>

using namespace std;


void InitGL()
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
}

int a;

void input_data1()
{
int s;
cout<<"Enter the number of sides ";
cin>>s;
a=s;
}
const int size=a;

int pts[2][size];

void input_data2()
{
    for(int i=0;i<size;i++)
    {
        cin>>pts[i][0];
        cin>>pts[i][1];
    }
}


void line(float x1,float y1,float x2,float y2)
{
    cout<<x1;
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd( );


}

void disp()
{
    cout<<"pt";
    glClearColor (0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    line(100,100,200,200);
    glFlush();



}


int main(int argc, char ** argv)
{
input_data1();
input_data2();
glutInit(&argc, argv);
glutCreateWindow("Violet");
glutInitWindowPosition(-100,-100);
glutInitWindowSize(800, 600);
glutReshapeWindow(800,600);
glutDisplayFunc(disp);
InitGL();
glutMainLoop();
return 0;
}

