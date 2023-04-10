/*
Name: Shazzad Hossen
ID; 191-15-2420
Department of CSE
Daffodil International University
Email: shazzad15-2420@diu.edu.bd
*/
#include <windows.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
float pos=-1.0;
int fast=25;
float theta;
int change=1;
float mov=0.0,movb=0.0;

int skyx=135, skyy=206, skyz=255,lx=41,ly=41,lz=41,smx=255,smy=215,smz=0;

using namespace std;




void handleKeypress(int key, int x, int y)

{

    if(change==1)
    {
        switch (key)
        {
        case GLUT_KEY_RIGHT:
            pos=-1.0;
            break;
        case GLUT_KEY_LEFT:
            pos=1.0;
            break;

        case GLUT_KEY_UP:
            if(fast==0)
            {

                break;
            }
            else
                fast--;
            break;
        case GLUT_KEY_DOWN:
            fast++;
            break;

        }


    }
    else if(change==0)
    {
        switch (key)
        {
        case GLUT_KEY_RIGHT:
            mov+=0.1;
            break;
        case GLUT_KEY_LEFT:
            mov-=0.1;
            break;


        }


    }
    else if(change==2)
    {

        switch (key)
        {
        case GLUT_KEY_RIGHT:


            movb+=0.1;
            break;
        case GLUT_KEY_LEFT:
            if(movb==-0.5)
            {

                movb=-0.5;
            }
            else
                movb-=0.1;
            break;


        }


    }




}

void processNormalKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        fast=-1;
        break;

    case 'n':
        skyx=96 ;
        skyy=123 ;
        skyz=139 ;
        lx=255;
        ly=255;
        smx=255;
        smy=255;
        smz=255;

        break;
    case 'd':
        skyx=135;
        skyy=206;
        skyz=255;
        lx=41;
        ly=41;
        smx=255;
        smy=215;
        smz=0;
        break;

    case 'w':
        change=1;
        break;
    case 'c':
        change=0;
        break;
    case 'b':
        change=2;
        break;




    }
}



void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL); //Enable color
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f); //Change the background to sky blue
}


void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0f;
float _cameraAngle = 0.0f;


void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);



    glClearColor(184.0f, 213.0f, 238.0f, 1.0f);



//WindMill_Propeller
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glScalef(0.5,0.5,0);

    glRotatef(_angle, 0.0f, 0.0f, pos);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);


    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glVertex3f(-0.5f, 1.0f, 0.0f);


    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -0.5f, 0.0f);
    glVertex3f(0.5f, -1.0f, 0.0f);


    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -0.5f, 0.0f);
    glVertex3f(-0.5f, -1.0f, 0.0f);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.5f, 0.0f);
    glVertex3f(0.5f, 1.0f, 0.0f);

    glEnd();
    glPopMatrix();









// windmill_pillar

    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glScalef(0.4,0.4,0);

    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.25f, -1.0f, 0.0f);
    glVertex3f(-0.25f, -1.0f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(0.25f, -1.0f, 0.0f);
    glVertex3f(0.25f, -3.0f, 0.0f);
    glVertex3f(-0.25f, -3.0f, 0.0f);
    glVertex3f(-0.25f, -1.0f, 0.0f);

    glEnd();

    glPopMatrix();





//Boat_______________________________________________

    glPushMatrix();
    glTranslatef(2.5+movb, 0.7f, 0.0f);

    glScalef(0.3,0.3,0);
    glBegin(GL_QUADS);

    glColor3ub(139, 121, 94);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);

    glColor3ub(46, 46, 46);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.5f, 0.0f);
    glVertex3f(1.0f, -1.5f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);


    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(-4.5f, -0.5f, 0.0f);
    glVertex3f(-1.0f, -1.5f, 0.0f);

    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(4.5f, -0.5f, 0.0f);
    glVertex3f(1.0f, -1.5f, 0.0f);




    glEnd();




    glPopMatrix();




//RIVER_______________________________________________

    glPushMatrix();


    glBegin(GL_TRIANGLES);

    glColor3ub(127, 255, 212);
    glVertex3f(0.0f, 0.95f, 0.0f);
    glVertex3f(100.0f, 0.95f, 0.0f);
    glVertex3f(3.72f, -0.60f, 0.0f);
    glEnd();

    glPopMatrix();





//Tree


    //Tree_Body
    glPushMatrix();
    glTranslatef(-2.0f, 1.0f, 0.0f);
    glScalef(0.3,0.3,0);

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, 0.0f);

    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.5f, 1.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.5f, 0.5f);

    glVertex2f(0.5f, 0.5f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.5f, 1.0f);
    glVertex2f(1.0f, 0.5f);

    glEnd();



    glPopMatrix();





//House


    glPushMatrix();
    glTranslatef(-2.0f, 1.0f, 0.0f);
    glScalef(0.6,0.6,0);
    glBegin(GL_QUADS);

    //House_Right_Shade

    glColor3f(0.27f, 0.27f, 0.27f);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glVertex3f(2.5f, -1.0f, 0.0f);
    glVertex3f(1.5f, 0.0f, 0.0f);

    //House_Left_Shade

    glColor3f(0.62f, 0.62f, 0.62f);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, -1.0f, 0.0f);
    glVertex3f(-1.5f, -1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.0f);


    //House_Middle_Shade

    glColor3f(0.67f, 0.67f, 0.67f);
    glVertex3f(-1.5f, -1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);



    //House_Left_Wall

    glColor3f(1.0f, 0.85f, 0.72f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-1.5f, -1.0f, 0.0f);
    glVertex3f(-1.5f, -2.0f, 0.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);

    //House_Right_Wall

    glColor3ub(255, 165, 0);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glVertex3f(2.0f, -1.0f, 0.0f);
    glVertex3f(2.0f, -2.0f, 0.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);

    //House_Flore

    glColor3f(0.54f, 0.51f, 0.52f);
    glVertex3f(-1.5f, -2.0f, 0.0f);
    glVertex3f(-1.75f, -2.25f, 0.0f);
    glVertex3f(2.25f, -2.25f, 0.0f);
    glVertex3f(2.0f, -2.0f, 0.0f);


    glEnd();

    glPopMatrix();







//TREE Leaf_______

    //Tree leaf_left

    glPushMatrix();
    glTranslatef(-2.15f, 1.35f, 0.0f);
    glScalef(0.3,0.3,0);

    glColor3ub(46, 139, 87);
    glBegin(GL_POLYGON);


    for(int i=0; i<360; i++)
    {

        theta=i*3.142/180;
        glVertex2f(cos(theta),sin(theta));
    }


    glEnd();
    glPopMatrix();


    //Tree leaf_right__________________

    glPushMatrix();
    glTranslatef(-1.7f, 1.35f, 0.0f);
    glScalef(0.3,0.3,0);

    glColor3ub(0, 139, 0);
    glBegin(GL_POLYGON);


    for(int i=0; i<360; i++)
    {

        theta=i*3.142/180;
        glVertex2f(cos(theta),sin(theta));
    }


    glEnd();
    glPopMatrix();


//Tree leaf_middle__________________

    glPushMatrix();
    glTranslatef(-1.93f, 1.7f, 0.0f);
    glScalef(0.3,0.3,0);

    glColor3ub(105, 139, 105);
    glBegin(GL_POLYGON);


    for(int i=0; i<360; i++)
    {

        theta=i*3.142/180;
        glVertex2f(cos(theta),sin(theta));
    }


    glEnd();

    glPopMatrix();



//SUN_MOON___________
    glPushMatrix();
    glTranslatef(-3.2f, 1.7f, 0.0f);
    glScalef(0.3,0.3,0);
    glColor3ub(smx, smy, smz);
    glBegin(GL_POLYGON);


    for(int i=0; i<360; i++)
    {

        theta=i*3.142/180;
        glVertex2f(cos(theta),sin(theta));
    }


    glEnd();
    glPopMatrix();



//TREES_Multiple__________


    glPushMatrix();
    glTranslatef(-2.7f, 1.15f, 0.0f);
    glScalef(0.2,0.2,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 139, 0);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(-0.25f, 1.5f, 0.0f);
    glVertex3f(-1.0f, 0.5f, 0.0f);

    glVertex3f(0.5f, 1.0f, 0.0f);
    glVertex3f(-.25f, 2.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    glVertex3f(0.5f, 1.5f, 0.0f);
    glVertex3f(-0.25f, 2.5f, 0.0f);
    glVertex3f(-1.0f, 1.5f, 0.0f);

    glEnd();

    glColor3ub(139, 76, 57);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.5f, 1.15f, 0.0f);
    glScalef(0.2,0.2,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 139, 0);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(-0.25f, 1.5f, 0.0f);
    glVertex3f(-1.0f, 0.5f, 0.0f);

    glVertex3f(0.5f, 1.0f, 0.0f);
    glVertex3f(-.25f, 2.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    glVertex3f(0.5f, 1.5f, 0.0f);
    glVertex3f(-0.25f, 2.5f, 0.0f);
    glVertex3f(-1.0f, 1.5f, 0.0f);

    glEnd();

    glColor3ub(139, 76, 57);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7f, 1.15f, 0.0f);
    glScalef(0.2,0.2,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 139, 0);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(-0.25f, 1.5f, 0.0f);
    glVertex3f(-1.0f, 0.5f, 0.0f);

    glVertex3f(0.5f, 1.0f, 0.0f);
    glVertex3f(-.25f, 2.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    glVertex3f(0.5f, 1.5f, 0.0f);
    glVertex3f(-0.25f, 2.5f, 0.0f);
    glVertex3f(-1.0f, 1.5f, 0.0f);

    glEnd();

    glColor3ub(139, 76, 57);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.7f, 1.15f, 0.0f);
    glScalef(0.2,0.2,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 139, 0);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(-0.25f, 1.5f, 0.0f);
    glVertex3f(-1.0f, 0.5f, 0.0f);

    glVertex3f(0.5f, 1.0f, 0.0f);
    glVertex3f(-.25f, 2.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    glVertex3f(0.5f, 1.5f, 0.0f);
    glVertex3f(-0.25f, 2.5f, 0.0f);
    glVertex3f(-1.0f, 1.5f, 0.0f);

    glEnd();

    glColor3ub(139, 76, 57);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.7f, 1.15f, 0.0f);
    glScalef(0.2,0.2,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 139, 0);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(-0.25f, 1.5f, 0.0f);
    glVertex3f(-1.0f, 0.5f, 0.0f);

    glVertex3f(0.5f, 1.0f, 0.0f);
    glVertex3f(-.25f, 2.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    glVertex3f(0.5f, 1.5f, 0.0f);
    glVertex3f(-0.25f, 2.5f, 0.0f);
    glVertex3f(-1.0f, 1.5f, 0.0f);

    glEnd();

    glColor3ub(139, 76, 57);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    glEnd();

    glPopMatrix();


//SKY___________
    glPushMatrix();
    glColor3ub(skyx, skyy, skyz);
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.95f, 0.0f);
    glVertex3f(100.0f, 0.95f, 0.0f);
    glVertex3f(-100.0f, 100.0f, 0.0f);
    glVertex3f(100.0f, 100.0f, 0.0f);

    glEnd();
    glPopMatrix();





//CAR Wheel_1____________________________________________
    glPushMatrix();
    glColor3ub(131, 139, 139);
    glTranslatef(-1.5+mov, -1.4f, 0.0f);
    glScalef(0.2,0.2,0);



    glBegin(GL_POLYGON);


    for(int i=0; i<360; i++)
    {

        theta=i*3.142/180;
        glVertex2f(cos(theta),sin(theta));
    }


    glEnd();
    glPopMatrix();

    //CAR Wheel_2____________________________________________
    glPushMatrix();
    glTranslatef(-0.15+mov, -1.4f, 0.0f);
    glScalef(0.2,0.2,0);



    glBegin(GL_POLYGON);


    for(int i=0; i<360; i++)
    {

        theta=i*3.142/180;
        glVertex2f(cos(theta),sin(theta));
    }


    glEnd();
    glPopMatrix();



    //CAR_____________________________________________
    glPushMatrix();
    glTranslatef(-0.93+mov, -0.75f, 0.0f);
    glScalef(0.3,0.3,0);



    glBegin(GL_QUADS);
    glColor3ub(255, 140, 0);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(-1.5f, -1.0f, 0.0f);
    glVertex3f(2.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);

    glColor3ub(205, 0, 0);
    glVertex3f(-3.0f, -1.0f, 0.0f);
    glVertex3f(-3.5f, -2.0f, 0.0f);
    glVertex3f(4.0f, -2.0f, 0.0f);
    glVertex3f(3.5f, -1.0f, 0.0f);


    glEnd();

    //Headlight

    glBegin(GL_TRIANGLES);
    glColor3ub(lx, ly, lz);
    glVertex3f(-4.5f, -1.0f, 0.0f);
    glVertex3f(-4.5f, -2.0f, 0.0f);
    glVertex3f(-3.25f, -1.5f, 0.0f);

    glEnd();


    glPopMatrix();








//ROAD___________
    glPushMatrix();

    //Road_Devider
    glBegin(GL_QUADS);

    glColor3ub(255, 255, 255);
    glVertex3f(0.0f, -1.5f, 0.0f);
    glVertex3f(1.0f, -1.5f, 0.0f);
    glVertex3f(1.0f, -1.6f, 0.0f);
    glVertex3f(0.0f, -1.6f, 0.0f);
    glColor3ub(255, 255, 255);
    glVertex3f(2.0f, -1.5f, 0.0f);
    glVertex3f(3.0f, -1.5f, 0.0f);
    glVertex3f(3.0f, -1.6f, 0.0f);
    glVertex3f(2.0f, -1.6f, 0.0f);
    glColor3ub(255, 255, 255);
    glVertex3f(-1.0f, -1.5f, 0.0f);
    glVertex3f(-2.0f, -1.5f, 0.0f);
    glVertex3f(-2.0f, -1.6f, 0.0f);
    glVertex3f(-1.0f, -1.6f, 0.0f);
    glColor3ub(255, 255, 255);
    glVertex3f(-3.0f, -1.5f, 0.0f);
    glVertex3f(-4.0f, -1.5f, 0.0f);
    glVertex3f(-4.0f, -1.6f, 0.0f);
    glVertex3f(-3.0f, -1.6f, 0.0f);


    glEnd();



    //Main_Road
    glColor3ub(41, 41, 41);
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, -0.80f, 0.0f);
    glVertex3f(100.0f, -0.80f, 0.0f);
    glVertex3f(100.0f, -100.0f, 0.0f);
    glVertex3f(-100.0f, -100.0f, 0.0f);
    //Road_Border
    glColor3ub(122, 122, 122);
    glVertex3f(-100.0f, -0.80f, 0.0f);
    glVertex3f(100.0f, -0.80f, 0.0f);
    glVertex3f(100.0f, -0.60f, 0.0f);
    glVertex3f(-100.0f, -0.60f, 0.0f);



    glEnd();
    glPopMatrix();










    glutSwapBuffers();
}

void update(int value)
{
    _angle += 2.0f;
    if (_angle > 360)
    {
        _angle -= 360;
    }

    glutPostRedisplay(); ////Tell GLUT that the scene has changed
    glutTimerFunc(fast, update, 0);
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1366, 768);


    glutCreateWindow("Shazzad_  Polash_  Atik_  Abu Taher");
    initRendering();


    glutDisplayFunc(drawScene);
    glutSpecialFunc(handleKeypress);
    glutKeyboardFunc(processNormalKeys);
    glutReshapeFunc(handleResize);

    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}






