#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

static GLfloat  cloud1=0.0;
static GLfloat  cloud2=0.0;
static GLfloat  cloud3=0.0;
static GLfloat  cloud4=0.0;
static GLfloat  cloud5=0.0;
static GLfloat  cloud6=0.0;

static GLfloat  counter_car1=0.0;
static GLfloat  counter_car2=0.0;
static GLfloat  counter_car3=0.0;
static GLfloat  counter_car4=0.0;

static GLfloat  counterBoat1=10.0;
static GLfloat  counterBoat2=10.0;
static GLfloat  counterBoat3=170.0;

static GLfloat  bird1=300.0;
static GLfloat  bird2=100.0;
static GLfloat  bird3=0.0;
static GLfloat  bird4=0.0;

static float  bf=1;
static float  mf=0;
float flag=0;
float flag1=0;

static GLfloat  helicopter1=0.0;

static GLfloat  object=0.0;
static float	tx	=  0.0;
static float	ty	=  1;

void restart(void)
{
   glutPostRedisplay();
}

void bird1_left(void)
{
   bird1=bird1-9;
   glutPostRedisplay();
}
void bird1_right(void)
{
   bird1=bird1+9;
   glutPostRedisplay();
}
void bird2_left(void)
{
   bird2=bird2-9;
   glutPostRedisplay();
}
void bird2_right(void)
{
   bird2=bird2+9;
   glutPostRedisplay();
}
void bird3_left(void)
{
   bird3=bird3-9;
   glutPostRedisplay();
}
void bird3_right(void)
{
   bird3=bird3+9;
   glutPostRedisplay();
}
void bird4_left(void)
{
   bird4=bird4-9;
   glutPostRedisplay();
}
void bird4_right(void)
{
   bird4=bird4+9;
   glutPostRedisplay();
}
void helicopter_left(void)
{
   helicopter1=helicopter1-9;
   glutPostRedisplay();
}
void helicopter_right(void)
{
   helicopter1=helicopter1+9;
   glutPostRedisplay();
}
void car1_left(void)
{
   counter_car1=counter_car1-9;
   glutPostRedisplay();
}
void car1_right(void)
{
   counter_car1=counter_car1+9;
   glutPostRedisplay();
}
void car2_left(void)
{
   counter_car2=counter_car2-9;
   glutPostRedisplay();
}
void car2_right(void)
{
   counter_car2=counter_car2+9;
   glutPostRedisplay();
}
void car3_left(void)
{
   counter_car3=counter_car3-9;
   glutPostRedisplay();
}
void car3_right(void)
{
   counter_car3=counter_car3+9;
   glutPostRedisplay();
}
void car4_left(void)
{
   counter_car4=counter_car4-9;
   glutPostRedisplay();
}
void car4_right(void)
{
   counter_car4=counter_car4+9;
   glutPostRedisplay();
}
void boat1_left(void)
{
   counterBoat1=counterBoat1-9;
   glutPostRedisplay();
}
void boat1_right(void)
{
   counterBoat1=counterBoat1+9;
   glutPostRedisplay();
}
void boat2_left(void)
{
   counterBoat2=counterBoat2-9;
   glutPostRedisplay();
}
void boat2_right(void)
{
   counterBoat2=counterBoat2+9;
   glutPostRedisplay();
}
void boat3_left(void)
{
   counterBoat3=counterBoat3-9;
   glutPostRedisplay();
}
void boat3_right(void)
{
   counterBoat3=counterBoat3+9;
   glutPostRedisplay();
}
void object_left(void)
{
   object = object + 0.30;
   if (object > 360.0)
      object = object - 360.0;
   glutPostRedisplay();
}
void object_right(void)
{
   object = object - 0.30;
   if (object > 360.0)
      object = object - 360.0;
   glutPostRedisplay();
}
void keyboard(unsigned char button, int a, int b)
{
	switch (button) {

		case 's':
			 glutIdleFunc(NULL);
			 break;
        case 'a':
            car1_left();
            break;
        case 'b':
            car1_right();
            break;
        case 'd':
            car2_left();
            break;
        case 'c':
            car2_right();
            break;
        case 'f':
            car3_left();
            break;
        case 'e':
            car3_right();
            break;
        case 'g':
            car4_left();
            break;
        case 'h':
            car4_right();
            break;

        case '1':
            bird1_left();
            break;
        case '2':
            bird1_right();
            break;
        case '3':
            bird2_left();
            break;
        case '4':
            bird2_right();
            break;
        case '6':
            bird3_left();
            break;
        case '5':
            bird3_right();
            break;
        case '8':
            bird4_left();
            break;
        case '7':
            bird4_right();
            break;

        case 'j':
            helicopter_left();
            break;
        case 'i':
            helicopter_right();
            break;

        case 'n':
            boat1_left();
            break;
        case 'm':
            boat1_right();
            break;
        case 'p':
            boat2_left();
            break;
        case 'o':
            boat2_right();
            break;
        case 'y':
            boat3_left();
            break;
        case 'x':
            boat3_right();
            break;

	  default:
			break;
	}
}
void mouse(int button, int mouse_key, int a, int b)
{
   switch (button) {

      case GLUT_LEFT_BUTTON:
         if (mouse_key == GLUT_DOWN)
            glutIdleFunc(restart);
         break;

      case GLUT_RIGHT_BUTTON:
         if (mouse_key == GLUT_DOWN)
			glutIdleFunc(restart);
         break;

      default:
         break;
   }
}
///Circle function
void circle(float cx, float cy, float rx, float ry, int num_segment)
{
    glBegin(GL_TRIANGLE_FAN);
    for(int ii=0; ii<num_segment; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segment);

        float x = rx * cosf(theta);
        float y = ry * sinf(theta);

        glVertex2f(x+cx , y+cy);
    }
    glEnd();
}

void circle2(float cx, float cy, float rx, float ry, int num_segment)
{
    glBegin(GL_TRIANGLE_FAN);
    for(int ii=500; ii<num_segment; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segment);

        float x = rx * cosf(theta);
        float y = ry * sinf(theta);

        glVertex2f(x+cx , y+cy);
    }
    glEnd();
}
///Circle function end

///Bird Start

///Bird-1
void bird_one()
{
    glPushMatrix();
    glLoadIdentity();
    bird1=bird1-0.2;
        if(bird1<=-1600)
        {
            bird1=1000;
        }
    glTranslated(bird1,30,0.0);

        //mouth
    glColor3f (1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f (500.0, 880.0, 0.0);
    glVertex3f (510.0, 920.0, 0.0);
    glVertex3f (525.0, 900.0, 0.0);
    glEnd();

    //leg
    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_LINES);
    glVertex3d(550.0, 880.0, 0.0);
    glVertex3d(565.0, 880.0, 0.0);
  	glEnd();

    glBegin(GL_LINES);
    glVertex3d(550.0, 890.0, 0.0);
    glVertex3d(585.0, 890.0, 0.0);
  	glEnd();

    //body
    glColor3f (0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f (515.0, 900.0, 0.0);
    glVertex3f (510.0, 920.0, 0.0);
    glVertex3f (570.0, 910.0, 0.0);
    glVertex3f (590.0, 920.0, 0.0);
    glVertex3f (590.0, 900.0, 0.0);
    glVertex3f (550.0, 880.0, 0.0);
    glEnd();

    //lej
    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (590.0, 915.0, 0.0);
    glVertex3f (590.0, 920.0, 0.0);
    glVertex3f (610.0, 930.0, 0.0);
    glVertex3f (610.0, 920.0, 0.0);
    glEnd();

    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (590.0, 907.0, 0.0);
    glVertex3f (590.0, 915.0, 0.0);
    glVertex3f (620.0, 915.0, 0.0);
    glVertex3f (620.0, 905.0, 0.0);
    glEnd();

    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (590.0, 900.0, 0.0);
    glVertex3f (590.0, 907.0, 0.0);
    glVertex3f (610.0, 900.0, 0.0);
    glVertex3f (610.0, 890.0, 0.0);
    glEnd();

    if(flag1<=1)
    {
        flag1+=0.01;
        //dana
        glColor3f (0.611, 0.933, 0.125);
        glBegin(GL_POLYGON);
        glVertex3f (540.0, 910.0, 0.0);
        glVertex3f (550.0, 940.0, 0.0);
        glVertex3f (560.0, 930.0, 0.0);
        glVertex3f (590.0, 940.0, 0.0);
        glVertex3f (555.0, 910.0, 0.0);
        glEnd();
    }
    else
    {
        if(flag1>=2)
        {
            flag1=0;
        }
        flag1+=0.01;
        //dana
        glColor3f (0.611, 0.933, 0.125);
        glBegin(GL_POLYGON);
        glVertex3f (540.0, 910.0, 0.0);
        glVertex3f (550.0, 880.0, 0.0);
        glVertex3f (560.0, 890.0, 0.0);
        glVertex3f (590.0, 880.0, 0.0);
        glVertex3f (555.0, 910.0, 0.0);
        glEnd();
    }


    //head
    glColor3f (0.611, 0.933, 0.125);
    circle(520,910,15,15,500);
    //eye
    glColor3f (0,0,0);
    circle(515,910,5,5,500);
    //eye-moni
    glColor3f (1,1,1);
    circle(513,910,2,2,500);

    glPopMatrix();
}

void bird_two()
{
    glPushMatrix();
    glLoadIdentity();

    bird2=bird2-0.07;
        if(bird2<=-1600)
        {
            bird2=1000;
        }

    glTranslated(bird2,-60,0.0);

        //mouth
    glColor3f (1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f (500.0, 880.0, 0.0);
    glVertex3f (510.0, 920.0, 0.0);
    glVertex3f (525.0, 900.0, 0.0);
    glEnd();

    //leg
    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_LINES);
    glVertex3d(550.0, 880.0, 0.0);
    glVertex3d(565.0, 880.0, 0.0);
  	glEnd();

    glBegin(GL_LINES);
    glVertex3d(550.0, 890.0, 0.0);
    glVertex3d(585.0, 890.0, 0.0);
  	glEnd();

    //body
    glColor3f (0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f (515.0, 900.0, 0.0);
    glVertex3f (510.0, 920.0, 0.0);
    glVertex3f (570.0, 910.0, 0.0);
    glVertex3f (590.0, 920.0, 0.0);
    glVertex3f (590.0, 900.0, 0.0);
    glVertex3f (550.0, 880.0, 0.0);
    glEnd();

    //lej
    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (590.0, 915.0, 0.0);
    glVertex3f (590.0, 920.0, 0.0);
    glVertex3f (610.0, 930.0, 0.0);
    glVertex3f (610.0, 920.0, 0.0);
    glEnd();

    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (590.0, 907.0, 0.0);
    glVertex3f (590.0, 915.0, 0.0);
    glVertex3f (620.0, 915.0, 0.0);
    glVertex3f (620.0, 905.0, 0.0);
    glEnd();

    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (590.0, 900.0, 0.0);
    glVertex3f (590.0, 907.0, 0.0);
    glVertex3f (610.0, 900.0, 0.0);
    glVertex3f (610.0, 890.0, 0.0);
    glEnd();
    if(flag1<=1)
    {
        flag1+=0.01;
        //dana
        glColor3f (0.611, 0.933, 0.125);
        glBegin(GL_POLYGON);
        glVertex3f (540.0, 910.0, 0.0);
        glVertex3f (550.0, 940.0, 0.0);
        glVertex3f (560.0, 930.0, 0.0);
        glVertex3f (590.0, 940.0, 0.0);
        glVertex3f (555.0, 910.0, 0.0);
        glEnd();
    }
    else
    {
        if(flag1>=2)
        {
            flag1=0;
        }
        flag1+=0.01;
        //dana
        glColor3f (0.611, 0.933, 0.125);
        glBegin(GL_POLYGON);
        glVertex3f (540.0, 910.0, 0.0);
        glVertex3f (550.0, 880.0, 0.0);
        glVertex3f (560.0, 890.0, 0.0);
        glVertex3f (590.0, 880.0, 0.0);
        glVertex3f (555.0, 910.0, 0.0);
        glEnd();
    }

    //head
    glColor3f (0.611, 0.933, 0.125);
    circle(520,910,15,15,500);
    //eye
    glColor3f (0,0,0);
    circle(515,910,5,5,500);
    //eye-moni
    glColor3f (1,1,1);
    circle(513,910,2,2,500);

    glPopMatrix();
}

void bird_three()
{
    glPushMatrix();
    glLoadIdentity();
    bird3=bird3+0.08;
        if(bird3>=1600)
        {
            bird3=-1000;
        }

    glTranslated(bird3,30,0.0);

    //mouth
    glColor3f (1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f (-500.0, 880.0, 0.0);
    glVertex3f (-510.0, 920.0, 0.0);
    glVertex3f (-525.0, 900.0, 0.0);
    glEnd();

    //leg
    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_LINES);
    glVertex3d(-550.0, 880.0, 0.0);
    glVertex3d(-565.0, 880.0, 0.0);
  	glEnd();

    glBegin(GL_LINES);
    glVertex3d(-550.0, 890.0, 0.0);
    glVertex3d(-585.0, 890.0, 0.0);
  	glEnd();

    //body
    glColor3f (0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f (-515.0, 900.0, 0.0);
    glVertex3f (-510.0, 920.0, 0.0);
    glVertex3f (-570.0, 910.0, 0.0);
    glVertex3f (-590.0, 920.0, 0.0);
    glVertex3f (-590.0, 900.0, 0.0);
    glVertex3f (-550.0, 880.0, 0.0);
    glEnd();

    //lej
    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (-590.0, 915.0, 0.0);
    glVertex3f (-590.0, 920.0, 0.0);
    glVertex3f (-610.0, 930.0, 0.0);
    glVertex3f (-610.0, 920.0, 0.0);
    glEnd();

    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (-590.0, 907.0, 0.0);
    glVertex3f (-590.0, 915.0, 0.0);
    glVertex3f (-620.0, 915.0, 0.0);
    glVertex3f (-620.0, 905.0, 0.0);
    glEnd();

    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (-590.0, 900.0, 0.0);
    glVertex3f (-590.0, 907.0, 0.0);
    glVertex3f (-610.0, 900.0, 0.0);
    glVertex3f (-610.0, 890.0, 0.0);
    glEnd();
    if(flag1<=1)
    {
        flag1+=0.001;
        //dana
        glColor3f (0.611, 0.933, 0.125);
        glBegin(GL_POLYGON);
        glVertex3f (-540.0, 910.0, 0.0);
        glVertex3f (-550.0, 940.0, 0.0);
        glVertex3f (-560.0, 930.0, 0.0);
        glVertex3f (-590.0, 940.0, 0.0);
        glVertex3f (-555.0, 910.0, 0.0);
        glEnd();
    }
    else
    {
        if(flag1>=2)
        {
            flag1=0;
        }
        flag1+=0.001;
        //dana
        glColor3f (0.611, 0.933, 0.125);
        glBegin(GL_POLYGON);
        glVertex3f (-540.0, 910.0, 0.0);
        glVertex3f (-550.0, 880.0, 0.0);
        glVertex3f (-560.0, 890.0, 0.0);
        glVertex3f (-590.0, 880.0, 0.0);
        glVertex3f (-555.0, 910.0, 0.0);
        glEnd();
    }

    //head
    glColor3f (0.611, 0.933, 0.125);
    circle(-520,910,15,15,500);
    //eye
    glColor3f (0,0,0);
    circle(-515,910,5,5,500);
    //eye-moni
    glColor3f (1,1,1);
    circle(-513,910,2,2,500);

    glPopMatrix();
}

void bird_four()
{
    glPushMatrix();
    glLoadIdentity();
    bird4=bird4+0.2;
        if(bird4>=1600)
        {
            bird4=-1000;
        }

    glTranslated(bird4,-70,0.0);

    //mouth
    glColor3f (1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f (-500.0, 880.0, 0.0);
    glVertex3f (-510.0, 920.0, 0.0);
    glVertex3f (-525.0, 900.0, 0.0);
    glEnd();

    //leg
    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_LINES);
    glVertex3d(-550.0, 880.0, 0.0);
    glVertex3d(-565.0, 880.0, 0.0);
  	glEnd();

    glBegin(GL_LINES);
    glVertex3d(-550.0, 890.0, 0.0);
    glVertex3d(-585.0, 890.0, 0.0);
  	glEnd();

    //body
    glColor3f (0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f (-515.0, 900.0, 0.0);
    glVertex3f (-510.0, 920.0, 0.0);
    glVertex3f (-570.0, 910.0, 0.0);
    glVertex3f (-590.0, 920.0, 0.0);
    glVertex3f (-590.0, 900.0, 0.0);
    glVertex3f (-550.0, 880.0, 0.0);
    glEnd();

    //lej
    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (-590.0, 915.0, 0.0);
    glVertex3f (-590.0, 920.0, 0.0);
    glVertex3f (-610.0, 930.0, 0.0);
    glVertex3f (-610.0, 920.0, 0.0);
    glEnd();

    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (-590.0, 907.0, 0.0);
    glVertex3f (-590.0, 915.0, 0.0);
    glVertex3f (-620.0, 915.0, 0.0);
    glVertex3f (-620.0, 905.0, 0.0);
    glEnd();

    glColor3f (0.611, 0.933, 0.125);
    glBegin(GL_QUADS);
    glVertex3f (-590.0, 900.0, 0.0);
    glVertex3f (-590.0, 907.0, 0.0);
    glVertex3f (-610.0, 900.0, 0.0);
    glVertex3f (-610.0, 890.0, 0.0);
    glEnd();
    if(flag1<=1)
    {
        flag1+=0.001;
        //dana
        glColor3f (0.611, 0.933, 0.125);
        glBegin(GL_POLYGON);
        glVertex3f (-540.0, 910.0, 0.0);
        glVertex3f (-550.0, 940.0, 0.0);
        glVertex3f (-560.0, 930.0, 0.0);
        glVertex3f (-590.0, 940.0, 0.0);
        glVertex3f (-555.0, 910.0, 0.0);
        glEnd();
    }
    else
    {
        if(flag1>=2)
        {
            flag1=0;
        }
        flag1+=0.001;
        //dana
        glColor3f (0.611, 0.933, 0.125);
        glBegin(GL_POLYGON);
        glVertex3f (-540.0, 910.0, 0.0);
        glVertex3f (-550.0, 880.0, 0.0);
        glVertex3f (-560.0, 890.0, 0.0);
        glVertex3f (-590.0, 880.0, 0.0);
        glVertex3f (-555.0, 910.0, 0.0);
        glEnd();
    }

    //head
    glColor3f (0.611, 0.933, 0.125);
    circle(-520,910,15,15,500);
    //eye
    glColor3f (0,0,0);
    circle(-515,910,5,5,500);
    //eye-moni
    glColor3f (1,1,1);
    circle(-513,910,2,2,500);

    glPopMatrix();
}
///Bird End

/// Windmill start

void turbine()
{
    glColor3f(0.988, 0.980, 0.631);
    glBegin(GL_QUADS);
    glVertex3f (-840.0, 140.0, 0.0);
    glVertex3f (-840.0, 180.0, 0.0);
    glVertex3f (-900.0, 180.0, 0.0);
    glVertex3f (-900.0, 140.0, 0.0);
    glEnd();

    glColor3f (0.956, 0.901, 0.784);
    glBegin(GL_QUADS);
    glVertex3f (-860.0, 180.0, 0.0);
    glVertex3f (-860.0, 460.0, 0.0);
    glVertex3f (-880.0, 460.0, 0.0);
    glVertex3f (-880.0, 180.0, 0.0);
    glEnd();

    //turbine rotate
    glPushMatrix();

	glTranslatef(-870.0f, 460.0f, 0.0f);
	glRotatef(object, 0.0, 0.0, 1.0);

    glColor3f(1.0, 1.0, 1.0);
         glRectf(-100,-12, 100, 12);

         glColor3f(0.956, 0.901, 0.784);
         glRectf(70.0,-35, 120, 12);
         glRectf(-70.0,-12, -120, 35);

    glColor3f(1.0, 1.0, 1.0);
        glRectf(-12,-100, 12, 100);

        glColor3f(0.956, 0.901, 0.784);
        glRectf(-12.0,70, 35, 120);
        glRectf(-35.0,-70, 12, -120);

	glPopMatrix();

	glColor3f(0.956, 0.901, 0.784);
	circle(-870,460,30,30,500);

}

///Windmill End

///Traffic Start

void traffic()
{
    glColor3f (0.615, 0.843, 0.941);
    glBegin(GL_QUADS);
    glVertex3f (870.0, 140.0, 0.0);
    glVertex3f (870.0, 180.0, 0.0);
    glVertex3f (930.0, 180.0, 0.0);
    glVertex3f (930.0, 140.0, 0.0);
    glEnd();

    glColor3f (0.615, 0.843, 0.941);
    glBegin(GL_QUADS);
    glVertex3f (890.0, 180.0, 0.0);
    glVertex3f (890.0, 380.0, 0.0);
    glVertex3f (910.0, 380.0, 0.0);
    glVertex3f (910.0, 180.0, 0.0);
    glEnd();

    glColor3f (0.615, 0.843, 0.941);
    glBegin(GL_QUADS);
    glVertex3f (855.0, 360.0, 0.0);
    glVertex3f (855.0, 580.0, 0.0);
    glVertex3f (945.0, 580.0, 0.0);
    glVertex3f (945.0, 360.0, 0.0);
    glEnd();

    glColor3f(1,0,0);
    circle(900,540,30,30,500);

    glColor3f(1,1,0);
    circle(900,470,30,30,500);

    glColor3f(0,1,0);
    circle(900,400,30,30,500);
}
/// Traffic End

///Boat-1 and Sea
void boat1_sea()
{

    //sea waves-1
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (180.0, -180.0, 0.0);
    glVertex3f (180.0, -182.0, 0.0);
    glVertex3f (250.0, -182.0, 0.0);
    glVertex3f (250.0, -180.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (180.0, -380.0, 0.0);
    glVertex3f (180.0, -382.0, 0.0);
    glVertex3f (250.0, -382.0, 0.0);
    glVertex3f (250.0, -380.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (180.0, -580.0, 0.0);
    glVertex3f (180.0, -582.0, 0.0);
    glVertex3f (250.0, -582.0, 0.0);
    glVertex3f (250.0, -580.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (180.0, -780.0, 0.0);
    glVertex3f (180.0, -782.0, 0.0);
    glVertex3f (250.0, -782.0, 0.0);
    glVertex3f (250.0, -780.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (180.0, -980.0, 0.0);
    glVertex3f (180.0, -982.0, 0.0);
    glVertex3f (250.0, -982.0, 0.0);
    glVertex3f (250.0, -980.0, 0.0);
    glEnd();

    //sea waves-2
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (300.0, -180.0, 0.0);
    glVertex3f (300.0, -182.0, 0.0);
    glVertex3f (370.0, -182.0, 0.0);
    glVertex3f (370.0, -180.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (300.0, -380.0, 0.0);
    glVertex3f (300.0, -382.0, 0.0);
    glVertex3f (370.0, -382.0, 0.0);
    glVertex3f (370.0, -380.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (300.0, -580.0, 0.0);
    glVertex3f (300.0, -582.0, 0.0);
    glVertex3f (370.0, -582.0, 0.0);
    glVertex3f (370.0, -580.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (300.0, -780.0, 0.0);
    glVertex3f (300.0, -782.0, 0.0);
    glVertex3f (370.0, -782.0, 0.0);
    glVertex3f (370.0, -780.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (300.0, -980.0, 0.0);
    glVertex3f (300.0, -982.0, 0.0);
    glVertex3f (370.0, -982.0, 0.0);
    glVertex3f (370.0, -980.0, 0.0);
    glEnd();

    //sea waves-3
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (420.0, -180.0, 0.0);
    glVertex3f (420.0, -182.0, 0.0);
    glVertex3f (490.0, -182.0, 0.0);
    glVertex3f (490.0, -180.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (420.0, -380.0, 0.0);
    glVertex3f (420.0, -382.0, 0.0);
    glVertex3f (490.0, -382.0, 0.0);
    glVertex3f (490.0, -380.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (420.0, -580.0, 0.0);
    glVertex3f (420.0, -582.0, 0.0);
    glVertex3f (490.0, -582.0, 0.0);
    glVertex3f (490.0, -580.0, 0.0);
    glEnd();

     glBegin(GL_QUADS);
    glVertex3f (420.0, -780.0, 0.0);
    glVertex3f (420.0, -782.0, 0.0);
    glVertex3f (490.0, -782.0, 0.0);
    glVertex3f (490.0, -780.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (420.0, -980.0, 0.0);
    glVertex3f (420.0, -982.0, 0.0);
    glVertex3f (490.0, -982.0, 0.0);
    glVertex3f (490.0, -980.0, 0.0);
    glEnd();

    //sea waves-4
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (540.0, -180.0, 0.0);
    glVertex3f (540.0, -182.0, 0.0);
    glVertex3f (610.0, -182.0, 0.0);
    glVertex3f (610.0, -180.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (540.0, -380.0, 0.0);
    glVertex3f (540.0, -382.0, 0.0);
    glVertex3f (610.0, -382.0, 0.0);
    glVertex3f (610.0, -380.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (540.0, -580.0, 0.0);
    glVertex3f (540.0, -582.0, 0.0);
    glVertex3f (610.0, -582.0, 0.0);
    glVertex3f (610.0, -580.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (540.0, -780.0, 0.0);
    glVertex3f (540.0, -782.0, 0.0);
    glVertex3f (610.0, -782.0, 0.0);
    glVertex3f (610.0, -780.0, 0.0);
    glEnd();

     glBegin(GL_QUADS);
    glVertex3f (540.0, -980.0, 0.0);
    glVertex3f (540.0, -982.0, 0.0);
    glVertex3f (610.0, -982.0, 0.0);
    glVertex3f (610.0, -980.0, 0.0);
    glEnd();

    //sea waves-5
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (660.0, -180.0, 0.0);
    glVertex3f (660.0, -182.0, 0.0);
    glVertex3f (730.0, -182.0, 0.0);
    glVertex3f (730.0, -180.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (660.0, -380.0, 0.0);
    glVertex3f (660.0, -382.0, 0.0);
    glVertex3f (730.0, -382.0, 0.0);
    glVertex3f (730.0, -380.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (660.0, -580.0, 0.0);
    glVertex3f (660.0, -582.0, 0.0);
    glVertex3f (730.0, -582.0, 0.0);
    glVertex3f (730.0, -580.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (660.0, -780.0, 0.0);
    glVertex3f (660.0, -782.0, 0.0);
    glVertex3f (730.0, -782.0, 0.0);
    glVertex3f (730.0, -780.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (660.0, -980.0, 0.0);
    glVertex3f (660.0, -982.0, 0.0);
    glVertex3f (730.0, -982.0, 0.0);
    glVertex3f (730.0, -980.0, 0.0);
    glEnd();

    //sea waves-6
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (780.0, -180.0, 0.0);
    glVertex3f (780.0, -182.0, 0.0);
    glVertex3f (850.0, -182.0, 0.0);
    glVertex3f (850.0, -180.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (780.0, -380.0, 0.0);
    glVertex3f (780.0, -382.0, 0.0);
    glVertex3f (850.0, -382.0, 0.0);
    glVertex3f (850.0, -380.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (780.0, -580.0, 0.0);
    glVertex3f (780.0, -582.0, 0.0);
    glVertex3f (850.0, -582.0, 0.0);
    glVertex3f (850.0, -580.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (780.0, -780.0, 0.0);
    glVertex3f (780.0, -782.0, 0.0);
    glVertex3f (850.0, -782.0, 0.0);
    glVertex3f (850.0, -780.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (780.0, -980.0, 0.0);
    glVertex3f (780.0, -982.0, 0.0);
    glVertex3f (850.0, -982.0, 0.0);
    glVertex3f (850.0, -980.0, 0.0);
    glEnd();

    //sea waves-7
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (900.0, -180.0, 0.0);
    glVertex3f (900.0, -182.0, 0.0);
    glVertex3f (970.0, -182.0, 0.0);
    glVertex3f (970.0, -180.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (900.0, -380.0, 0.0);
    glVertex3f (900.0, -382.0, 0.0);
    glVertex3f (970.0, -382.0, 0.0);
    glVertex3f (970.0, -380.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (900.0, -580.0, 0.0);
    glVertex3f (900.0, -582.0, 0.0);
    glVertex3f (970.0, -582.0, 0.0);
    glVertex3f (970.0, -580.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (900.0, -780.0, 0.0);
    glVertex3f (900.0, -782.0, 0.0);
    glVertex3f (970.0, -782.0, 0.0);
    glVertex3f (970.0, -780.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (900.0, -980.0, 0.0);
    glVertex3f (900.0, -982.0, 0.0);
    glVertex3f (970.0, -982.0, 0.0);
    glVertex3f (970.0, -980.0, 0.0);
    glEnd();

    //sea waves-11
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (180.0, -280.0, 0.0);
    glVertex3f (180.0, -282.0, 0.0);
    glVertex3f (300.0, -282.0, 0.0);
    glVertex3f (300.0, -280.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (180.0, -480.0, 0.0);
    glVertex3f (180.0, -482.0, 0.0);
    glVertex3f (300.0, -482.0, 0.0);
    glVertex3f (300.0, -480.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (180.0, -680.0, 0.0);
    glVertex3f (180.0, -682.0, 0.0);
    glVertex3f (300.0, -682.0, 0.0);
    glVertex3f (300.0, -680.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (180.0, -880.0, 0.0);
    glVertex3f (180.0, -882.0, 0.0);
    glVertex3f (300.0, -882.0, 0.0);
    glVertex3f (300.0, -880.0, 0.0);
    glEnd();

    //sea waves-22
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (350.0, -280.0, 0.0);
    glVertex3f (350.0, -282.0, 0.0);
    glVertex3f (470.0, -282.0, 0.0);
    glVertex3f (470.0, -280.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (350.0, -480.0, 0.0);
    glVertex3f (350.0, -482.0, 0.0);
    glVertex3f (470.0, -482.0, 0.0);
    glVertex3f (470.0, -480.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (350.0, -680.0, 0.0);
    glVertex3f (350.0, -682.0, 0.0);
    glVertex3f (470.0, -682.0, 0.0);
    glVertex3f (470.0, -680.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (350.0, -880.0, 0.0);
    glVertex3f (350.0, -882.0, 0.0);
    glVertex3f (470.0, -882.0, 0.0);
    glVertex3f (470.0, -880.0, 0.0);
    glEnd();

    //sea waves-33
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (520.0, -280.0, 0.0);
    glVertex3f (520.0, -282.0, 0.0);
    glVertex3f (640.0, -282.0, 0.0);
    glVertex3f (640.0, -280.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (520.0, -480.0, 0.0);
    glVertex3f (520.0, -482.0, 0.0);
    glVertex3f (640.0, -482.0, 0.0);
    glVertex3f (640.0, -480.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (520.0, -680.0, 0.0);
    glVertex3f (520.0, -682.0, 0.0);
    glVertex3f (640.0, -682.0, 0.0);
    glVertex3f (640.0, -680.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (520.0, -880.0, 0.0);
    glVertex3f (520.0, -882.0, 0.0);
    glVertex3f (640.0, -882.0, 0.0);
    glVertex3f (640.0, -880.0, 0.0);
    glEnd();

    //sea waves-44
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (690.0, -280.0, 0.0);
    glVertex3f (690.0, -282.0, 0.0);
    glVertex3f (810.0, -282.0, 0.0);
    glVertex3f (810.0, -280.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (690.0, -480.0, 0.0);
    glVertex3f (690.0, -482.0, 0.0);
    glVertex3f (810.0, -482.0, 0.0);
    glVertex3f (810.0, -480.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (690.0, -680.0, 0.0);
    glVertex3f (690.0, -682.0, 0.0);
    glVertex3f (810.0, -682.0, 0.0);
    glVertex3f (810.0, -680.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (690.0, -880.0, 0.0);
    glVertex3f (690.0, -882.0, 0.0);
    glVertex3f (810.0, -882.0, 0.0);
    glVertex3f (810.0, -880.0, 0.0);
    glEnd();

    //sea waves-55
    glColor3f (0.364, 0.933, 0.972);
    glBegin(GL_QUADS);
    glVertex3f (860.0, -280.0, 0.0);
    glVertex3f (860.0, -282.0, 0.0);
    glVertex3f (980.0, -282.0, 0.0);
    glVertex3f (980.0, -280.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (860.0, -480.0, 0.0);
    glVertex3f (860.0, -482.0, 0.0);
    glVertex3f (980.0, -482.0, 0.0);
    glVertex3f (980.0, -480.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (860.0, -680.0, 0.0);
    glVertex3f (860.0, -682.0, 0.0);
    glVertex3f (980.0, -682.0, 0.0);
    glVertex3f (980.0, -680.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f (860.0, -880.0, 0.0);
    glVertex3f (860.0, -882.0, 0.0);
    glVertex3f (980.0, -882.0, 0.0);
    glVertex3f (980.0, -880.0, 0.0);
    glEnd();

    //sea bridge
    glColor3f (0.815, 0.603, 0.184);
    glBegin(GL_QUADS);
    glVertex3f (140.0, -520.0, 0.0);
    glVertex3f (140.0, -400.0, 0.0);
    glVertex3f (250.0, -400.0, 0.0);
    glVertex3f (250.0, -520.0, 0.0);
    glEnd();

    glColor3f (0.815, 0.603, 0.184);
    glBegin(GL_QUADS);
    glVertex3f (250.0, -520.0, 0.0);
    glVertex3f (250.0, -400.0, 0.0);
    glVertex3f (350.0, -430.0, 0.0);
    glVertex3f (350.0, -550.0, 0.0);
    glEnd();

    glColor3f (0.972, 0.701, 0.364);
    glBegin(GL_QUADS);
    glVertex3f (140.0, -410.0, 0.0);
    glVertex3f (140.0, -400.0, 0.0);
    glVertex3f (250.0, -400.0, 0.0);
    glVertex3f (250.0, -410.0, 0.0);
    glEnd();

    glColor3f (0.972, 0.701, 0.364);
    glBegin(GL_QUADS);
    glVertex3f (140.0, -520.0, 0.0);
    glVertex3f (140.0, -510.0, 0.0);
    glVertex3f (250.0, -510.0, 0.0);
    glVertex3f (250.0, -520.0, 0.0);
    glEnd();

    glColor3f (0.972, 0.701, 0.364);
    glBegin(GL_QUADS);
    glVertex3f (250.0, -410.0, 0.0);
    glVertex3f (250.0, -400.0, 0.0);
    glVertex3f (350.0, -430.0, 0.0);
    glVertex3f (350.0, -440.0, 0.0);
    glEnd();

    glColor3f (0.972, 0.701, 0.364);
    glBegin(GL_QUADS);
    glVertex3f (250.0, -520.0, 0.0);
    glVertex3f (250.0, -510.0, 0.0);
    glVertex3f (350.0, -540.0, 0.0);
    glVertex3f (350.0, -550.0, 0.0);
    glEnd();

    //bridge pillar
    glColor3f (0.533, 0.431, 0.266);
    glBegin(GL_QUADS);
    glVertex3f (170.0, -560.0, 0.0);
    glVertex3f (170.0, -520.0, 0.0);
    glVertex3f (190.0, -520.0, 0.0);
    glVertex3f (190.0, -560.0, 0.0);
    glEnd();

    glColor3f (0.533, 0.431, 0.266);
    glBegin(GL_QUADS);
    glVertex3f (230.0, -560.0, 0.0);
    glVertex3f (230.0, -520.0, 0.0);
    glVertex3f (250.0, -520.0, 0.0);
    glVertex3f (250.0, -560.0, 0.0);
    glEnd();

    ///Boat - 1
    glPushMatrix();
    glLoadIdentity();
    if(bf==0)
    {
        counterBoat1=counterBoat1+0.06;
        if(counterBoat1>=1000)
        {
            bf=1;
        }
    }
    else
    {
        counterBoat1=counterBoat1-0.06;
        if(counterBoat1<=100)
        {
            bf=0;
        }
    }
    glTranslated(counterBoat1,-180,0.0);

    //Boat body
    glColor3f (0.0, 0.0, 0.929);
    glBegin(GL_QUADS);
    glVertex3f (170.0, -600.0, 0.0);
    glVertex3f (120.0, -530.0, 0.0);
    glVertex3f (460.0, -530.0, 0.0);
    glVertex3f (380.0, -600.0, 0.0);
    glEnd();

    //top part of boat
    glColor3f (0.8, 0.901, 0.078);
    glBegin(GL_QUADS);
    glVertex3f (190.0, -530.0, 0.0);
    glVertex3f (190.0, -490.0, 0.0);
    glVertex3f (390.0, -490.0, 0.0);
    glVertex3f (390.0, -530.0, 0.0);
    glEnd();

    glColor3f (0.8, 0.901, 0.078);
    glBegin(GL_QUADS);
    glVertex3f (220.0, -490.0, 0.0);
    glVertex3f (220.0, -450.0, 0.0);
    glVertex3f (350.0, -450.0, 0.0);
    glVertex3f (350.0, -490.0, 0.0);
    glEnd();

    // boat window 1st row
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (210.0, -520.0, 0.0);
    glVertex3f (210.0, -500.0, 0.0);
    glVertex3f (250.0, -500.0, 0.0);
    glVertex3f (250.0, -520.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (270.0, -520.0, 0.0);
    glVertex3f (270.0, -500.0, 0.0);
    glVertex3f (310.0, -500.0, 0.0);
    glVertex3f (310.0, -520.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (330.0, -520.0, 0.0);
    glVertex3f (330.0, -500.0, 0.0);
    glVertex3f (370.0, -500.0, 0.0);
    glVertex3f (370.0, -520.0, 0.0);
    glEnd();

    // boat window top row
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (230.0, -480.0, 0.0);
    glVertex3f (230.0, -460.0, 0.0);
    glVertex3f (275.0, -460.0, 0.0);
    glVertex3f (275.0, -480.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (295.0, -480.0, 0.0);
    glVertex3f (295.0, -460.0, 0.0);
    glVertex3f (340.0, -460.0, 0.0);
    glVertex3f (340.0, -480.0, 0.0);
    glEnd();

    glPopMatrix();


}

///Boat-2
void boat2_sea()
{

    glPushMatrix();
    glLoadIdentity();
    if(bf==0)
    {
        counterBoat2=counterBoat2+0.08;
        if(counterBoat2>=1100)
        {
            bf=1;
        }
    }
    else
    {
        counterBoat2=counterBoat2-0.08;
        if(counterBoat2<=120)
        {
            bf=0;
        }
    }

    glTranslated(counterBoat2,250,0.0);

    //Boat body
    glColor3f (0.913, 0.168, 0.298);
    glBegin(GL_QUADS);
    glVertex3f (170.0, -600.0, 0.0);
    glVertex3f (120.0, -530.0, 0.0);
    glVertex3f (460.0, -530.0, 0.0);
    glVertex3f (380.0, -600.0, 0.0);
    glEnd();

    //top part of boat
    glColor3f (0.8, 0.901, 0.078);
    glBegin(GL_QUADS);
    glVertex3f (160.0, -530.0, 0.0);
    glVertex3f (190.0, -490.0, 0.0);
    glVertex3f (390.0, -490.0, 0.0);
    glVertex3f (420.0, -530.0, 0.0);
    glEnd();

    // boat window 1st row
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (210.0, -520.0, 0.0);
    glVertex3f (210.0, -500.0, 0.0);
    glVertex3f (250.0, -500.0, 0.0);
    glVertex3f (250.0, -520.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (270.0, -520.0, 0.0);
    glVertex3f (270.0, -500.0, 0.0);
    glVertex3f (310.0, -500.0, 0.0);
    glVertex3f (310.0, -520.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (330.0, -520.0, 0.0);
    glVertex3f (330.0, -500.0, 0.0);
    glVertex3f (370.0, -500.0, 0.0);
    glVertex3f (370.0, -520.0, 0.0);
    glEnd();

    glPopMatrix();


}
///Boat-2 End

///Boat-3 Start
void boat3_sea()
{

    glPushMatrix();
    glLoadIdentity();
    counterBoat3=counterBoat3+0.0;
    glTranslated(counterBoat3,70,0.0);

    //Boat body
    glColor3f (0.274, 0.113, 0.525);
    glBegin(GL_QUADS);
    glVertex3f (190.0, -600.0, 0.0);
    glVertex3f (140.0, -530.0, 0.0);
    glVertex3f (510.0, -530.0, 0.0);
    glVertex3f (430.0, -600.0, 0.0);
    glEnd();

    //top part of boat
    glColor3f (0.886, 0.113, 0.768);
    glBegin(GL_QUADS);
    glVertex3f (190.0, -530.0, 0.0);
    glVertex3f (210.0, -490.0, 0.0);
    glVertex3f (420.0, -490.0, 0.0);
    glVertex3f (440.0, -530.0, 0.0);
    glEnd();

    glColor3f (0.886, 0.113, 0.768);
    glBegin(GL_QUADS);
    glVertex3f (230.0, -490.0, 0.0);
    glVertex3f (250.0, -450.0, 0.0);
    glVertex3f (380.0, -450.0, 0.0);
    glVertex3f (400.0, -490.0, 0.0);
    glEnd();

    // boat window 1st row
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (230.0, -520.0, 0.0);
    glVertex3f (230.0, -500.0, 0.0);
    glVertex3f (270.0, -500.0, 0.0);
    glVertex3f (270.0, -520.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (290.0, -520.0, 0.0);
    glVertex3f (290.0, -500.0, 0.0);
    glVertex3f (330.0, -500.0, 0.0);
    glVertex3f (330.0, -520.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (350.0, -520.0, 0.0);
    glVertex3f (350.0, -500.0, 0.0);
    glVertex3f (390.0, -500.0, 0.0);
    glVertex3f (390.0, -520.0, 0.0);
    glEnd();

    // boat window top row
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (260.0, -480.0, 0.0);
    glVertex3f (260.0, -460.0, 0.0);
    glVertex3f (305.0, -460.0, 0.0);
    glVertex3f (305.0, -480.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (325.0, -480.0, 0.0);
    glVertex3f (325.0, -460.0, 0.0);
    glVertex3f (370.0, -460.0, 0.0);
    glVertex3f (370.0, -480.0, 0.0);
    glEnd();

    glPopMatrix();


}

///Field and hospital and Tree
void hospital_sign(int x,int y)
{
   float theta;
   glBegin(GL_POLYGON);
   for(int i=0;i<360;i++)
   {
       theta=i*(3.1416/180);
       glVertex2f(x+50*cos(theta),y+50*sin(theta));
   }

   glEnd();

}

void field_tree()
{

    //filed road
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-420.0, -1000.0, 0.0);
    glVertex3f (-460.0, -700.0, 0.0);
    glVertex3f (-480.0, -700.0, 0.0);
    glVertex3f (-440.0, -1000.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-760.0, -1000.0, 0.0);
    glVertex3f (-720.0, -700.0, 0.0);
    glVertex3f (-740.0, -700.0, 0.0);
    glVertex3f (-780.0, -1000.0, 0.0);
    glEnd();

    glColor3f (0.207, 0.231, 0.211);
    glBegin(GL_QUADS);
    glVertex3f (-440.0, -1000.0, 0.0);
    glVertex3f (-480.0, -700.0, 0.0);
    glVertex3f (-720.0, -700.0, 0.0);
    glVertex3f (-760.0, -1000.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-595.0, -770.0, 0.0);
    glVertex3f (-595.0, -720.0, 0.0);
    glVertex3f (-605.0, -720.0, 0.0);
    glVertex3f (-605.0, -770.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-595.0, -840.0, 0.0);
    glVertex3f (-595.0, -790.0, 0.0);
    glVertex3f (-605.0, -790.0, 0.0);
    glVertex3f (-605.0, -840.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-595.0, -910.0, 0.0);
    glVertex3f (-595.0, -860.0, 0.0);
    glVertex3f (-605.0, -860.0, 0.0);
    glVertex3f (-605.0, -910.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-595.0, -980.0, 0.0);
    glVertex3f (-595.0, -930.0, 0.0);
    glVertex3f (-605.0, -930.0, 0.0);
    glVertex3f (-605.0, -980.0, 0.0);
    glEnd();
    //tree-1
    glColor3f (0.380, 0.247, 0.101);
    glBegin(GL_QUADS);
    glVertex3f (-900.0, -700.0, 0.0);
    glVertex3f (-910.0, -550.0, 0.0);
    glVertex3f (-940.0, -550.0, 0.0);
    glVertex3f (-950.0, -700.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-860.0, -550.0, 0.0);
    glVertex3f (-925.0, -450.0, 0.0);
    glVertex3f (-990.0, -550.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-870.0, -500.0, 0.0);
    glVertex3f (-925.0, -400.0, 0.0);
    glVertex3f (-980.0, -500.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-880.0, -450.0, 0.0);
    glVertex3f (-925.0, -350.0, 0.0);
    glVertex3f (-970.0, -450.0, 0.0);
    glEnd();
    //tree-2
    glColor3f (0.380, 0.247, 0.101);
    glBegin(GL_QUADS);
    glVertex3f (-260.0, -700.0, 0.0);
    glVertex3f (-270.0, -550.0, 0.0);
    glVertex3f (-300.0, -550.0, 0.0);
    glVertex3f (-310.0, -700.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-230.0, -550.0, 0.0);
    glVertex3f (-285.0, -450.0, 0.0);
    glVertex3f (-340.0, -550.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-240.0, -500.0, 0.0);
    glVertex3f (-285.0, -400.0, 0.0);
    glVertex3f (-330.0, -500.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-250.0, -450.0, 0.0);
    glVertex3f (-285.0, -350.0, 0.0);
    glVertex3f (-320.0, -450.0, 0.0);
    glEnd();
    //tree-3
    glColor3f (0.380, 0.247, 0.101);
    glBegin(GL_QUADS);
    glVertex3f (-170.0, -700.0, 0.0);
    glVertex3f (-180.0, -550.0, 0.0);
    glVertex3f (-210.0, -550.0, 0.0);
    glVertex3f (-220.0, -700.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-150.0, -550.0, 0.0);
    glVertex3f (-195.0, -450.0, 0.0);
    glVertex3f (-240.0, -550.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-160.0, -500.0, 0.0);
    glVertex3f (-195.0, -400.0, 0.0);
    glVertex3f (-230.0, -500.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-170.0, -450.0, 0.0);
    glVertex3f (-195.0, -350.0, 0.0);
    glVertex3f (-220.0, -450.0, 0.0);
    glEnd();

    //Grass-1
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-400.0, -780.0, 0.0);
    glVertex3f (-410.0, -720.0, 0.0);
    glVertex3f (-420.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-410.0, -780.0, 0.0);
    glVertex3f (-430.0, -720.0, 0.0);
    glVertex3f (-430.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-390.0, -780.0, 0.0);
    glVertex3f (-390.0, -720.0, 0.0);
    glVertex3f (-410.0, -780.0, 0.0);
    glEnd();

    //Grass-2
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-300.0, -780.0, 0.0);
    glVertex3f (-310.0, -720.0, 0.0);
    glVertex3f (-320.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-310.0, -780.0, 0.0);
    glVertex3f (-330.0, -720.0, 0.0);
    glVertex3f (-330.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-290.0, -780.0, 0.0);
    glVertex3f (-290.0, -720.0, 0.0);
    glVertex3f (-310.0, -780.0, 0.0);
    glEnd();


    //Grass-3
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-200.0, -780.0, 0.0);
    glVertex3f (-210.0, -720.0, 0.0);
    glVertex3f (-220.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-210.0, -780.0, 0.0);
    glVertex3f (-230.0, -720.0, 0.0);
    glVertex3f (-230.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-190.0, -780.0, 0.0);
    glVertex3f (-190.0, -720.0, 0.0);
    glVertex3f (-210.0, -780.0, 0.0);
    glEnd();

    //Grass-4
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-200.0, -880.0, 0.0);
    glVertex3f (-210.0, -820.0, 0.0);
    glVertex3f (-220.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-210.0, -880.0, 0.0);
    glVertex3f (-230.0, -820.0, 0.0);
    glVertex3f (-230.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-190.0, -880.0, 0.0);
    glVertex3f (-190.0, -820.0, 0.0);
    glVertex3f (-210.0, -880.0, 0.0);
    glEnd();

    //Grass-5
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-200.0, -980.0, 0.0);
    glVertex3f (-210.0, -920.0, 0.0);
    glVertex3f (-220.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-210.0, -980.0, 0.0);
    glVertex3f (-230.0, -920.0, 0.0);
    glVertex3f (-230.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-190.0, -980.0, 0.0);
    glVertex3f (-190.0, -920.0, 0.0);
    glVertex3f (-210.0, -980.0, 0.0);
    glEnd();

    //Grass-6
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-300.0, -980.0, 0.0);
    glVertex3f (-310.0, -920.0, 0.0);
    glVertex3f (-320.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-310.0, -980.0, 0.0);
    glVertex3f (-330.0, -920.0, 0.0);
    glVertex3f (-330.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-290.0, -980.0, 0.0);
    glVertex3f (-290.0, -920.0, 0.0);
    glVertex3f (-310.0, -980.0, 0.0);
    glEnd();

    //Grass-7
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-300.0, -880.0, 0.0);
    glVertex3f (-310.0, -820.0, 0.0);
    glVertex3f (-320.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-310.0, -880.0, 0.0);
    glVertex3f (-330.0, -820.0, 0.0);
    glVertex3f (-330.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-290.0, -880.0, 0.0);
    glVertex3f (-290.0, -820.0, 0.0);
    glVertex3f (-310.0, -880.0, 0.0);
    glEnd();

    //Grass-8
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-390.0, -880.0, 0.0);
    glVertex3f (-400.0, -820.0, 0.0);
    glVertex3f (-410.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-400.0, -880.0, 0.0);
    glVertex3f (-420.0, -820.0, 0.0);
    glVertex3f (-420.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-380.0, -880.0, 0.0);
    glVertex3f (-380.0, -820.0, 0.0);
    glVertex3f (-400.0, -880.0, 0.0);
    glEnd();

    //Grass-9
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-380.0, -980.0, 0.0);
    glVertex3f (-390.0, -920.0, 0.0);
    glVertex3f (-400.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-390.0, -980.0, 0.0);
    glVertex3f (-410.0, -920.0, 0.0);
    glVertex3f (-410.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-370.0, -980.0, 0.0);
    glVertex3f (-370.0, -920.0, 0.0);
    glVertex3f (-390.0, -980.0, 0.0);
    glEnd();

    //Grass-10
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-770.0, -780.0, 0.0);
    glVertex3f (-780.0, -720.0, 0.0);
    glVertex3f (-790.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-780.0, -780.0, 0.0);
    glVertex3f (-800.0, -720.0, 0.0);
    glVertex3f (-800.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-760.0, -780.0, 0.0);
    glVertex3f (-760.0, -720.0, 0.0);
    glVertex3f (-780.0, -780.0, 0.0);
    glEnd();

    //Grass-11
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-870.0, -780.0, 0.0);
    glVertex3f (-880.0, -720.0, 0.0);
    glVertex3f (-890.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-880.0, -780.0, 0.0);
    glVertex3f (-900.0, -720.0, 0.0);
    glVertex3f (-900.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-860.0, -780.0, 0.0);
    glVertex3f (-860.0, -720.0, 0.0);
    glVertex3f (-880.0, -780.0, 0.0);
    glEnd();

    //Grass-12
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-960.0, -780.0, 0.0);
    glVertex3f (-970.0, -720.0, 0.0);
    glVertex3f (-980.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-970.0, -780.0, 0.0);
    glVertex3f (-990.0, -720.0, 0.0);
    glVertex3f (-990.0, -780.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-950.0, -780.0, 0.0);
    glVertex3f (-950.0, -720.0, 0.0);
    glVertex3f (-970.0, -780.0, 0.0);
    glEnd();

    //Grass-13
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-960.0, -880.0, 0.0);
    glVertex3f (-970.0, -820.0, 0.0);
    glVertex3f (-980.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-970.0, -880.0, 0.0);
    glVertex3f (-990.0, -820.0, 0.0);
    glVertex3f (-990.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-950.0, -880.0, 0.0);
    glVertex3f (-950.0, -820.0, 0.0);
    glVertex3f (-970.0, -880.0, 0.0);
    glEnd();

    //Grass-14
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-960.0, -980.0, 0.0);
    glVertex3f (-970.0, -920.0, 0.0);
    glVertex3f (-980.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-970.0, -980.0, 0.0);
    glVertex3f (-990.0, -920.0, 0.0);
    glVertex3f (-990.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-950.0, -980.0, 0.0);
    glVertex3f (-950.0, -920.0, 0.0);
    glVertex3f (-970.0, -980.0, 0.0);
    glEnd();

    //Grass-15
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-870.0, -980.0, 0.0);
    glVertex3f (-880.0, -920.0, 0.0);
    glVertex3f (-890.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-880.0, -980.0, 0.0);
    glVertex3f (-900.0, -920.0, 0.0);
    glVertex3f (-900.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-860.0, -980.0, 0.0);
    glVertex3f (-860.0, -920.0, 0.0);
    glVertex3f (-880.0, -980.0, 0.0);
    glEnd();

    //Grass-16
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-870.0, -880.0, 0.0);
    glVertex3f (-880.0, -820.0, 0.0);
    glVertex3f (-890.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-880.0, -880.0, 0.0);
    glVertex3f (-900.0, -820.0, 0.0);
    glVertex3f (-900.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-860.0, -880.0, 0.0);
    glVertex3f (-860.0, -820.0, 0.0);
    glVertex3f (-880.0, -880.0, 0.0);
    glEnd();

    //Grass-17
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-780.0, -880.0, 0.0);
    glVertex3f (-790.0, -820.0, 0.0);
    glVertex3f (-800.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-790.0, -880.0, 0.0);
    glVertex3f (-810.0, -820.0, 0.0);
    glVertex3f (-810.0, -880.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-770.0, -880.0, 0.0);
    glVertex3f (-770.0, -820.0, 0.0);
    glVertex3f (-790.0, -880.0, 0.0);
    glEnd();

    //Grass-18
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-795.0, -980.0, 0.0);
    glVertex3f (-805.0, -920.0, 0.0);
    glVertex3f (-815.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-805.0, -980.0, 0.0);
    glVertex3f (-825.0, -920.0, 0.0);
    glVertex3f (-825.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-785.0, -980.0, 0.0);
    glVertex3f (-785.0, -920.0, 0.0);
    glVertex3f (-805.0, -980.0, 0.0);
    glEnd();

    //Grass-19
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-400.0, -210.0, 0.0);
    glVertex3f (-410.0, -150.0, 0.0);
    glVertex3f (-420.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-410.0, -210.0, 0.0);
    glVertex3f (-430.0, -150.0, 0.0);
    glVertex3f (-430.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-390.0, -210.0, 0.0);
    glVertex3f (-390.0, -150.0, 0.0);
    glVertex3f (-410.0, -210.0, 0.0);
    glEnd();

    //Grass-20
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-300.0, -210.0, 0.0);
    glVertex3f (-310.0, -150.0, 0.0);
    glVertex3f (-320.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-310.0, -210.0, 0.0);
    glVertex3f (-330.0, -150.0, 0.0);
    glVertex3f (-330.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-290.0, -210.0, 0.0);
    glVertex3f (-290.0, -150.0, 0.0);
    glVertex3f (-310.0, -210.0, 0.0);
    glEnd();

    //Grass-21
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-200.0, -210.0, 0.0);
    glVertex3f (-210.0, -150.0, 0.0);
    glVertex3f (-220.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-210.0, -210.0, 0.0);
    glVertex3f (-230.0, -150.0, 0.0);
    glVertex3f (-230.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-190.0, -210.0, 0.0);
    glVertex3f (-190.0, -150.0, 0.0);
    glVertex3f (-210.0, -210.0, 0.0);
    glEnd();

    //Grass-22
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-480.0, -210.0, 0.0);
    glVertex3f (-490.0, -150.0, 0.0);
    glVertex3f (-500.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-490.0, -210.0, 0.0);
    glVertex3f (-510.0, -150.0, 0.0);
    glVertex3f (-510.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-470.0, -210.0, 0.0);
    glVertex3f (-470.0, -150.0, 0.0);
    glVertex3f (-490.0, -210.0, 0.0);
    glEnd();

    //Grass-23
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-700.0, -210.0, 0.0);
    glVertex3f (-710.0, -150.0, 0.0);
    glVertex3f (-720.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-710.0, -210.0, 0.0);
    glVertex3f (-730.0, -150.0, 0.0);
    glVertex3f (-730.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-690.0, -210.0, 0.0);
    glVertex3f (-690.0, -150.0, 0.0);
    glVertex3f (-710.0, -210.0, 0.0);
    glEnd();

    //Grass-24
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-780.0, -210.0, 0.0);
    glVertex3f (-790.0, -150.0, 0.0);
    glVertex3f (-800.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-790.0, -210.0, 0.0);
    glVertex3f (-810.0, -150.0, 0.0);
    glVertex3f (-810.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-770.0, -210.0, 0.0);
    glVertex3f (-770.0, -150.0, 0.0);
    glVertex3f (-790.0, -210.0, 0.0);
    glEnd();

    //Grass-25
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-940.0, -210.0, 0.0);
    glVertex3f (-950.0, -150.0, 0.0);
    glVertex3f (-960.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-950.0, -210.0, 0.0);
    glVertex3f (-970.0, -150.0, 0.0);
    glVertex3f (-970.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-930.0, -210.0, 0.0);
    glVertex3f (-930.0, -150.0, 0.0);
    glVertex3f (-950.0, -210.0, 0.0);
    glEnd();

    //Grass-26
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-940.0, -310.0, 0.0);
    glVertex3f (-950.0, -250.0, 0.0);
    glVertex3f (-960.0, -310.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-950.0, -310.0, 0.0);
    glVertex3f (-970.0, -250.0, 0.0);
    glVertex3f (-970.0, -310.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-930.0, -310.0, 0.0);
    glVertex3f (-930.0, -250.0, 0.0);
    glVertex3f (-950.0, -310.0, 0.0);
    glEnd();

    //Grass-27
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-860.0, -310.0, 0.0);
    glVertex3f (-870.0, -250.0, 0.0);
    glVertex3f (-880.0, -310.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-870.0, -310.0, 0.0);
    glVertex3f (-890.0, -250.0, 0.0);
    glVertex3f (-890.0, -310.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-850.0, -310.0, 0.0);
    glVertex3f (-850.0, -250.0, 0.0);
    glVertex3f (-870.0, -310.0, 0.0);
    glEnd();

    //Grass-28
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-860.0, -210.0, 0.0);
    glVertex3f (-870.0, -150.0, 0.0);
    glVertex3f (-880.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-870.0, -210.0, 0.0);
    glVertex3f (-890.0, -150.0, 0.0);
    glVertex3f (-890.0, -210.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-850.0, -210.0, 0.0);
    glVertex3f (-850.0, -150.0, 0.0);
    glVertex3f (-870.0, -210.0, 0.0);
    glEnd();

    //Grass-29
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-200.0, -310.0, 0.0);
    glVertex3f (-210.0, -250.0, 0.0);
    glVertex3f (-220.0, -310.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-210.0, -310.0, 0.0);
    glVertex3f (-230.0, -250.0, 0.0);
    glVertex3f (-230.0, -310.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-190.0, -310.0, 0.0);
    glVertex3f (-190.0, -250.0, 0.0);
    glVertex3f (-210.0, -310.0, 0.0);
    glEnd();

    //Grass-30
    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-300.0, -310.0, 0.0);
    glVertex3f (-310.0, -250.0, 0.0);
    glVertex3f (-320.0, -310.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-310.0, -310.0, 0.0);
    glVertex3f (-330.0, -250.0, 0.0);
    glVertex3f (-330.0, -310.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    glBegin(GL_TRIANGLES);
    glVertex3f (-290.0, -310.0, 0.0);
    glVertex3f (-290.0, -250.0, 0.0);
    glVertex3f (-310.0, -310.0, 0.0);
    glEnd();

    //tree 4
    glColor3f (0.380, 0.247, 0.101);
    glBegin(GL_QUADS);
    glVertex3f (-260.0, -980.0, 0.0);
    glVertex3f (-270.0, -830.0, 0.0);
    glVertex3f (-300.0, -830.0, 0.0);
    glVertex3f (-310.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    circle(-310,-840,50,50,500);
    circle(-260,-840,50,50,500);
    circle(-260,-780,40,40,500);
    circle(-310,-780,40,40,500);
    //tree-5
    glColor3f (0.380, 0.247, 0.101);
    glBegin(GL_QUADS);
    glVertex3f (-900.0, -980.0, 0.0);
    glVertex3f (-910.0, -830.0, 0.0);
    glVertex3f (-940.0, -830.0, 0.0);
    glVertex3f (-950.0, -980.0, 0.0);
    glEnd();

    glColor3f (0.133, 0.309, 0.070);
    circle(-950,-840,50,50,500);
    circle(-900,-840,50,50,500);
    circle(-925,-780,50,50,500);

    //hospital main body
    glColor3f (1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f (-350.0, -700.0, 0.0);
    glVertex3f (-350.0, -350.0, 0.0);
    glVertex3f (-850.0, -350.0, 0.0);
    glVertex3f (-850.0, -700.0, 0.0);
    glEnd();
    //hospital roof top
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-350.0, -350.0, 0.0);
    glVertex3f (-380.0, -300.0, 0.0);
    glVertex3f (-820.0, -300.0, 0.0);
    glVertex3f (-850.0, -350.0, 0.0);
    glEnd();
    //hospital main left-1 window
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-785.0, -370.0, 0.0);
    glVertex3f (-785.0, -410.0, 0.0);
    glVertex3f (-830.0, -410.0, 0.0);
    glVertex3f (-830.0, -370.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-785.0, -450.0, 0.0);
    glVertex3f (-785.0, -490.0, 0.0);
    glVertex3f (-830.0, -490.0, 0.0);
    glVertex3f (-830.0, -450.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-785.0, -530.0, 0.0);
    glVertex3f (-785.0, -570.0, 0.0);
    glVertex3f (-830.0, -570.0, 0.0);
    glVertex3f (-830.0, -530.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-785.0, -610.0, 0.0);
    glVertex3f (-785.0, -650.0, 0.0);
    glVertex3f (-830.0, -650.0, 0.0);
    glVertex3f (-830.0, -610.0, 0.0);
    glEnd();

    //hospital main right-1 window
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-720.0, -370.0, 0.0);
    glVertex3f (-720.0, -410.0, 0.0);
    glVertex3f (-765.0, -410.0, 0.0);
    glVertex3f (-765.0, -370.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-720.0, -450.0, 0.0);
    glVertex3f (-720.0, -490.0, 0.0);
    glVertex3f (-765.0, -490.0, 0.0);
    glVertex3f (-765.0, -450.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-720.0, -530.0, 0.0);
    glVertex3f (-720.0, -570.0, 0.0);
    glVertex3f (-765.0, -570.0, 0.0);
    glVertex3f (-765.0, -530.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-720.0, -610.0, 0.0);
    glVertex3f (-720.0, -650.0, 0.0);
    glVertex3f (-765.0, -650.0, 0.0);
    glVertex3f (-765.0, -610.0, 0.0);
    glEnd();

    //hospital main left-2 window
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-435.0, -370.0, 0.0);
    glVertex3f (-435.0, -410.0, 0.0);
    glVertex3f (-480.0, -410.0, 0.0);
    glVertex3f (-480.0, -370.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-435.0, -450.0, 0.0);
    glVertex3f (-435.0, -490.0, 0.0);
    glVertex3f (-480.0, -490.0, 0.0);
    glVertex3f (-480.0, -450.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-435.0, -530.0, 0.0);
    glVertex3f (-435.0, -570.0, 0.0);
    glVertex3f (-480.0, -570.0, 0.0);
    glVertex3f (-480.0, -530.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-435.0, -610.0, 0.0);
    glVertex3f (-435.0, -650.0, 0.0);
    glVertex3f (-480.0, -650.0, 0.0);
    glVertex3f (-480.0, -610.0, 0.0);
    glEnd();

    //hospital main right-2 window
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, -370.0, 0.0);
    glVertex3f (-370.0, -410.0, 0.0);
    glVertex3f (-415.0, -410.0, 0.0);
    glVertex3f (-415.0, -370.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, -450.0, 0.0);
    glVertex3f (-370.0, -490.0, 0.0);
    glVertex3f (-415.0, -490.0, 0.0);
    glVertex3f (-415.0, -450.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, -530.0, 0.0);
    glVertex3f (-370.0, -570.0, 0.0);
    glVertex3f (-415.0, -570.0, 0.0);
    glVertex3f (-415.0, -530.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, -610.0, 0.0);
    glVertex3f (-370.0, -650.0, 0.0);
    glVertex3f (-415.0, -650.0, 0.0);
    glVertex3f (-415.0, -610.0, 0.0);
    glEnd();
    //hospital door
    glColor3f (0.380, 0.113, 0.686);
    glBegin(GL_QUADS);
    glVertex3f (-500.0, -700.0, 0.0);
    glVertex3f (-500.0, -450.0, 0.0);
    glVertex3f (-700.0, -450.0, 0.0);
    glVertex3f (-700.0, -700.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-490.0, -450.0, 0.0);
    glVertex3f (-490.0, -470.0, 0.0);
    glVertex3f (-710.0, -470.0, 0.0);
    glVertex3f (-710.0, -450.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-595.0, -700.0, 0.0);
    glVertex3f (-595.0, -450.0, 0.0);
    glVertex3f (-605.0, -450.0, 0.0);
    glVertex3f (-605.0, -700.0, 0.0);
    glEnd();
    //hospital stair
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-500.0, -680.0, 0.0);
    glVertex3f (-500.0, -660.0, 0.0);
    glVertex3f (-700.0, -660.0, 0.0);
    glVertex3f (-700.0, -680.0, 0.0);
    glEnd();

    glColor3f (0.039, 0.039, 0.039);
    glBegin(GL_QUADS);
    glVertex3f (-500.0, -680.0, 0.0);
    glVertex3f (-500.0, -678.0, 0.0);
    glVertex3f (-700.0, -678.0, 0.0);
    glVertex3f (-700.0, -680.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-480.0, -700.0, 0.0);
    glVertex3f (-480.0, -680.0, 0.0);
    glVertex3f (-720.0, -680.0, 0.0);
    glVertex3f (-720.0, -700.0, 0.0);
    glEnd();

    //hospital top part
    glColor3f (1.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-520.0, -450.0, 0.0);
    glVertex3f (-520.0, -250.0, 0.0);
    glVertex3f (-680.0, -250.0, 0.0);
    glVertex3f (-680.0, -450.0, 0.0);
    glEnd();
    //hospital top part roof top
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-520.0, -250.0, 0.0);
    glVertex3f (-540.0, -200.0, 0.0);
    glVertex3f (-660.0, -200.0, 0.0);
    glVertex3f (-680.0, -250.0, 0.0);
    glEnd();
    //hospital top part window
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-610.0, -430.0, 0.0);
    glVertex3f (-610.0, -390.0, 0.0);
    glVertex3f (-660.0, -390.0, 0.0);
    glVertex3f (-660.0, -430.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (-540.0, -430.0, 0.0);
    glVertex3f (-540.0, -390.0, 0.0);
    glVertex3f (-590.0, -390.0, 0.0);
    glVertex3f (-590.0, -430.0, 0.0);
    glEnd();

}

///Sun start
void sun(int x,int y)
{
   float theta;
   glBegin(GL_POLYGON);
   //glColor3f(0.988, 0.980, 0.631);
   for(int i=0;i<360;i++)
   {
       theta=i*(3.1416/180);
       glVertex2f(x+60*cos(theta),y+60*sin(theta));
   }

   glEnd();

}
void arrow_key(int key, int x, int y)
{

    switch (key)
    {

    case GLUT_KEY_DOWN:
        ty -=5;
        glutPostRedisplay();
        break;


    case GLUT_KEY_UP:
        ty +=5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_LEFT:
			glutIdleFunc(object_left);
			break;

    case GLUT_KEY_RIGHT:
			glutIdleFunc(object_right);
			break;

    default:
        break;
    }
}

///Sun End

/// Car Start
void wheel(int x,int y)
{
   float theta;
   glBegin(GL_POLYGON);
   glColor3f(0.043, 0.2, 0.258);
   for(int i=0;i<360;i++)
   {
       theta=i*(3.1416/180);
       glVertex2f(x+25*cos(theta),y+25*sin(theta));
   }

   glEnd();

}

void car1()
{

    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();

    counter_car1=counter_car1-0.5;
        if(counter_car1<=-2000)
        {
            counter_car1=1000;
        }

    glTranslated(counter_car1,-10,0.0);

          //car light
   glColor3f (1,1,1);
   circle(570,105,15,10,500);
   circle(560,75,15,10,500);

   //car Body
   glBegin(GL_POLYGON);
   glColor3f(1.0,0.0,1.0);
   glVertex3f(550.0, 60.0, 0.0);
   glVertex3f(570.0, 120.0, 0.0);
   glVertex3f(950.0 ,120.0, 0.0);
   glVertex3f(950.0, 60.0, 0.0);

   //car Top
   glBegin(GL_POLYGON);
   glColor3f(1,1,1);
   glVertex3f(650.0, 120.0, 0.0);
   glVertex3f(700.0, 170.0, 0.0);
   glVertex3f(850.0, 170.0, 0.0);
   glVertex3f(900.0, 120.0, 0.0);

   //car window
   glColor3f (0.0, 255.0, 255.0);
   glBegin(GL_QUADS);
   glVertex3f(670, 120, 0);
   glVertex3f(710, 160, 0);
   glVertex3f(760, 160, 0);
   glVertex3f(760, 120, 0);

   glColor3f (0.0, 255.0, 255.0);
   glBegin(GL_QUADS);
   glVertex3f(775, 120, 0);
   glVertex3f(775, 160, 0);
   glVertex3f(840, 160, 0);
   glVertex3f(880, 120, 0);


   glEnd();

   wheel(700,70);
   wheel(850,70);

   glColor3f (0.294, 0.388, 0.384);
   circle(700,70,20,20,500);
   circle(850,70,20,20,500);

   glColor3f(0.043, 0.2, 0.258);
   circle(700,70,15,15,500);
   circle(850,70,15,15,500);

   glPopMatrix();

}

void car2()
{

    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();

    counter_car2=counter_car2+0.4;
        if(counter_car2>=2000)
        {
            counter_car2=-1000;
        }

    glTranslated(counter_car2,-90,0.0);

    //car light
   glColor3f (1,1,1);
   circle(-570,55,15,10,500);
   circle(-560,25,15,10,500);

   //car Body
   glBegin(GL_POLYGON);
   glColor3f(1.0,1.0,0.0);
   glVertex3f(-550, 10, 0);
   glVertex3f(-570, 70, 0);
   glVertex3f(-950, 70, 0);
   glVertex3f(-950, 10, 0);

   //car Top
   glColor3f(1.0,1.0,0.0);
   glBegin(GL_POLYGON);
   glVertex3f(-650, 70, 0);
   glVertex3f(-700, 120, 0);
   glVertex3f(-850, 120, 0);
   glVertex3f(-900, 70, 0);

   //car window
   glColor3f (0.0, 255.0, 255.0);
   glBegin(GL_QUADS);
   glVertex3f(-670, 70, 0);
   glVertex3f(-710, 110, 0);
   glVertex3f(-760, 110, 0);
   glVertex3f(-760, 70, 0);

   glColor3f (0.0, 255.0, 255.0);
   glBegin(GL_QUADS);
   glVertex3f(-775, 70, 0);
   glVertex3f(-775, 110, 0);
   glVertex3f(-840, 110, 0);
   glVertex3f(-880, 70, 0);


   glEnd();

   wheel(-700,20);
   wheel(-850,20);

   glColor3f (0.294, 0.388, 0.384);
   circle(-700,20,20,20,500);
   circle(-850,20,20,20,500);

   glColor3f(0.043, 0.2, 0.258);
   circle(-700,20,15,15,500);
   circle(-850,20,15,15,500);

   glPopMatrix();

}

void car3()
{

    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    counter_car3=counter_car3+0.09;
        if(counter_car3>=2000)
        {
            counter_car3=-1000;
        }
    glTranslated(counter_car3,-90,0.0);

   //car Body
   glColor3f(0.592, 0.309, 0.890);
   glBegin(GL_POLYGON);
   glVertex3f(-50, 10, 0);
   glVertex3f(-70, 70, 0);
   glVertex3f(-450, 70, 0);
   glVertex3f(-450, 10, 0);

   //car Top
   glColor3f(1,1,1);
   glBegin(GL_POLYGON);
   glVertex3f(-150, 70, 0);
   glVertex3f(-200, 120, 0);
   glVertex3f(-350, 120, 0);
   glVertex3f(-400, 70, 0);

   //car window
   glColor3f (0.0, 255.0, 255.0);
   glBegin(GL_QUADS);
   glVertex3f(-170, 70, 0);
   glVertex3f(-210, 110, 0);
   glVertex3f(-260, 110, 0);
   glVertex3f(-260, 70, 0);

   glColor3f (0.0, 255.0, 255.0);
   glBegin(GL_QUADS);
   glVertex3f(-275, 70, 0);
   glVertex3f(-275, 110, 0);
   glVertex3f(-340, 110, 0);
   glVertex3f(-380, 70, 0);


   glEnd();

   wheel(-200,20);
   wheel(-350,20);

   glColor3f (0.294, 0.388, 0.384);
   circle(-200,20,20,20,500);
   circle(-350,20,20,20,500);

   glColor3f(0.043, 0.2, 0.258);
   circle(-200,20,15,15,500);
   circle(-350,20,15,15,500);

   glPopMatrix();

}

void car4()
{

    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();

    counter_car4=counter_car4-0.09;
        if(counter_car4<=-2000)
        {
            counter_car4=1000;
        }
    glTranslated(counter_car4,-10,0.0);

   //car Body
   glColor3f(0.431, 0.701, 0.098);
   glBegin(GL_POLYGON);
   glVertex3f(50, 60, 0);
   glVertex3f(70, 120, 0);
   glVertex3f(450, 120, 0);
   glVertex3f(450, 60, 0);

   //car Top
   glColor3f(0.431, 0.701, 0.098);
   glBegin(GL_POLYGON);
   glVertex3f(150, 120, 0);
   glVertex3f(200, 170, 0);
   glVertex3f(350, 170, 0);
   glVertex3f(400, 120, 0);

   //car window
   glColor3f (0.0, 255.0, 255.0);
   glBegin(GL_QUADS);
   glVertex3f(170, 120, 0);
   glVertex3f(210, 160, 0);
   glVertex3f(260, 160, 0);
   glVertex3f(260, 120, 0);

   glColor3f (0.0, 255.0, 255.0);
   glBegin(GL_QUADS);
   glVertex3f(275, 120, 0);
   glVertex3f(275, 160, 0);
   glVertex3f(340, 160, 0);
   glVertex3f(380, 120, 0);


   glEnd();

   wheel(200,70);
   wheel(350,70);

   glColor3f (0.294, 0.388, 0.384);
   circle(200,70,20,20,500);
   circle(350,70,20,20,500);

   glColor3f(0.043, 0.2, 0.258);
   circle(200,70,15,15,500);
   circle(350,70,15,15,500);

   glPopMatrix();

}

///Car End

///Building flag circle
void building_flag(int x,int y)
{
   float theta;
   glBegin(GL_POLYGON);
   for(int i=0;i<360;i++)
   {
       theta=i*(3.1416/180);
       glVertex2f(x+30*cos(theta),y+30*sin(theta));
   }

   glEnd();

}
///Building flag circle End

///helicopter Start

void helicopter()
{
    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    helicopter1=helicopter1+0.3;
        if(helicopter1>=2000)
        {
            helicopter1=-1000;
        }

    glTranslated(helicopter1,0,0.0);

    //helicopter bottom part
    glColor3f (1.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (-700.0, 830.0, 0.0);
    glVertex3f (-710.0, 870.0, 0.0);
    glVertex3f (-840.0, 870.0, 0.0);
    glVertex3f (-830.0, 830.0, 0.0);
    glEnd();

    //helicopter wheel
    glColor3f (1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (-730.0, 810.0, 0.0);
    glVertex3f (-730.0, 830.0, 0.0);
    glVertex3f (-750.0, 830.0, 0.0);
    glVertex3f (-750.0, 810.0, 0.0);
    glEnd();

    glColor3f (1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (-780.0, 810.0, 0.0);
    glVertex3f (-780.0, 830.0, 0.0);
    glVertex3f (-800.0, 830.0, 0.0);
    glVertex3f (-800.0, 810.0, 0.0);
    glEnd();
    //helicopter top part
    glColor3f (1.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (-740.0, 870.0, 0.0);
    glVertex3f (-750.0, 910.0, 0.0);
    glVertex3f (-950.0, 910.0, 0.0);
    glVertex3f (-940.0, 870.0, 0.0);
    glEnd();
    //helicopter top window
    glColor3f (1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (-755.0, 880.0, 0.0);
    glVertex3f (-760.0, 900.0, 0.0);
    glVertex3f (-790.0, 900.0, 0.0);
    glVertex3f (-790.0, 880.0, 0.0);
    glEnd();

    glColor3f (1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (-800.0, 880.0, 0.0);
    glVertex3f (-800.0, 900.0, 0.0);
    glVertex3f (-830.0, 900.0, 0.0);
    glVertex3f (-830.0, 880.0, 0.0);
    glEnd();

    glColor3f (0.945, 0.776, 0.819);
    circle(-950,915,25,25,500);

    glColor3f (0.945, 0.776, 0.819);
    circle(-800,935,35,25,500);

    glPopMatrix();
}
///Cloud Function Start
void cloudDraw(int x,int y)
{
   float theta;
   glBegin(GL_POLYGON);
   for(int i=0;i<360;i++)
   {
       theta=i*(3.1416/180);
       glVertex2f(x+65*cos(theta),y+45*sin(theta));
   }

   glEnd();

}
///Cloud function End

///Moon function Start
void moon(int x,int y)
{
   float theta;
   glBegin(GL_POLYGON);
   for(int i=0;i<360;i++)
   {
       theta=i*(3.1416/180);
       glVertex2f(x+65*cos(theta),y+65*sin(theta));
   }

   glEnd();

}
///Moon function End


void show(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    if(flag<=1)
    {
        ///Sky blue
        flag+=0.0005;

        glColor3f (0.286, 0.4, 0.972);
        glBegin(GL_QUADS);
        glVertex3f (1000.0, 300.0, 0.0);
        glVertex3f (1000.0, 1000.0, 0.0);
        glVertex3f (-1000.0, 1000.0, 0.0);
        glVertex3f (-1000.0, 300.0, 0.0);
        glEnd();

        ///rainbow
        glColor3f(1,0,0);
        circle(0,0,950,950,1000);
        glColor3f(0.956, 0.505, 0.121);
        circle(0,0,930,930,1000);
        glColor3f(1,1,0);
        circle(0,0,910,910,1000);
        glColor3f(0,1,0);
        circle(0,0,890,890,1000);
        glColor3f(0,1,1);
        circle(0,0,870,870,1000);
        glColor3f(0,0,1);
        circle(0,0,850,850,1000);
        glColor3f(0.180, 0.043, 0.576);
        circle(0,0,830,830,1000);
        glColor3f(0.286, 0.4, 0.972);
        circle(0,0,810,810,1000);


        ///field green
        glColor3f (0.0, 1.0, 0.0);
        glBegin(GL_QUADS);
        glVertex3f (-140.0, -140.0, 0.0);
        glVertex3f (-140.0, -1000.0, 0.0);
        glVertex3f (-1000.0, -1000.0, 0.0);
        glVertex3f (-1000.0, -140.0, 0.0);
        glEnd();

        /// Sea blue
        glColor3f (0.070, 0.596, 0.929);
        glBegin(GL_QUADS);
        glVertex3f (140.0, -140.0, 0.0);
        glVertex3f (140.0, -1000.0, 0.0);
        glVertex3f (1000.0, -1000.0, 0.0);
        glVertex3f (1000.0, -140.0, 0.0);
        glEnd();

        ///Sun yellow
        glPushMatrix();
        glTranslatef(tx,ty,0);
        glColor3f(0.988, 0.980, 0.631);
        sun(800,850);
        glPopMatrix();

        ///cloud-position

        //cloud-1
        glPushMatrix();
        glLoadIdentity();
        cloud1=cloud1+0.2;
        if(cloud1>=2000)
        {
            cloud1=0;
        }
        glTranslated(cloud1,0,0.0);

        glColor3f(1.0, 1.0, 1.0);
        cloudDraw(500,850);
        cloudDraw(600,850);
        cloudDraw(450,800);
        cloudDraw(550,800);
        cloudDraw(650,800);

        glPopMatrix();

        //cloud-2
        glPushMatrix();
        glLoadIdentity();
        cloud2=cloud2+0.08;
        if(cloud2>=2000)
        {
            cloud2=-2000;
        }
        glTranslated(cloud2,0,0.0);
        glColor3f(1.0, 1.0, 1.0);

        cloudDraw(-700,850);
        cloudDraw(-800,850);
        cloudDraw(-650,800);
        cloudDraw(-750,800);
        cloudDraw(-850,800);

        glPopMatrix();

        //cloud-3
        glPushMatrix();
        glLoadIdentity();
        cloud3=cloud3+0.1;
        if(cloud3>=2000)
        {
            cloud3=-2000;
        }
        glTranslated(cloud3,0,0.0);
        glColor3f(1.0, 1.0, 1.0);

        cloudDraw(-200,920);
        cloudDraw(-300,920);
        cloudDraw(-150,870);
        cloudDraw(-250,870);
        cloudDraw(-350,870);

        glPopMatrix();

        //cloud-4
        glPushMatrix();
        glLoadIdentity();
        cloud4=cloud4+0.08;
        if(cloud4>=3500)
        {
            cloud4=0;
        }
        glTranslated(cloud4,0,0.0);
        glColor3f(1.0, 1.0, 1.0);

        cloudDraw(-1200,920);
        cloudDraw(-1300,920);
        cloudDraw(-1150,870);
        cloudDraw(-1250,870);
        cloudDraw(-1350,870);

        glPopMatrix();

        //cloud-5
        glPushMatrix();
        glLoadIdentity();
        cloud5=cloud5+0.06;
        if(cloud5>=3500)
        {
            cloud5=0;
        }
        glTranslated(cloud5,0,0.0);
        glColor3f(1.0, 1.0, 1.0);

        cloudDraw(-1700,850);
        cloudDraw(-1800,850);
        cloudDraw(-1650,800);
        cloudDraw(-1750,800);
        cloudDraw(-1850,800);

        glPopMatrix();

        //cloud-6
        glPushMatrix();
        glLoadIdentity();
        cloud6=cloud6+0.04;
        if(cloud6>=3500)
        {
            cloud6=0;
        }
        glTranslated(cloud6,0,0.0);
        glColor3f(1.0, 1.0, 1.0);

        cloudDraw(-2300,920);
        cloudDraw(-2400,920);
        cloudDraw(-2250,870);
        cloudDraw(-2350,870);
        cloudDraw(-2450,870);

        glPopMatrix();

    }
    else
    {
        ///Sky black
        if(flag>=2)
        {
            flag=0;
        }
        flag+=0.0003;
        glColor3f (0.0, 0.0, 0.0);
        glBegin(GL_QUADS);
        glVertex3f (1000.0, 300.0, 0.0);
        glVertex3f (1000.0, 1000.0, 0.0);
        glVertex3f (-1000.0, 1000.0, 0.0);
        glVertex3f (-1000.0, 300.0, 0.0);
        glEnd();

        ///Star-1
        glColor3f(1,1,1);
        glBegin(GL_TRIANGLES);
        glVertex2f(660,645);
        glVertex2f(690,645);
        glVertex2f(675,675);

        glVertex2f(660,660);
        glVertex2f(690,660);
        glVertex2f(675,635);
        glEnd();

        ///Star-2
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-660,645);
        glVertex2f(-690,645);
        glVertex2f(-675,675);

        glVertex2f(-660,660);
        glVertex2f(-690,660);
        glVertex2f(-675,635);
        glEnd();

        ///Star-3
        glColor3f(1.0,1.0,0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-760,745);
        glVertex2f(-790,745);
        glVertex2f(-775,770);

        glVertex2f(-760,760);
        glVertex2f(-790,760);
        glVertex2f(-775,735);
        glEnd();

        ///Star-4
        glColor3f(1.0,1.0,0);
        glBegin(GL_TRIANGLES);
        glVertex2f(760,745);
        glVertex2f(790,745);
        glVertex2f(775,770);

        glVertex2f(760,760);
        glVertex2f(790,760);
        glVertex2f(775,735);
        glEnd();

        ///Star-5
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(550,845);
        glVertex2f(600,845);
        glVertex2f(575,885);

        glVertex2f(550,870);
        glVertex2f(600,870);
        glVertex2f(575,830);
        glEnd();

        ///Star-6
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-550,845);
        glVertex2f(-600,845);
        glVertex2f(-575,885);

        glVertex2f(-550,870);
        glVertex2f(-600,870);
        glVertex2f(-575,830);
        glEnd();

        ///Star-6
        glColor3f(1.0,1.0,0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-460,745);
        glVertex2f(-490,745);
        glVertex2f(-475,770);

        glVertex2f(-460,760);
        glVertex2f(-490,760);
        glVertex2f(-475,735);
        glEnd();

        ///Star-7
        glColor3f(1.0,1.0,0);
        glBegin(GL_TRIANGLES);
        glVertex2f(460,745);
        glVertex2f(490,745);
        glVertex2f(475,770);

        glVertex2f(460,760);
        glVertex2f(490,760);
        glVertex2f(475,735);
        glEnd();

        ///Star-8
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(360,845);
        glVertex2f(390,845);
        glVertex2f(375,870);

        glVertex2f(360,860);
        glVertex2f(390,860);
        glVertex2f(375,835);
        glEnd();

        ///Star-9
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-360,845);
        glVertex2f(-390,845);
        glVertex2f(-375,875);

        glVertex2f(-360,860);
        glVertex2f(-390,860);
        glVertex2f(-375,835);
        glEnd();

        ///Star-10
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-160,845);
        glVertex2f(-190,845);
        glVertex2f(-175,870);

        glVertex2f(-160,860);
        glVertex2f(-190,860);
        glVertex2f(-175,835);
        glEnd();

        ///Star-11
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(360,845);
        glVertex2f(390,845);
        glVertex2f(375,870);

        glVertex2f(360,860);
        glVertex2f(390,860);
        glVertex2f(375,835);
        glEnd();

        ///Star-12
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(160,845);
        glVertex2f(190,845);
        glVertex2f(175,870);

        glVertex2f(160,860);
        glVertex2f(190,860);
        glVertex2f(175,835);
        glEnd();

        ///Star-13
        glColor3f(1.0,1.0,0);
        glBegin(GL_TRIANGLES);
        glVertex2f(10,900);
        glVertex2f(40,900);
        glVertex2f(25,925);

        glVertex2f(10,915);
        glVertex2f(40,915);
        glVertex2f(25,890);
        glEnd();

        ///Star-14
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(860,900);
        glVertex2f(890,900);
        glVertex2f(875,925);

        glVertex2f(860,915);
        glVertex2f(890,915);
        glVertex2f(875,890);
        glEnd();

         ///Star-15
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-860,900);
        glVertex2f(-890,900);
        glVertex2f(-875,925);

        glVertex2f(-860,915);
        glVertex2f(-890,915);
        glVertex2f(-875,890);
        glEnd();

         ///Star-16
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-860,700);
        glVertex2f(-890,700);
        glVertex2f(-875,725);

        glVertex2f(-860,715);
        glVertex2f(-890,715);
        glVertex2f(-875,690);
        glEnd();

        ///field black
        glColor3f (0.0, 0.0, 0.0);
        glBegin(GL_QUADS);
        glVertex3f (-140.0, -140.0, 0.0);
        glVertex3f (-140.0, -1000.0, 0.0);
        glVertex3f (-1000.0, -1000.0, 0.0);
        glVertex3f (-1000.0, -140.0, 0.0);
        glEnd();

        /// Sea black
        glColor3f (0.0, 0.0, 0.0);
        glBegin(GL_QUADS);
        glVertex3f (140.0, -140.0, 0.0);
        glVertex3f (140.0, -1000.0, 0.0);
        glVertex3f (1000.0, -1000.0, 0.0);
        glVertex3f (1000.0, -140.0, 0.0);
        glEnd();

        ///Sun black
        glColor3f(0.0,0.0,0.0);
        sun(800,850);

        ///Moon white
        glColor3f(1,1,1);
        moon(-700,900);

        glColor3f(0,0,0);
        moon(-710,910);


    }


    ///Moon start
    /*glPushMatrix();
    glLoadIdentity();
    glTranslatef(tx,ty,0);
    if(mf==0)
    {
        if(ty<=-100)
        {
            mf=1;
        }
        ty=ty-0.05;
    }
    else
    {
        if(ty>=850)
        {
            mf=0;
        }
        ty=ty+0.05;
    }
    glTranslated(tx,ty,0.0);
    moon(800,850);
    glPopMatrix();*/
    ///Moon end

    ///field blue sky
    glColor3f (0.117, 0.568, 0.050);
    glBegin(GL_QUADS);
    glVertex3f (1000.0, 140.0, 0.0);
    glVertex3f (1000.0, 300.0, 0.0);
    glVertex3f (-1000.0, 300.0, 0.0);
    glVertex3f (-1000.0, 140.0, 0.0);
    glEnd();

    circle(960,300,50,50,500);
    circle(820,300,50,50,500);

    circle(-950,300,50,50,500);
    circle(-800,300,50,50,500);
    ///field blue sky End

    ///Building Start- (1)
             //Main body
    glColor3f (0.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (800.0, 140.0, 0.0);
    glVertex3f (800.0, 400.0, 0.0);
    glVertex3f (600.0, 400.0, 0.0);
    glVertex3f (600.0, 140.0, 0.0);
    glEnd();
            //Roof-top
    glColor3f (0.0, 255.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f (800.0, 400.0, 0.0);
    glVertex3f (700.0, 500.0, 0.0);
    glVertex3f (600.0, 400.0, 0.0);
    glEnd();
             //left-window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (640.0, 360.0, 0.0);
    glVertex3f (680.0, 360.0, 0.0);
    glVertex3f (680.0, 320.0, 0.0);
    glVertex3f (640.0, 320.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (640.0, 280.0, 0.0);
    glVertex3f (680.0, 280.0, 0.0);
    glVertex3f (680.0, 240.0, 0.0);
    glVertex3f (640.0, 240.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (640.0, 200.0, 0.0);
    glVertex3f (680.0, 200.0, 0.0);
    glVertex3f (680.0, 160.0, 0.0);
    glVertex3f (640.0, 160.0, 0.0);
    glEnd();
            //Right-window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (720.0, 360.0, 0.0);
    glVertex3f (760.0, 360.0, 0.0);
    glVertex3f (760.0, 320.0, 0.0);
    glVertex3f (720.0, 320.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (720.0, 280.0, 0.0);
    glVertex3f (760.0, 280.0, 0.0);
    glVertex3f (760.0, 240.0, 0.0);
    glVertex3f (720.0, 240.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (720.0, 200.0, 0.0);
    glVertex3f (760.0, 200.0, 0.0);
    glVertex3f (760.0, 160.0, 0.0);
    glVertex3f (720.0, 160.0, 0.0);
    glEnd();
    ///Building- (1) End

    ///Building -2 Start
              //main body
    glColor3f (255.0, 255.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f (600.0, 140.0, 0.0);
    glVertex3f (600.0, 600.0, 0.0);
    glVertex3f (350.0, 600.0, 0.0);
    glVertex3f (350.0, 140.0, 0.0);
    glEnd();
               //Roof-top
    glColor3f (0.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (350.0, 600.0, 0.0);
    glVertex3f (380.0, 630.0, 0.0);
    glVertex3f (570.0, 630.0, 0.0);
    glVertex3f (600.0, 600.0, 0.0);
    glEnd();

    glColor3f (0.0, 255.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f (400.0, 630.0, 0.0);
    glVertex3f (430.0, 660.0, 0.0);
    glVertex3f (520.0, 660.0, 0.0);
    glVertex3f (550.0, 630.0, 0.0);
    glEnd();
              //window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (380.0, 570.0, 0.0);
    glVertex3f (570.0, 570.0, 0.0);
    glVertex3f (570.0, 540.0, 0.0);
    glVertex3f (380.0, 540.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (380.0, 530.0, 0.0);
    glVertex3f (570.0, 530.0, 0.0);
    glVertex3f (570.0, 500.0, 0.0);
    glVertex3f (380.0, 500.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (380.0, 490.0, 0.0);
    glVertex3f (570.0, 490.0, 0.0);
    glVertex3f (570.0, 460.0, 0.0);
    glVertex3f (380.0, 460.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (380.0, 450.0, 0.0);
    glVertex3f (570.0, 450.0, 0.0);
    glVertex3f (570.0, 420.0, 0.0);
    glVertex3f (380.0, 420.0, 0.0);
    glEnd();
               //left window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (380.0, 390.0, 0.0);
    glVertex3f (455.0, 390.0, 0.0);
    glVertex3f (455.0, 340.0, 0.0);
    glVertex3f (380.0, 340.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (380.0, 310.0, 0.0);
    glVertex3f (455.0, 310.0, 0.0);
    glVertex3f (455.0, 260.0, 0.0);
    glVertex3f (380.0, 260.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (380.0, 230.0, 0.0);
    glVertex3f (455.0, 230.0, 0.0);
    glVertex3f (455.0, 180.0, 0.0);
    glVertex3f (380.0, 180.0, 0.0);
    glEnd();

            //Right window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (495.0, 390.0, 0.0);
    glVertex3f (570.0, 390.0, 0.0);
    glVertex3f (570.0, 340.0, 0.0);
    glVertex3f (495.0, 340.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (495.0, 310.0, 0.0);
    glVertex3f (570.0, 310.0, 0.0);
    glVertex3f (570.0, 260.0, 0.0);
    glVertex3f (495.0, 260.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (495.0, 230.0, 0.0);
    glVertex3f (570.0, 230.0, 0.0);
    glVertex3f (570.0, 180.0, 0.0);
    glVertex3f (495.0, 180.0, 0.0);
    glEnd();
    ///Building-2 End

    ///Building-3 Start
           //Main Building
    glColor3f (30.0, 0.0, 30.0);
    glBegin(GL_QUADS);
    glVertex3f (350.0, 140.0, 0.0);
    glVertex3f (350.0, 500.0, 0.0);
    glVertex3f (100.0, 500.0, 0.0);
    glVertex3f (100.0, 140.0, 0.0);
    glEnd();
            //Roof-top
    glColor3f (0.0, 30.0, 30.0);
    glBegin(GL_QUADS);
    glVertex3f (320.0, 500.0, 0.0);
    glVertex3f (320.0, 520.0, 0.0);
    glVertex3f (130.0, 520.0, 0.0);
    glVertex3f (130.0, 500.0, 0.0);
    glEnd();

    glColor3f (0.0, 30.0, 30.0);
    glBegin(GL_QUADS);
    glVertex3f (290.0, 520.0, 0.0);
    glVertex3f (290.0, 540.0, 0.0);
    glVertex3f (160.0, 540.0, 0.0);
    glVertex3f (160.0, 520.0, 0.0);
    glEnd();

    glColor3f (0.0, 30.0, 30.0);
    glBegin(GL_QUADS);
    glVertex3f (260.0, 540.0, 0.0);
    glVertex3f (260.0, 560.0, 0.0);
    glVertex3f (190.0, 560.0, 0.0);
    glVertex3f (190.0, 540.0, 0.0);
    glEnd();

           //window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (120.0, 480.0, 0.0);
    glVertex3f (120.0, 450.0, 0.0);
    glVertex3f (330.0, 450.0, 0.0);
    glVertex3f (330.0, 480.0, 0.0);
    glEnd();
            //Left-window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (120.0, 430.0, 0.0);
    glVertex3f (120.0, 400.0, 0.0);
    glVertex3f (330.0, 400.0, 0.0);
    glVertex3f (330.0, 430.0, 0.0);
    glEnd();
            //Right-window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (120.0, 380.0, 0.0);
    glVertex3f (120.0, 150.0, 0.0);
    glVertex3f (200.0, 150.0, 0.0);
    glVertex3f (200.0, 380.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (250.0, 380.0, 0.0);
    glVertex3f (250.0, 150.0, 0.0);
    glVertex3f (330.0, 150.0, 0.0);
    glVertex3f (330.0, 380.0, 0.0);
    glEnd();
             //flag
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f (215.0, 650.0, 0.0);
    glVertex3f (215.0, 750.0, 0.0);
    glVertex3f (350.0, 750.0, 0.0);
    glVertex3f (350.0, 650.0, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f (215.0, 560.0, 0.0);
    glVertex3f (215.0, 750.0, 0.0);
    glVertex3f (235.0, 750.0, 0.0);
    glVertex3f (235.0, 560.0, 0.0);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    building_flag(292,700);


    ///Building-3 End

    ///Building-4 start
         //Main building
    glColor3d (0.490, 0.058, 0.741);
    glBegin(GL_QUADS);
    glVertex3f (100.0, 140.0, 0.0);
    glVertex3f (100.0, 700.0, 0.0);
    glVertex3f (-300.0, 700.0, 0.0);
    glVertex3f (-300.0, 140.0, 0.0);
    glEnd();
          //Roof-top
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (120.0, 700.0, 0.0);
    glVertex3f (120.0, 720.0, 0.0);
    glVertex3f (-320.0, 720.0, 0.0);
    glVertex3f (-320.0, 700.0, 0.0);
    glEnd();

    glColor3f (0.490, 0.058, 0.741);
    glBegin(GL_QUADS);
    glVertex3f (20.0, 720.0, 0.0);
    glVertex3f (20.0, 780.0, 0.0);
    glVertex3f (-220.0, 780.0, 0.0);
    glVertex3f (-220.0, 720.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (20.0, 780.0, 0.0);
    glVertex3f (20.0, 800.0, 0.0);
    glVertex3f (-220.0, 800.0, 0.0);
    glVertex3f (-220.0, 780.0, 0.0);
    glEnd();

               //Door
    glColor3f (255.0, 255.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f (0.0, 350.0, 0.0);
    glVertex3f (0.0, 140.0, 0.0);
    glVertex3f (-200.0, 140.0, 0.0);
    glVertex3f (-200.0, 350.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-100.0, 350.0, 0.0);
    glVertex3f (-100.0, 140.0, 0.0);
    glVertex3f (-110.0, 140.0, 0.0);
    glVertex3f (-110.0, 350.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (20.0, 350.0, 0.0);
    glVertex3f (20.0, 360.0, 0.0);
    glVertex3f (-220.0, 360.0, 0.0);
    glVertex3f (-220.0, 350.0, 0.0);
    glEnd();
              //right Window
    glColor3d (255, 255, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (70.0, 680.0, 0.0);
    glVertex3f (70.0, 600.0, 0.0);
    glVertex3f (0.0, 600.0, 0.0);
    glVertex3f (0.0, 680.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (70.0, 540.0, 0.0);
    glVertex3f (70.0, 460.0, 0.0);
    glVertex3f (0.0, 460.0, 0.0);
    glVertex3f (0.0, 540.0, 0.0);
    glEnd();
               //left Window
    glColor3d (255, 255, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-270.0, 680.0, 0.0);
    glVertex3f (-270.0, 600.0, 0.0);
    glVertex3f (-200.0, 600.0, 0.0);
    glVertex3f (-200.0, 680.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-270.0, 540.0, 0.0);
    glVertex3f (-270.0, 460.0, 0.0);
    glVertex3f (-200.0, 460.0, 0.0);
    glVertex3f (-200.0, 540.0, 0.0);
    glEnd();
            //middle Window
    glColor3d (255, 255, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-65.0, 680.0, 0.0);
    glVertex3f (-65.0, 600.0, 0.0);
    glVertex3f (-135.0, 600.0, 0.0);
    glVertex3f (-135.0, 680.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-65.0, 540.0, 0.0);
    glVertex3f (-65.0, 460.0, 0.0);
    glVertex3f (-135.0, 460.0, 0.0);
    glVertex3f (-135.0, 540.0, 0.0);
    glEnd();
          //window line
    glColor3d (255, 255, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (100.0, 580.0, 0.0);
    glVertex3f (100.0, 560.0, 0.0);
    glVertex3f (-300.0, 560.0, 0.0);
    glVertex3f (-300.0, 580.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (100.0, 440.0, 0.0);
    glVertex3f (100.0, 420.0, 0.0);
    glVertex3f (-300.0, 420.0, 0.0);
    glVertex3f (-300.0, 440.0, 0.0);
    glEnd();
    ///Building-4 End

    ///Building-5 Start
         //Main building
    glColor3d (0.870, 0.176, 0.168);
    glBegin(GL_QUADS);
    glVertex3f (-300.0, 140.0, 0.0);
    glVertex3f (-300.0, 600.0, 0.0);
    glVertex3f (-550.0, 500.0, 0.0);
    glVertex3f (-550.0, 140.0, 0.0);
    glEnd();
             //Roof-top
    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-300.0, 600.0, 0.0);
    glVertex3f (-300.0, 620.0, 0.0);
    glVertex3f (-550.0, 520.0, 0.0);
    glVertex3f (-550.0, 500.0, 0.0);
    glEnd();

    glColor3d (0.870, 0.176, 0.168);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, 590.0, 0.0);
    glVertex3f (-370.0, 660.0, 0.0);
    glVertex3f (-480.0, 660.0, 0.0);
    glVertex3f (-480.0, 550.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, 660.0, 0.0);
    glVertex3f (-370.0, 680.0, 0.0);
    glVertex3f (-480.0, 680.0, 0.0);
    glVertex3f (-480.0, 660.0, 0.0);
    glEnd();
              //left-Window
    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-530.0, 480.0, 0.0);
    glVertex3f (-530.0, 430.0, 0.0);
    glVertex3f (-490.0, 430.0, 0.0);
    glVertex3f (-490.0, 495.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-530.0, 400.0, 0.0);
    glVertex3f (-530.0, 340.0, 0.0);
    glVertex3f (-490.0, 340.0, 0.0);
    glVertex3f (-490.0, 400.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-530.0, 310.0, 0.0);
    glVertex3f (-530.0, 250.0, 0.0);
    glVertex3f (-490.0, 250.0, 0.0);
    glVertex3f (-490.0, 310.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-530.0, 220.0, 0.0);
    glVertex3f (-530.0, 160.0, 0.0);
    glVertex3f (-490.0, 160.0, 0.0);
    glVertex3f (-490.0, 220.0, 0.0);
    glEnd();

             //middle-Window
    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-450.0, 510.0, 0.0);
    glVertex3f (-450.0, 430.0, 0.0);
    glVertex3f (-410.0, 430.0, 0.0);
    glVertex3f (-410.0, 525.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-450.0, 400.0, 0.0);
    glVertex3f (-450.0, 340.0, 0.0);
    glVertex3f (-410.0, 340.0, 0.0);
    glVertex3f (-410.0, 400.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-450.0, 310.0, 0.0);
    glVertex3f (-450.0, 250.0, 0.0);
    glVertex3f (-410.0, 250.0, 0.0);
    glVertex3f (-410.0, 310.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-450.0, 220.0, 0.0);
    glVertex3f (-450.0, 160.0, 0.0);
    glVertex3f (-410.0, 160.0, 0.0);
    glVertex3f (-410.0, 220.0, 0.0);
    glEnd();

             //Right-Window
    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, 540.0, 0.0);
    glVertex3f (-370.0, 430.0, 0.0);
    glVertex3f (-330.0, 430.0, 0.0);
    glVertex3f (-330.0, 555.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, 400.0, 0.0);
    glVertex3f (-370.0, 340.0, 0.0);
    glVertex3f (-330.0, 340.0, 0.0);
    glVertex3f (-330.0, 400.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, 310.0, 0.0);
    glVertex3f (-370.0, 250.0, 0.0);
    glVertex3f (-330.0, 250.0, 0.0);
    glVertex3f (-330.0, 310.0, 0.0);
    glEnd();

    glColor3d (255, 255, 255);
    glBegin(GL_QUADS);
    glVertex3f (-370.0, 220.0, 0.0);
    glVertex3f (-370.0, 160.0, 0.0);
    glVertex3f (-330.0, 160.0, 0.0);
    glVertex3f (-330.0, 220.0, 0.0);
    glEnd();
    ///Building-5 End

    ///Building-6 Start
             //Main body
    glColor3f (0.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-550.0, 140.0, 0.0);
    glVertex3f (-550.0, 400.0, 0.0);
    glVertex3f (-750.0, 400.0, 0.0);
    glVertex3f (-750.0, 140.0, 0.0);
    glEnd();
            //Roof-top
    glColor3f (0.0, 255.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f (-550.0, 400.0, 0.0);
    glVertex3f (-650.0, 500.0, 0.0);
    glVertex3f (-750.0, 400.0, 0.0);
    glEnd();
             //right-window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-620.0, 360.0, 0.0);
    glVertex3f (-580.0, 360.0, 0.0);
    glVertex3f (-580.0, 320.0, 0.0);
    glVertex3f (-620.0, 320.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-620.0, 280.0, 0.0);
    glVertex3f (-580.0, 280.0, 0.0);
    glVertex3f (-580.0, 240.0, 0.0);
    glVertex3f (-620.0, 240.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-620.0, 200.0, 0.0);
    glVertex3f (-580.0, 200.0, 0.0);
    glVertex3f (-580.0, 160.0, 0.0);
    glVertex3f (-620.0, 160.0, 0.0);
    glEnd();
            //left-window
    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-710.0, 360.0, 0.0);
    glVertex3f (-670.0, 360.0, 0.0);
    glVertex3f (-670.0, 320.0, 0.0);
    glVertex3f (-710.0, 320.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-710.0, 280.0, 0.0);
    glVertex3f (-670.0, 280.0, 0.0);
    glVertex3f (-670.0, 240.0, 0.0);
    glVertex3f (-710.0, 240.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-710.0, 200.0, 0.0);
    glVertex3f (-670.0, 200.0, 0.0);
    glVertex3f (-670.0, 160.0, 0.0);
    glVertex3f (-710.0, 160.0, 0.0);
    glEnd();
    ///Building-6 End

    ///Street Start
    glColor3f (0.247, 0.254, 0.290);
    glBegin(GL_QUADS);
    glVertex3f (1000.0, -120.0, 0.0);
    glVertex3f (1000.0, 120.0, 0.0);
    glVertex3f (-1000.0, 120.0, 0.0);
    glVertex3f (-1000.0, -120.0, 0.0);
    glEnd();

    glColor3f (0.247, 0.254, 0.290);
    glBegin(GL_QUADS);
    glVertex3f (120.0, -1000.0, 0.0);
    glVertex3f (120.0, -120.0, 0.0);
    glVertex3f (-120.0, -120.0, 0.0);
    glVertex3f (-120.0, -1000.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (1000.0, 140.0, 0.0);
    glVertex3f (1000.0, 120.0, 0.0);
    glVertex3f (-1000.0, 120.0, 0.0);
    glVertex3f (-1000.0, 140.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_POLYGON);
    glVertex3f (120.0, -120.0, 0.0);
    glVertex3f (120.0, -1000.0, 0.0);
    glVertex3f (140.0, -1000.0, 0.0);
    glVertex3f (140.0, -140.0, 0.0);
    glVertex3f (1000.0, -140.0, 0.0);
    glVertex3f (1000.0, -120.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-120.0, -120.0, 0.0);
    glVertex3f (-120.0, -1000.0, 0.0);
    glVertex3f (-140.0, -1000.0, 0.0);
    glVertex3f (-140.0, -140.0, 0.0);
    glVertex3f (-1000.0, -140.0, 0.0);
    glVertex3f (-1000.0, -120.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (1000.0, 5.0, 0.0);
    glVertex3f (1000.0, -5.0, 0.0);
    glVertex3f (900.0, -5.0, 0.0);
    glVertex3f (900.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (800.0, 5.0, 0.0);
    glVertex3f (800.0, -5.0, 0.0);
    glVertex3f (700.0, -5.0, 0.0);
    glVertex3f (700.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (600.0, 5.0, 0.0);
    glVertex3f (600.0, -5.0, 0.0);
    glVertex3f (500.0, -5.0, 0.0);
    glVertex3f (500.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (400.0, 5.0, 0.0);
    glVertex3f (400.0, -5.0, 0.0);
    glVertex3f (300.0, -5.0, 0.0);
    glVertex3f (300.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (200.0, 5.0, 0.0);
    glVertex3f (200.0, -5.0, 0.0);
    glVertex3f (100.0, -5.0, 0.0);
    glVertex3f (100.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (0.0, 5.0, 0.0);
    glVertex3f (0.0, -5.0, 0.0);
    glVertex3f (-100.0, -5.0, 0.0);
    glVertex3f (-100.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-200.0, 5.0, 0.0);
    glVertex3f (-200.0, -5.0, 0.0);
    glVertex3f (-300.0, -5.0, 0.0);
    glVertex3f (-300.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-400.0, 5.0, 0.0);
    glVertex3f (-400.0, -5.0, 0.0);
    glVertex3f (-500.0, -5.0, 0.0);
    glVertex3f (-500.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-600.0, 5.0, 0.0);
    glVertex3f (-600.0, -5.0, 0.0);
    glVertex3f (-700.0, -5.0, 0.0);
    glVertex3f (-700.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-800.0, 5.0, 0.0);
    glVertex3f (-800.0, -5.0, 0.0);
    glVertex3f (-900.0, -5.0, 0.0);
    glVertex3f (-900.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (-970.0, 5.0, 0.0);
    glVertex3f (-970.0, -5.0, 0.0);
    glVertex3f (-1000.0, -5.0, 0.0);
    glVertex3f (-1000.0, 5.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (5.0, -1000.0, 0.0);
    glVertex3f (-5.0, -1000.0, 0.0);
    glVertex3f (-5.0, -900.0, 0.0);
    glVertex3f (5.0, -900.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (5.0, -800.0, 0.0);
    glVertex3f (-5.0, -800.0, 0.0);
    glVertex3f (-5.0, -700.0, 0.0);
    glVertex3f (5.0, -700.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (5.0, -600.0, 0.0);
    glVertex3f (-5.0, -600.0, 0.0);
    glVertex3f (-5.0, -500.0, 0.0);
    glVertex3f (5.0, -500.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (5.0, -400.0, 0.0);
    glVertex3f (-5.0, -400.0, 0.0);
    glVertex3f (-5.0, -300.0, 0.0);
    glVertex3f (5.0, -300.0, 0.0);
    glEnd();

    glColor3f (255.0, 255.0, 255.0);
    glBegin(GL_QUADS);
    glVertex3f (5.0, -200.0, 0.0);
    glVertex3f (-5.0, -200.0, 0.0);
    glVertex3f (-5.0, -120.0, 0.0);
    glVertex3f (5.0, -120.0, 0.0);
    glEnd();
    ///Street end


    //hospital sign
    field_tree();
    hospital_sign(-600,-305);

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f (-560.0, -300.0, 0.0);
    glVertex3f (-560.0, -320.0, 0.0);
    glVertex3f (-640.0, -320.0, 0.0);
    glVertex3f (-640.0, -300.0, 0.0);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f (-590.0, -350.0, 0.0);
    glVertex3f (-590.0, -270.0, 0.0);
    glVertex3f (-610.0, -270.0, 0.0);
    glVertex3f (-610.0, -350.0, 0.0);
    glEnd();

///Function Call
    helicopter();

    bird_one();
    bird_two();
    bird_three();
    bird_four();

    turbine();

    traffic();

    boat1_sea();
    boat2_sea();
    boat3_sea();


    car1();
    car2();
    car3();
    car4();

    glutSwapBuffers();

    glFlush ();
}

void init (void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1000, 1000, -1000, 1000);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (800, 680);
glutInitWindowPosition (300, 0);
glutCreateWindow ("City Project- jaber - 171-15-8656");
init ();
glutDisplayFunc(show);
glutIdleFunc(show);
glutMouseFunc(mouse);
glutKeyboardFunc(keyboard);
glutSpecialFunc(arrow_key);
glutMainLoop();
return 0;
}
