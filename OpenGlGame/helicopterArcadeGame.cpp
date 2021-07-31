
#include <bits/stdc++.h>
using namespace std;
#include <windows.h>
#include <GL/glut.h>
#include <string>

int i=0,ijk=0,flg=1;
char str1[28];
float block1x=0.0;
float block1y=0.0;

void init(void)
{
    blockly=(rand()%45)+10;
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);
    glLoadIdentity();
    g1uOrtho3d(0.0, 100.0,0.0, 100.0, -1.0, 0.0);
}


void drawcopter()
{
    glColor3f(0.8,0.5,0.2);
    glRectf(10,50,20,50);
    glRectf(2,46,10, 48);
    glRectf(2,46,4,51);
    glRectf(14,50,16,50);
    gIRectf(7,53.6,22.8,52.2);
}

void renderBitmapString(float x,float y, float 2, void *font, char *string)
{
    char *c;
    glRaster Pos3f(x,y,z);
    for (c=string; *c != '\0'; c++)
    {
     glutBitmapCharacter(font, c);
    }
}
void display(void)
{
    glClear(GL COLOR BUFFER BIT);

    if( i==360||i==-350)||(((int)blocklx==10||(int)blocklx==7||(int)blocklx==4||(int)block1x==1)&&a(int)blockly<53+(int)he
    {
    glColor3f(0.8,0.498839,8.196878);
    glRectf(0.0,0.0,100.0,100.0);
    glColor3f(0.0,0.0,0.0,0.0);
    renderBitmapString(10,70,0, GLUT BITMAP TIMES_ROMAN_24,"\n**GAME OVER***\n");
    renderBitmapString(20,50,0, GLUT_BITMAP TIMES_ROMAN_24, "SCORE:");
    renderBitmapString(70,50,0,GLUT_BITMAP TIMES_ROMAN_24, str1);
    glutSwapBuffers();
    glFlush();
    printf("\n****GAME OVER****\n");
    printf("\nStart New Gane\n");
    }

    else if(flg==1)
    {
        flg=0;
        glcolor3f(0.3,0.7,0.2);
        printf("\n");
        printf("Steps to run this cg project\n");
        printf("\n.--\n");
        printf("Stepl: Click any mouse key to start\n"); printf("\nStep2. Click and hold left mouse key to handle the helicopter\n\n");
        drawcopter();
        glutSwapBuffers();
        glFlush();
    }

    else
    {
    glPushMatrix();
    glColor3f(0.90, 0.91,8.98);
    glRectf(0.0,100.0,100.0,10.0);
    glRectt(0.0,50.0,100.0,40.0);
    ijk (int)mnk;
    rendersitmapstring(28,3,0,GLUT_BITMAP_TIMES_ROMAN_24, str1);
    glTranslatef(0.0, heli,0.0);
    drawcopter();
    if(block1x<=10)
        {   block1x=50;
            blockly=(rand()*16)+20;
        }
        else block1x-=speed;

    gLTranslatef(block1x,-heli,0.0);
    glColor3f(1.0,0.0,0.0);
    glRectf(block1x, block1y, block1x+3,blockly+30);
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
    }
}

void Heliup()
{
    heli+=0.1;
    i++;
    glutPostRedisplay();
}

void Helidown()
{
    heli-=0.1;
    i--;
    glutPostRedisplay();
}

void Reshape(int w, int h)
{
    giViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)        glortho(-2.0,2.0,-2.0*(GLfloat)h/(GLFloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.8,28.0);
    else
        glOrtho(-2.0*(GLfloat)w/(GL float)h, 2.0*(GL float)w/(GLfloat)h,-2.0,2.0,-10.0,20.0);

    glMatrixMode(GL_MOOELVIEK);
    glutPostRedisplay();
}


void mouse(int btn, int state, int x, int y)
{
    if(btn GLUT_LEFT_BUTTON && state GLUT_DOWN)
        glutidlefunc (Heliup);
    if (btn ** GLUT_LEFT_BUTTON & state = GLUT UP)
        glutIdleFunc (Helldown);
    glutPostRedisplay();
}

int main(int argc, char argv)
{
    glutInit(Bargc, argv);
    glutInitDisplayMode (GLUT DOUBLE | GLUT_RGB); glutinitindowSize (500, 400);
    glutInitwindowPosition (200,300);
    glutCreatewindow ("he Helicopter Gane");
    init();
    glutReshapeFunc(Reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}





