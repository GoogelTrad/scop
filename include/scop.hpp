#pragma once
#define GL_SILENCE_DEPRECATION


#include <GL/glut.h>
//#include <GLUT/glut.h>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <ostream>
#include <vector>
#include <fstream>
#include "../class/Vertex.hpp"
#include "../class/Face.hpp"
#include "../class/Objets.hpp"

#define WIDTH 800
#define HEIGHT 600

class Vertex;
class Face;

//Window.hpp
void initDisplay(int ac, char **av);
void vDisplay();

//parsing.hpp
bool parseObj(char *file, std::vector<std::string> &parse);
void parseVertex(std::vector<std::string> &parse, std::map<int, Vertex> &listVer);

//draw.hpp
void setupProjection();
void setupCamera();
void timerMain(int value);
void updateRotation();