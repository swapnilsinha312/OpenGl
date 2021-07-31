#include<iostream>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;

float x2,x1,y2,y1;
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const float minX=0;
const float minY=0;
const float maxX=300;
const float maxY=300;

void InitGL()
{
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500,500,-500,500);
}

void drawLine(float x0, float y0, float x1, float y1){
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
}

int position(GLfloat x, GLfloat y){
    int code = INSIDE;
    if (x < minX)
        code |= LEFT;
    else if (x > maxX)
        code |= RIGHT;
    if (y < minY)
        code |= BOTTOM;
    else if (y > maxY)
        code |= TOP;
    return code;
}


void clipping()
{
	int code1 = position(x1, y1);
	int code2 = position(x2, y2);

	bool accept = false;

	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
			accept = true;
			break;
		}
		else if (code1 & code2) {
			break;
		}
		else {
			int code_out;
			double x, y;

			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			if (code_out & TOP) {
				x = x1 + (x2 - x1) * (maxY- y1) / (y2 - y1);
				y = maxY;
			}
			else if (code_out & BOTTOM) {
				x = x1 + (x2 - x1) * (minY- y1) / (y2 - y1);
				y = minY;
			}
			else if (code_out & RIGHT) {

				y = y1 + (y2 - y1) * (maxX- x1) / (x2 - x1);
				x = maxX;
			}
			else if (code_out & LEFT) {

				y = y1 + (y2 - y1) * (minX- x1) / (x2 - x1);
				x = minX;
			}

			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = position(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = position(x2, y2);
			}
		}
	}
	if (accept)
        drawLine(x1+150,y1,x2+150,y2);
    else
		cout << "Can not make line";
}



void frame(float fx1,float fy1,float fx2,float fy2)
{
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(fx1,fy1); glVertex2f(fx1,fy2);
    glVertex2f(fx2,fy2); glVertex2f(fx1,fy2);
    glVertex2f(fx2,fy2); glVertex2f(fx2,fy1);
    glVertex2f(fx1,fy1); glVertex2f(fx2,fy1);
}

void disp(){
    glLineWidth(4.0);
	glClear(GL_COLOR_BUFFER_BIT);
    frame(minX-350,minY,maxX-350,maxY);
    frame(minX+150,minY,maxX+150,maxY);
	glColor3f(1.0, 0.0, 0.0);
    drawLine(x1-350, y1,x2-350,y2);
    clipping();

	glFlush();
}

int main(int argc, char** argv)
{



	cout << "Enter co-ordinates of first point of line: "; cin >> x1>> y1;
	cout << "Enter co-ordinates of second point of line: "; cin >> x2>> y2;

	glutInit(&argc, argv);
    glutCreateWindow("Violet");
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000, 1000);
    glutReshapeWindow(1000,1000);
    glutDisplayFunc(disp);
    InitGL();
    glutMainLoop();
    return 0;

}

