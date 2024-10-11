#include "../include/scop.hpp"



void initDisplay(int ac, char **av)
{
    glutInit(&ac, av);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("scop");
    glViewport(0, 0, WIDTH, HEIGHT);
}