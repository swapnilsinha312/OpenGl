#include<iostream>
#include<windows.h>
#include<GL/glut.h>


using namespace std;
int x1,y1,x2,y2;

void InitGL()
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
}

void input_data()
{
cout<<"Enter the initial point";
cin>>x1;
 cin>>y1;
cout<<"Enter the end point";
cin>>x2;
 cin>>y2;

}

void disp()
{

glClearColor (0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;
	dx = x2-x1;
	dy = y2-y1;
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1;
	y = y1;

if (dx > dy) {

		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;

for (i=0; i<dx; i++)
    {
        if (e >= 0) {
            y += incy;
            e += inc1;
        }
        else
            e += inc2;

    x += incx;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    }

	}
else {
        e = 2*dx-dy;

    inc1 = 2*(dx-dy);
    inc2 = 2*dx;
    for (i=0; i<dy; i++) {
        if (e >= 0) {
            x += incx;
            e += inc1;
        }
        else
            e += inc2;
        y += incy;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
		}
	}
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
InitGL();
glutMainLoop();
return 0;
}

