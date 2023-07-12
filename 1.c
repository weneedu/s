#include<GL/glut.h> 		
#include <stdlib.h> 
#include<math.h> 
void init(void) 
{ 
glClearColor(1.0,1.0,1.0,0.0); 
glMatrixMode(GL_PROJECTION); 
gluOrtho2D(0.0,300.0,0.0,300.0); 
} 
void setPixel(GLint xCoordinate, GLint yCoordinate)
{ 
glBegin(GL_POINTS); 
glVertex2i(xCoordinate,yCoordinate); 
glEnd(); 
glFlush(); 
}   
void lineBres(GLint x0, GLint y0, GLint xEnd, GLint  
yEnd) 
{ 
GLint dx = fabs(xEnd - x0); 
GLint dy = fabs(yEnd - y0); 
GLint p = 2 * dy - dx; 
GLint twoDy = 2 * dy; 
GLint twoDyMinusDx = 2 * (dy-dx); 
GLint x,y; 
if (x0 > xEnd){ 
x = xEnd; 
y = yEnd; 
xEnd = x; 
}else{ 
x = x0; 
y = y0; 
} 
setPixel(x,y); 
while(x<xEnd){ 
x++; 
if(p<0) 
p += twoDy; 
else{ 
y++; 
p += twoDyMinusDx; 
} 
setPixel(x,y); 
} 
} 
void drawMyLine(void) 
{ 
glClear(GL_COLOR_BUFFER_BIT); 
glColor3f(1.0,0.0,0.0); 
glPointSize(4.0); 
GLint x0 = 100; 
GLint y0 = 150; 
GLint xEnd = 200; 
GLint yEnd = 200; 
lineBres(x0,y0,xEnd,yEnd); 
} 
void main(int argc, char**argv) 
{ 
glutInit(&argc,argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(400,400); 
glutInitWindowPosition(0,0); 
glutCreateWindow("Bresenham"); 
init(); 
glutDisplayFunc(drawMyLine); 
glutMainLoop(); 
}
