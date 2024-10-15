#include "Face.hpp"

Face::Face()
{
    this->red = random_color();
    this->green = random_color();
    this->blue = random_color();
}

Face::~Face()
{
}


std::vector<Vertex> &Face::getVertex(void) {return this->vertex;}
float &Face::getRed(void) {return this->red;}
float &Face::getBlue(void) {return this->blue;}
float &Face::getGreen(void) {return this->green;}


void Face::setBlue(float &_color) {this->blue = _color;}
void Face::setRed(float &_color) {this->red = _color;}
void Face::setGreen(float &_color) {this->green = _color;}
