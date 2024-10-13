#include "../include/scop.hpp"

Objets obj;

void timerMain(int value)
{
    obj.setAngleY(obj.getAngleY() += 0.5f);
    glutPostRedisplay(); // Redessiner la scène
    glutTimerFunc(16, timerMain, 0); // Environ 60 FPS
    (void)value;
}


void vDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // //glMatrixMode(GL_MODELVIEW);
    setupCamera();
    glRotatef(obj.getAngleY(), 0.0f, 1.0f, 0.0f);

    for(unsigned int i = 0; i < obj.getObj().size(); i++)
    {
        //std::cout << "size face = " << obj.getObj()[i].getFaces().size() << std::endl;
        //Probleme sur les sizes
        if (obj.getObj()[i].getFaces().size() == 3)
        {
            // std::cout << "3" << std::endl;
            glBegin(GL_TRIANGLES);
        }
        else if (obj.getObj()[i].getFaces().size() == 4)
        {
            // std::cout << "4" << std::endl;
            glBegin(GL_QUADS);
        }
        else
        {
            // std::cout << "autres" << std::endl;
            glBegin(GL_POLYGON);
        }

        for(unsigned int j = 0; j < obj.getObj()[i].getFaces().size(); j++)
        {
            glVertex3f(obj.getObj()[i].getFaces()[j].getX(),obj.getObj()[i].getFaces()[j].getY(), obj.getObj()[i].getFaces()[j].getZ());
            glColor4f(j * 1.0f, (j % 2) * 1.0f, (j %3 ) * 1.0f, 1.0f);           
        }
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