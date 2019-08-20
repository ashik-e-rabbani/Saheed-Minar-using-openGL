#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>


/** DDA Line Algo parameter */

float x1[10]={-450,-410,-450,-430,-410,-390},
yy1[10]={-352,-440,-352,-395,-440,-480},
x2[10]={450,410,-430,-410,-390,-370},
y2[10]={-352,-440,-395,-440,-480,-520};


/** Breshenham Line Algo. parameter */

int bresh_x1[10]={-430,-390,-370,450}, bresh_y1[10]={-395,-480,-520,-352},
bresh_x2[10]={430,390,370,370}, bresh_y2[10]={-395,-480,-520,-520};

/** Text Rendering */

char message[] = "Omor Ekushey";


int angle  =  0;

void idle()
{
  angle += 0;
  glutPostRedisplay();
}

/** END Text Render */

/** Circle Drawing Function */

void circle() {
 glColor3f(1.0, 0.0, 0.0);
 glPointSize(2.0);
 float r =120;
 float x = 0, y = r;
 float p = 1 - r;
 glBegin(GL_POLYGON);
 while (x != y)
 {
  x++;
  if (p < 0) {
   p += 2 * (x + 1) + 1;
  }
  else {
   y--;
   p += 2 * (x + 1) + 1 - 2 * (y - 1);
  }
  glVertex2i(x, y);
  glVertex2i(-x, y);
  glVertex2i(x, -y);
  glVertex2i(-x, -y);

  glVertex2i(y, x);
  glVertex2i(-y, x);
  glVertex2i(y, -x);
  glVertex2i(-y, -x);

 }
 glEnd();

}



/** Pixel insertion on display */

void visualizer(int x, int y) {
        glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}


void draw_line(int bresh_x1, int bresh_x2, int bresh_y1, int bresh_y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = bresh_x2-bresh_x1;
	dy = bresh_y2-bresh_y1;


	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (bresh_x2 < bresh_x1) incx = -1;
	incy = 1;
	if (bresh_y2 < bresh_y1) incy = -1;
	x = bresh_x1; y = bresh_y1;
	if (dx > dy) {
		visualizer(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			visualizer(x, y);
		}


	} else {
		visualizer(x, y);
		e = 2*dx-dy;inc1 = 2*(dx-dy);inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			visualizer(x, y);
		}
	}
}
/** END Breshenham */




void display()
{
  /** Green Background Polygon */
 glColor3f(0.0007, 0.2, 0.1);
    glBegin(GL_POLYGON);
  glVertex2i(-450, 450);
  glVertex2i(450, 450);
  glVertex2i(450, -550);
  glVertex2i(-450, -550);
 glEnd();



  /** RIGHT COLUMN */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2i(300, -100);
  glVertex2i(400, -100);
  glVertex2i(400, -350);
  glVertex2i(300, -350);
 glEnd();
    // FAKE GREEN
  glColor3f(0.0007, 0.2, 0.1);
  glBegin(GL_POLYGON);
  glVertex2i(320, -120);
  glVertex2i(380, -120);
  glVertex2i(380, -350);
  glVertex2i(320, -350);
 glEnd();

  /** 2ND RIGHT COLUMN */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2i(150, 10);
  glVertex2i(250, 10);
  glVertex2i(250, -350);
  glVertex2i(150, -350);
 glEnd();

  glColor3f(0.0007, 0.2, 0.1);
  glBegin(GL_POLYGON);
  glVertex2i(170, -10);
  glVertex2i(230, -10);
  glVertex2i(230, -350);
  glVertex2i(170, -350);
 glEnd();

 /** LEFT COLUMN */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2i(-300, -100);
  glVertex2i(-400, -100);
  glVertex2i(-400, -350);
  glVertex2i(-300, -350);
 glEnd();

  glColor3f(0.0007, 0.2, 0.1);
  glBegin(GL_POLYGON);
  glVertex2i(-320, -120);
  glVertex2i(-380, -120);
  glVertex2i(-380, -350);
  glVertex2i(-320, -350);
 glEnd();

   /** 2ND LEFT COLUMN */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2i(-150, 10);
  glVertex2i(-250, 10);
  glVertex2i(-250, -350);
  glVertex2i(-150, -350);
 glEnd();

  glColor3f(0.0007, 0.2, 0.1);
  glBegin(GL_POLYGON);
  glVertex2i(-170, -10);
  glVertex2i(-230, -10);
  glVertex2i(-230, -350);
  glVertex2i(-170, -350);
 glEnd();

 /** DRAW CIRCLE CALL */
  circle();


/** MID LEFT COLUMN */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2i(-80, 50);
  glVertex2i(-60, 50);
  glVertex2i(-60, -350);
  glVertex2i(-80, -350);

 glEnd();

/** MID MID COLUMN */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2i(0, 250);
  glVertex2i(20, 250);
  glVertex2i(20, -350);
  glVertex2i(0, -350);

 glEnd();
/** MID RIGHT COLUMN */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2i(90, 50);
  glVertex2i(70, 50);
  glVertex2i(70, -350);
  glVertex2i(90, -350);

 glEnd();

/** ANGLE LEFT COLUMN */
 glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
  glVertex2i(-100, 250);
  glVertex2i(-80, 250);
  glVertex2i(-60, 50);
  glVertex2i(-80, 50);

 glEnd();
/** ANGLE RIGHT RIGHT COLUMN */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2i(100,250);
  glVertex2i(120, 250);
  glVertex2i(90, 50);
  glVertex2i(70, 50);

 glEnd();

/** TOP BAR */
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2i(-100,250);
  glVertex2i(101, 250);
  glVertex2i(97, 230);
  glVertex2i(-96, 230);

 glEnd();


/** DDA BEGINS */
int i;

for(i=0;i<6;i++){
float dy,dx,step,x,y,k,Xin,Yin;
dx=x2[i]-x1[i];
dy=y2[i]-yy1[i];

if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);

Xin = dx/step;
Yin = dy/step;

x= x1[i];
y=yy1[i];
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

for (k=1 ;k<=step;k++)
{
x= x + Xin;
y= y + Yin;

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
} /** DDA END*/


/** BRESHENHAM */
for(i=0;i<6;i++){
    draw_line(bresh_x1[i], bresh_x2[i], bresh_y1[i], bresh_y2[i]);
}






/** TEXT RENDER */


glColor3f(.8, 0.0, 0.0);
  glLineWidth(2.0);


  glMatrixMode(GL_PROJECTION);
 // glLoadIdentity();


  glPushMatrix();
  glTranslatef(-160,350,0); //Translates the character object with its axis of rotation
  glRotatef(angle, 0.0, 0.0, 1.0);//Rotates the characters about z-axis
                             //by angle degree
  //glTranslatef(-700,0,0); //translates the character object
                        //by 700 unit to the -ve x-axis
                        glScalef(0.4,0.4,1);
  for (int t = 0; t < strlen(message); t++) {

    glutStrokeCharacter(GLUT_STROKE_ROMAN, message[t]);
  }
  glPopMatrix();
  glutSwapBuffers();






glFlush();
}



void init(void)
{
glClearColor(0.7,0.7,0.7,0.7);
glMatrixMode(GL_PROJECTION);

glLoadIdentity();
//left right bottom top
gluOrtho2D(-450,450,-550,450);
}

int main(int argc, char** argv) {




glutInit(&argc, argv);

glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (700, 700);
glutInitWindowPosition (100,100);
glutCreateWindow ("Shaheed Minar");
init();
glutDisplayFunc(display);
glutIdleFunc(idle);
glutMainLoop();

return 0;
}
