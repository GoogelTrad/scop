#include "../include/scop.hpp"

void vDisplay()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void initDisplay(int ac, char **av)
{
    glutInit(&ac, av);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("scop");
    glutDisplayFunc(vDisplay);
    glutMainLoop();
}