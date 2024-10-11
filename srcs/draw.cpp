#include "../include/scop.hpp"

void setupCamera()
{
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,   // Position de la caméra
              0.0, 0.0, 0.0,   // Point à regarder
              0.0, 1.0, 0.0);  // Vecteur 'up'
}

void setupProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f); // FOV, ratio, near, far
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
