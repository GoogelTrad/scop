#include "../include/scop.hpp"

Objets obj;

void reshape(int width, int height)
{
    obj.setHeight(height);
    obj.setWidth(width);

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void timerMain(int value)
{
    obj.setAngleY(obj.getAngleY() += 2.0f);
    glutPostRedisplay();
    glutTimerFunc(16, timerMain, 0);
    (void)value;
}


void vDisplay()
{
    Matrices m;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // m.loadIdentity();

    glMatrixMode(GL_MODELVIEW);
    setupCamera();
    glTranslatef(obj.getC_X(), obj.getC_Y(), obj.getC_Z());
    // m.translate(obj.getC_X(), obj.getC_Y(), obj.getC_Z());
    // m.loadToOpenGL();
    glRotatef(obj.getAngleY(), 0.0f, 1.0f, 0.0f);
    // m.rotate(obj.getAngleY(), 0.0f, 1.0f, 0.0f);
    // m.loadToOpenGL();
    glTranslatef(-obj.getC_X(), -obj.getC_Y(), -obj.getC_Z());
    // m.translate(-obj.getC_X(), -obj.getC_Y(), -obj.getC_Z());
    // m.loadToOpenGL();


    for (unsigned int i = 0; i < obj.getFaces().size(); i++)
    {
        if (obj.getFaces()[i].getVertex().size() == 3)
            glBegin(GL_TRIANGLES);
        else if (obj.getFaces()[i].getVertex().size() == 4)
            glBegin(GL_QUADS);
        else
            glBegin(GL_POLYGON);

        glColor3f(obj.getFaces()[i].getRed(), obj.getFaces()[i].getGreen(), obj.getFaces()[i].getBlue());

        for (unsigned int j = 0; j < obj.getFaces()[i].getVertex().size(); j++)
            glVertex3f(obj.getFaces()[i].getVertex()[j].getX(), obj.getFaces()[i].getVertex()[j].getY(), obj.getFaces()[i].getVertex()[j].getZ());
        glEnd();
    }
    glutSwapBuffers();
}

int main(int ac, char **av)
{
    std::srand(std::time(0));
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

    glutReshapeFunc(reshape);
    glScalef(0.1f, 0.1f, 0.1f);
    glutDisplayFunc(vDisplay);
    timerMain(0);

    glutMainLoop();

}