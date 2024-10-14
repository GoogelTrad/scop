#include "../include/scop.hpp"

Objets obj;

void timerMain(int value)
{
    obj.setAngleY(obj.getAngleY() += 2.0f);
    glutPostRedisplay(); // Redessiner la scène
    glutTimerFunc(16, timerMain, 0); // Environ 60 FPS
    (void)value;
}


void vDisplay()
{
    // double c_x = 0.0f, c_y = 2.0f, c_z = 1.0f;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // //glMatrixMode(GL_MODELVIEW);
    setupCamera();
    glTranslatef(obj.getC_X(), obj.getC_Y(), obj.getC_Z());
    glRotatef(obj.getAngleY(), 0.0f, 1.0f, 0.0f);
    glTranslatef(-obj.getC_X(), -obj.getC_Y(), -obj.getC_Z());


    for (unsigned int i = 0; i < obj.getFaces().size(); i++)
    {
        if (obj.getFaces()[i].getVertex().size() == 3)
            glBegin(GL_TRIANGLES);
        else if (obj.getFaces()[i].getVertex().size() == 4)
            glBegin(GL_QUADS);
        else
            glBegin(GL_POLYGON);
        if (i% 3 == 0)
            glColor3f(0.7f, 0.7f, 0.7f);
        if (i% 3 == 1)
            glColor3f(0.3f, 0.3f, 0.3f);
        if (i% 3 == 2)
            glColor3f(0.5f, 0.5f, 0.5f);
        for (unsigned int j = 0; j < obj.getFaces()[i].getVertex().size(); j++)
            glVertex3f(obj.getFaces()[i].getVertex()[j].getX(), obj.getFaces()[i].getVertex()[j].getY(), obj.getFaces()[i].getVertex()[j].getZ());
        glEnd();
    }
    glutSwapBuffers();
}

int main(int ac, char **av)
{
    std::vector<std::string> parse;

    if (ac)
        std::cout << std::endl;
    if (!parseObj(av[1], parse))
        exit(1);

    obj.parseVertex(parse);

    initDisplay(ac, av);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    setupProjection();
    setupCamera();

    glutDisplayFunc(vDisplay);
    timerMain(0);

    glutMainLoop();

}