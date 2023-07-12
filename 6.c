#include<GL/glut.h>
void obj(double tx,double ty,double tz,double sx,double sy,double sz)
{
glRotated(50,0,1,0); 
glRotated(-10,1,0,0);
glRotated(-10,0,0,1);
glTranslated(tx,ty,tz);
glScaled(sx,sy,sz);
glutSolidCube(1);
glLoadIdentity();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
obj(0,0,0.5,1,1,0.05);  
obj(0,-0.5,0,1,0.05,1); 
obj(-0.5,0,0,0.05,1,1); 
obj(0,-0.3,0,0.02,0.2,0.02);   
obj(0,-0.3,-0.4,0.02,0.2,0.02);
obj(0.4,-0.3,0,0.02,0.2,0.02);
obj(0.4,-0.3,-0.4,0.02,0.2,0.02);
obj(0.2,-0.18,-0.2,0.6,0.02,0.6); 
glRotated(50,0,1,0); 
glRotated(-10,1,0,0);
glRotated(-10,0,0,1);
glTranslated(0.3,-0.1,-0.3);
glutSolidTeapot(0.1);
glFlush();
glLoadIdentity();
}
int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
float ambient[]={1,1,1,1}; 
float light_pos[]={27,80,2,0}; 
glutInitWindowSize(700,700);
glutCreateWindow("scene");
glutDisplayFunc(display);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
}


