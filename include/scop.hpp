#pragma once
#define GL_SILENCE_DEPRECATION


//#include <GL/glut.h>
#include <GLUT/glut.h>
#include <map>
#include <string>
#include <fstream>
#include "Vertex.hpp"
#include "Face.hpp"

#define WIDTH 800
#define HEIGHT 600


//Window.hpp
void initDisplay(int ac, char **av);
void vDisplay();

//parsing.hpp
void parseObj(char *file);