
#include<GL/glut.h>
#include<stdio.h>
float v[]={0,0.6,0.25,0.9,0.5,0.6};
GLubyte list[]={0,1,2};
int g=0;
void dis()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	glColor3f(0,0,0);
	//glViewport(0,0,700,700);
	glDrawElements(GL_LINE_LOOP,3,GL_UNSIGNED_BYTE,list);
	glRotated(g,0,0,1);
	glDrawElements(GL_LINE_LOOP,3,GL_UNSIGNED_BYTE,list);
	glFlush();
	glLoadIdentity();
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	printf("Enter Rotation Angle:");    
	scanf("%d",&g);
	glutCreateWindow("Triangle Rotation");
	glutDisplayFunc(dis);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2,GL_FLOAT,0,v);
	glutMainLoop();
}
 

