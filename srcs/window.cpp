#include "../include/scop.hpp"



void initDisplay(int ac, char **av)
{
    glutInit(&ac, av);
    // glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("scop");
    glViewport(0, 0, WIDTH, HEIGHT);
}