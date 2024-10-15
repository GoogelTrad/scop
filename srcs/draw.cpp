#include "../include/scop.hpp"

extern Objets obj;

void setupCamera()
{

    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10,   // Position de la caméra
              obj.getC_X(), obj.getC_Y(), obj.getC_Z(),   // Point à regarder
              0.0, 1.0, 0.0);  // Vecteur 'up'
}

void setupProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)obj.getWidth() / (float)obj.getHeight(), 0.1f, 100.0f); // FOV, ratio, near, far
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void center(double &res_x, double &res_y, double &res_z, std::vector<Vertex> coucou)
{
    double x = 0;
    double y = 0;
    double z = 0;
    double min_x = 0;
    double min_y = 0;
    double min_z = 0;
    for (unsigned int i = 0; i < coucou.size(); i++)
    {
        if (x < coucou[i].getX())
            x = coucou[i].getX();
        if (y < coucou[i].getY())
            y = coucou[i].getY();
        if (z < coucou[i].getZ())
            z = coucou[i].getZ();
        if (min_x > coucou[i].getX())
            min_x = coucou[i].getX();
        if (min_y > coucou[i].getY())
            min_y = coucou[i].getY();
        if (min_z > coucou[i].getZ())
            min_z = coucou[i].getZ();
    }

    res_x = (x + min_x) / 2;
    res_y = (y + min_y) / 2;
    res_z = (z + min_z) / 2;
}

float random_color()
{
    float res;

    res = std::rand() / static_cast<float>(RAND_MAX);
    return res;
}