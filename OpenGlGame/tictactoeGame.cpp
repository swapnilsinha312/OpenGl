#include <bits/stdc++.h>
using namespace std;
#include <windows.h>
#include <GL/glut.h>
#include <string>

// Made by Tanmay and Swapnil
int chance=1;
int chancewin=1;
int en=0;
int z[3][3]{{1,4,7},{2,5,8},{3,6,9}};
int pos[3][3]{0};
int prposy[3]={575,375,175};
int prposx[3]={175,375,575};
int winb=0;

void init(){
	glClearColor (0.0,0.0,0.0,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 800.0, 0.0, 800.0);
}
void dispText(float x, float y,string str){
	 int len = str.length();
     char char_array[len + 1];
     strcpy(char_array, str.c_str());
     glRasterPos2f(x, y);
     for (int i = 0; i < len; i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, char_array[i]);
     }
     glEnd();
}
void drawLine(int x0,int y0,int x1,int y1)
{
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
}

void win()
{
    for(int i=0;i<3;i++)
    {
        if(pos[i][1]==pos[i][0] && pos[i][1]==pos[i][2] && pos[i][2]!=0)
            {   winb=1; cout<<"Won(win)";
                drawLine(prposx[0],prposy[i],prposx[2],prposy[i]);
            }
        if(pos[0][i]==pos[1][i] && pos[1][i]==pos[2][i]&& pos[1][i]!=0)
            {
                winb=1; cout<<"Won(win)";
                drawLine(prposx[i],prposy[0],prposx[i],prposy[2]);
            }
    }
    if(pos[0][0]==pos[1][1] && pos[1][1]==pos[2][2]&& pos[2][2]!=0)
        {   winb=1;
            cout<<"Won(win)";drawLine(prposx[0],prposy[0],prposx[2],prposy[2]);
        }
    if(pos[1][1]==pos[2][0] && pos[1][1]==pos[0][2]&& pos[0][2]!=0)
        {   winb=1; cout<<"Won(win)";
            drawLine(prposx[2],prposy[0],prposx[0],prposy[2]);
        }
    glEnd();
}

void printInBox(int y,int x,int z)
{
    if(z==1)
        dispText(x,y,"X");
    if(z==2)
        dispText(x,y,"O");
}


void printpos()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(pos[i][j]!=0)
                printInBox(prposy[i],prposx[j],pos[i][j]);
            dispText(prposx[i]-70,prposy[j]-70,to_string(z[i][j]));
        }
    }
}

void frame()
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(100,100);glVertex2f(100,700);
    glVertex2f(700,700);glVertex2f(700,100);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(300,100);glVertex2f(300,700);
    glVertex2f(500,100);glVertex2f(500,700);
    glVertex2f(100,300);glVertex2f(700,300);
    glVertex2f(100,500);glVertex2f(700,500);
    glEnd();
    printpos();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void input(){
    en++;
    int ch;
    cout<<"Player"<<chance<<" : ";
    cin>>ch;
    chancewin=chance;
    if(ch==1){pos[0][0]=chance; }
    else if(ch==2){pos[0][1]=chance;  }
    else if(ch==3) {pos[0][2]=chance; }
    else if(ch==4) {pos[1][0]=chance; }
    else if(ch==5) {pos[1][1]=chance; }
    else if(ch==6) {pos[1][2]=chance; }
    else if(ch==7) {pos[2][0]=chance; }
    else if(ch==8) {pos[2][1]=chance; }
    else if(ch==9) {pos[2][2]=chance; }
    else {cout<<"Wrong Input, Terminated"; Sleep(3000);exit(0);}
    win();
    if(chance==1) chance =2; else chance=1;
}


void display(void)
{
    glClearColor (0.9,0.9,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    frame();
    input();
    frame();
    if(winb==1)
       {cout<<"Won by player "<<" "<<chancewin; glEnd(); Sleep(5000);  exit(0); }
    if(en==9)
        {cout<<"Match Drawn "; Sleep(5000);glEnd(); exit(0); }

}


int main(int argc,char *argv[]){
    cout<<"Welcome!\nThis is a Multiplayer TicTacToe Game\n";
    cout<<"The Input is as follows :-\nEvery Cell is assigned a No. , player have to input the No. of the cell to mark it.\n";
    cout<<"|1|2|3|\n";
    cout<<"|4|5|6|\n";
    cout<<"|7|8|9|\n\nGame Starts with the input of Player 1\nEnter Your Choice :-\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow ("TicTacToe");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
