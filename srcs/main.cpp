#include "../include/scop.hpp"

std::map<int, Vertex> Vertex::listVer;
Objets obj;

void timerMain(int value)
{
    glutPostRedisplay(); // Redessiner la scène
    glutTimerFunc(16, timerMain, 0); // Environ 60 FPS
    (void)value;
}


void vDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // //glMatrixMode(GL_MODELVIEW);
    // setupCamera();
    // glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    for(unsigned int i = 0; i < obj.getObj()[i].size(); i++)
    {
        if (obj.getObj()[i].size() == 3)
            glBegin(GL_TRIANGLES);
        else if (obj.getObj()[i].size() == 4)
            glBegin(GL_QUADS);
        else
            glBegin(GL_POLYGON);
        for (unsigned int j = 0; j < obj.getObj()[i][j].getFaces().size(); j++)
        {
            for (unsigned int k = 0; k < 3; k++)
            {
                glVertex3f(obj.getObj()[i][j].getFaces()[k].getX(), obj.getObj()[i][j].getFaces()[k].getY(), obj.getObj()[i][j].getFaces()[k].getZ());
                glColor4f(i * 1.0f, (i%2) * 1.0f, (i%3) * 1.0f, 1.0f);
            }
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
    obj.timer();

    glutMainLoop();

}