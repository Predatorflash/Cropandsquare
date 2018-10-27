/****Header Files****/
#include <GL/glut.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
/***************************/









/*********prototypes************/
void init();
void display();
void BounceDisplay(void);
void gameover();
void startgame();
void initialize();
/**********************************/












/**** GLobal Variables****/
double spin = 0.5, scale = 0.8, scaleOffset = -0.005;
float tx = 90, ty = 67, dy = 0.1, dx =0.3, DIRspin = 5, HEXsize = 1;
int hex[13][2] = {{ 0,0 },{ 0,27 },{ 26,12},{26,-12},{ 0,-27},{-26,-12},{-26,12 },{-54,0 },{-24,51},{24,51 },{ 54,0 },{ 24,-51},{-24,-51}};
int Green[18] = {   0,1,9 , 0,2,10 , 0,3,11 , 0,4,12 , 0,5,7 , 0,6,8	};
int Purple[18]	= {	0,2,9 , 0,3,10 , 0,4,11 , 0,5,12 , 0,6,7 , 0,1,8	};
int up=390,down=30,left=30,right=390;
int i=0;
char str1[]="SRINIVAS INSTITUTE OF TECHNOLOGY";
char str2[]="COMPUTER GRAPHICS";
char str3[]="VISUALIZATION";
char str4[]="A MINIPROJECT ON THE SHRINK GAME";
char str5[]="  TEAM MEMBERS";
char str6[]=" AKASH NAMBIAR";
char str7[]="4SN12CS702";
char str8[]="SRIVATSA A RAO";
char str9[]=" 4SN12CS729";
char str10[]="PROJECT GUIDE";
char str11[]=" MR GURUDAS V R RAO";
char str12[]="Press F2 to continue";
char str13[]="You have cleared this Level..!! ";
char point1[]="Your point is 10";
char point2[]="Your point is 20";
char point3[]="Your point is 30";
char str14[]="Level 1";
char str15[]="Level 2";
char str16[]="Level 3";
char str17[]="You have Cleared this game !!!!";
char str18[]="GAME OVER";
char inistr1[]="Start Game";
char inistr2[]="Quit";

int z;
/*
|	tx,ty... Translate x,y
|	dx,dy... change in x,y
|	DIRspin is Direction of Spin. + or -
|	HEXsize determines Shrink or Grow.
|   Radius is  function that determines the radius of star.
|
|	Green and Purple specify order for drawing verticies, hex specifies
|	the verticies to draw.
*/
/*	HexTriangles() || Draws a green and Purple six pointed star...
*/
/****************************************/










/*****Here we draw the star*****/
void HexTriangles()
{
    int ii = 0, x = 0, y =0;
    double R = 1.0, G = 0.0, B= 0.0;
    glColor3d(R,G,B);
    glBegin(GL_TRIANGLES);
    for(ii = 0; ii < 18; ii++)
    {
        x = hex[Green[ii]][0];
        y = hex[Green[ii]][1];

        if(Green[ii] == 0)
        {
            glColor3d(0.0,0.0,0.0);
        }
        glVertex2i(x,y);
        R = B += 0.02;
        glColor3d(R,G,B);
    }
    R = 3.0;
    G = 0.0;
    B = 0.0;
    for(ii = 0; ii < 18; ii++)
    {
        x = hex[Purple[ii]][0];
        y = hex[Purple[ii]][1];

        if(Green[ii] == 0)
        {
            glColor3d(0.8,0.8,0.8);
        }
        glVertex2i(x,y);
        G += 0.02;
        glColor3d(R,G,B);
    }
    glEnd();


}
/******************************/












/*****************delay function*****************/
void delayy()
{
    int c = 1, d = 1;

    for ( c = 1 ; c <= 32767 ; c++ )
        for ( d = 1 ; d <= 32767 ; d++ )
        {}


}

/***********************************************/









/*************display text initial*********************/
void display1()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,50,0,50);
    glColor3f(0.2,2.0,0.0);
    glRasterPos2f(15.0,45.0);
    for(z=0; z<strlen(str1); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[z]);
    glRasterPos2f(20.0,35.0);
    for(z=0; z<strlen(str2); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[z]);
    glRasterPos2f(26.0,32.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'&');
    glRasterPos2f(22.0,29.0);
    for(z=0; z<strlen(str3); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str3[z]);
    glRasterPos2f(15.0,22.0);
    for(z=0; z<strlen(str4); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str4[z]);
    glRasterPos2f(3.0,12.0);
    for(z=0; z<strlen(str5); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str5[z]);
    glRasterPos2f(6.0,8.0);
    for(z=0; z<strlen(str6); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str6[z]);
    glRasterPos2f(8.0,6.0);
    for(z=0; z<strlen(str7); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str7[z]);
    glRasterPos2f(6.0,4.0);
    for(z=0; z<strlen(str8); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str8[z]);
    glRasterPos2f(8.0,2.0);
    for(z=0; z<strlen(str9); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str9[z]);
    glRasterPos2f(32.0,12.0);
    for(z=0; z<strlen(str10); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str10[z]);
    glRasterPos2f(34.0,8.0);
    for(z=0; z<strlen(str11); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str11[z]);
    glRasterPos2f(22,20);
    for(z=0; z<strlen(str12); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str12[z]);
    glFlush();
}
/************************************/











/******************Game over********************************/
void gameover()
{
    i=0;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glClearColor(0.0,0.8,0.7,0.0);
    glLineWidth(10);
    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0.45);
    glVertex2f(100,100);
    glColor3f(0,0.5,0.45);
    glVertex2f(450,100);
    glColor3f(0,0.5,0.45);
    glVertex2f(450,310);
    glColor3f(0,0.5,0.45);
    glVertex2f(100,310);
    glEnd();
    glColor3f(1,1,1);
    glRasterPos2f(220,200);
    for(z=0; z<strlen(str18); z++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str18[z]);
    glFlush();
    delayy();
    dy=0.1,dx=0.3;
    initialize();
    glutDisplayFunc(startgame);

}
/******************************************************/









/****Here we draw rectangle****/
void rectangle()
{
    glLineWidth(5.0);
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(left,down);
    glVertex2f(right,down);
    glVertex2f(right,up);
    glVertex2f(left,up);
    glEnd();
    glFlush();
}
/**************************************/















/** Reinitialization in the game**/

void initialize()
{
    up=390,down=50,left=50,right=390;
    rectangle();
    glFlush();
    glutPostRedisplay();

}
/**********************************/













/***************************start game********************************/
void startgame()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glClearColor(0,0,0,0.0);
    glColor3f(1,1,1);
    glRasterPos2f(150,250);
    for(z=0; z<strlen(inistr1); z++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,inistr1[z]);
    glRasterPos2f(150,200);
    glColor3f(1,1,1);
    for(z=0; z<strlen(inistr2); z++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,inistr2[z]);
    glFlush();


}
/***********************************************************************/






















/**********************display message after complete **********************/
void display2()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glClearColor(0.0,0.8,0.7,0.0);
    glLineWidth(10);
    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0.45);
    glVertex2f(100,100);
    glColor3f(0,0.5,0.45);
    glVertex2f(450,100);
    glColor3f(0,0.5,0.45);
    glVertex2f(450,310);
    glColor3f(0,0.5,0.45);
    glVertex2f(100,310);
    glEnd();
    glColor3f(1,1,1);


    switch (i)
    {
    case 0:
    {
        glRasterPos2f(220,200);
        for(z=0; z<strlen(str14); z++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str14[z]);
        glFlush();
        i++;
        delayy();
        glutDisplayFunc(display);
        break;
    }
    case 1:
    case 3:
    {
        glRasterPos2f(200,200);
        i++;
        for(z=0; z<strlen(str13); z++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str13[z]);
        glFlush();
        display2();
        break;
    }
    case 2:
    {
        delayy();
        glRasterPos2f(220,200);
        for(z=0; z<strlen(str15); z++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str15[z]);
        glFlush();
        i++;
        delayy();
        for(z=0; z<strlen(point1); z++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,point1[z]);
        glFlush();
        delayy();
        dx=0.6;
        dy=0.9;
        initialize();
        glutDisplayFunc(display);
        break;
    }
    case 4:
    {
        delayy();
        glRasterPos2f(220,200);
        for(z=0; z<strlen(str16); z++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str16[z]);
        glFlush();
        delayy();
        for(z=0; z<strlen(point2); z++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,point2[z]);
        glFlush();
        delayy();
        i++;
        dx=2;
        dy=3;
        initialize();
        glutDisplayFunc(display);
        break;
    }
    case 5:
    {
        glRasterPos2f(220,200);
        for(z=0; z<strlen(str17); z++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str17[z]);
        glFlush();
        delayy();
        glRasterPos2f(220,200);
        for(z=0; z<strlen(point3); z++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,point3[z]);
        glFlush();
        delayy();
        i=0;
        initialize();
        glutDisplayFunc(startgame);
    }
    }
}

/******************************************************/









/***Calculate area****/
void area()
{
    int areaa,length,breadth;
    length=up-down;
    breadth=right-left;
    areaa=length*breadth;
    if (areaa<30000)
    {

        glutDisplayFunc(display2);
    }
}
/**********************************/









/****Here we use display function to display ***/
void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT);
    glPushMatrix(); /* Put onto matrix stack */
    glTranslatef(tx,ty,0); /* Move to/from tx,ty */
    glRotatef(spin, 0.0, 0.0, 1.0); /* rotate about z axis by spin degrees */
    glScalef(scale, scale, 0.0);/* shrink or grow by scale in x,y */
    HexTriangles(); /* now draw the pixels */
    glPopMatrix();/* take off of stack*/
    rectangle();
    glutSwapBuffers(); /* swap drawn w/ shown */
}
/**************************/





















/******BounceDisplay || The Idle Function. and bouncing function.COllision Detection ******/

void BounceDisplay(void)
{
    /*
    | Deflect off of the walls by the amount you|
    | exceeded each wall, angles will take care of themselves...
    |the individual x or y intercepts need to be
    | calculated... the new position will
    | intrinsically be the vector sum of the dx,dy |
    | vectors.
    */

    int Radius = 54;


    if(HEXsize < 100)
    {
        scale += scaleOffset; /* grow/shrink by offset */
        HEXsize++;
    }


    else
    {
        HEXsize = 0;/* Reset loop*/
        scaleOffset *= -1; /* Flip grow/shrink */
    }
    Radius *= scale;
    /* Radius must be in scale too. */


    if(DIRspin < 0)
    {
        spin = spin - 2.0; /* ClockWise*/
    }


    else
    {
        spin = spin + 2.0; /* CounterClockWise */
    }


    if(spin > 360.0)
    {
        spin = spin - 360.0; /* Keep small */
    }


    if(spin < -360.0)
    {
        spin = spin + 360.0;
    }
    tx += dx; /* Move center over */
    ty += dy; /* by dx,dy (applied by translation) */

//collision dection and handling
    if((tx + Radius) >right)
    {
        DIRspin *= -1;				/* reverse spin! */
        dx*= -1;/* reverse dx!*/
        tx -= (tx + Radius) - right; /* !
                                        		center moved -change
                                        		left over from dx */
    }


    if((tx - Radius-left)< 0)
    {
        DIRspin *= -1;
        dx*= -1;
        tx += -1 * (tx - Radius-left); /*  !
                                            		The object is deflected by the amount it exceeded
                                            		the lower bound... no  angles.
                                            		AND no popping about. ie:
                                            		the object appears to move at constant speed.
                                            		*/
    }


    if((ty + Radius) > up)
    {
        DIRspin *= -1;
        dy *= -1;
        ty -= (ty + Radius) - up; /* ! same as dx */
    }


    if ((ty - Radius-down) <0)
    {
        DIRspin *= -1;
        dy *= -1;
        ty += -1 * (ty - Radius-down); /* ! same as dx */
    }
    glutPostRedisplay();/*redraw everything */
}
/*******************************/














/**********init() || GL initialization..*********/
void init (void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 600, 0, 400, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}
/******************************/















/**mouse() **/

void mouse(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {

        if(x>=312 && x<=432 && y>=255 && y<=290)
        {


            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            init();
            glFlush();
            glutDisplayFunc(display2);

        }
        else if(x>=301 && x<=386&& y>=346 && y<=390)
            exit(0);
    }
}
/**************************************************/
















/***********The keyboard function which is used to control the rectangle***************/
void keyboard(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
    {
        if((tx - 54-left)< 0)
        {
            gameover();
            //initialize() ;//initialise again
        }
        glLoadIdentity();
        left+=7;
        rectangle();
        glFlush();
        break;
    }
    case GLUT_KEY_UP:
    {
        if((ty + 54) > up)
        {
            gameover();
            //initialize() ;//initialise again
        }

        glLoadIdentity();
        up-=7;
        rectangle();
        glFlush();

        break;
    }
    case GLUT_KEY_RIGHT:
    {
        if((tx + 54) >right)
        {
            gameover();
            //initialize() ;//initialise again

        }
        glLoadIdentity();
        right-=7;
        rectangle();
        glFlush();
        break;
    }
    case GLUT_KEY_DOWN:
    {
        if ((ty - 54-down) <0)
        {
            gameover();
            //initialize() ;//initialise again
        }
        glLoadIdentity();
        down+=7;
        rectangle();
        glFlush();
        break;
    }//for start press f2
    case GLUT_KEY_F2:
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        init();
        glFlush();
        glutDisplayFunc(startgame);
    }
    default:
        break;
    }

    area();//call area function

//--redraw
    glutPostRedisplay();
}

/***************************************/












/** main function **/

int main(int argc, char** argv)
{
    glutInit(&argc, argv);//init
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);//specify display mode
    glutInitWindowSize (1366, 768);//init window size
    glutInitWindowPosition (100, 100);//position of the window
    glutCreateWindow ("mini project game");//give title
    init();//call init
    glutDisplayFunc(display1);//call display function
    glutIdleFunc(BounceDisplay);//this is the idle func.i.e, function will be running all the time
    glutSpecialFunc(keyboard);//this is a function which is used for arrow keys
    glutMouseFunc(mouse);//its the mouse function
    glutMainLoop();//call the main screen..its like getch function
    return 0;//return value
}
/*********************************/


