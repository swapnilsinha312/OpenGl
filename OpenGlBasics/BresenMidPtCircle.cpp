#include<iostream>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>

using namespace std;
float cx,cy,r;

void InitGL()
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
}

void input_data()
{
cout<<"Enter the value of the x,y of the center of circle ";
cin>>cx;
cin>>cy;
cout<<"Enter the radius of inner circle ";
cin>>r;

}


void mid_point_circle(int cx,int cy,int r) {
	 glColor3f(1.0,1.0,1.0);
        float x = 0, y = r;
        float d = (5/4) - r;

        while(x < y)
        {
            x = x + 1;
            if(d < 0)
                d = d + (2 * x) + 3;
            else
            {
                y = y - 1;
                d = d + 2*(x - y) + 5;

            }
          glBegin(GL_POINTS);
          glVertex2i(cx+x, cy+y);
          glVertex2i(cx+x, cy-y);
          glVertex2i(cx+y, cy+x);
          glVertex2i(cx+y, cy-x);
          glVertex2i(cx-x, cy-y);
          glVertex2i(cx-y, cy-x);
          glVertex2i(cx-x, cy+y);
          glVertex2i(cx-y, cy+x);
          glEnd();
        }
}

void Bresenham_circle(int cx, int cy, int r)
    {
        glColor3f(1.0,0.0,0.0);
        float bx = 0, by = r;
        float p = 3 - 2*r;

        while(bx < by)
        {
            bx = bx + 1;
            if(p < 0)
                p = p + 4*bx+6;
            else
            {
                by = by - 1;
                p = p + 4*(bx - by) + 10;
            }
        glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(cx+bx, cy+by);
        glVertex2i(cx+bx, cy-by);
        glVertex2i(cx+by, cy+bx);
        glVertex2i(cx+by, cy-bx);
        glVertex2i(cx-bx, cy-by);
        glVertex2i(cx-by, cy-bx);
        glVertex2i(cx-bx, cy+by);
        glVertex2i(cx-by, cy+bx);

        glEnd();
        }
}
void disp()
{
    glClearColor (0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);


   // Bresenham_circle(cx,cy,r);
    mid_point_circle(cx,cy,r);
    glFlush();
}


int main(int argc, char ** argv)
{
input_data();
glutInit(&argc, argv);
glutCreateWindow("Violet");
glutInitWindowPosition(-100,-100);
glutInitWindowSize(800, 600);
glutReshapeWindow(800,800);
glutDisplayFunc(disp);
InitGL();
glutMainLoop();
return 0;
}


