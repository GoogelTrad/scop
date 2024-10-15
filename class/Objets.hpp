#pragma once
#include "../include/scop.hpp"

class Face;

class Objets
{
private:
    std::vector<Face> faces;
    float angleY;
    double c_x;
    double c_y;
    double c_z;
    int height;
    int width;
public:
    Objets();
    ~Objets();

    std::vector<Face> &getFaces(void);

    float &getAngleY();
    void setAngleY(float &_angleY);

    int &getWidth();
    int &getHeight();
    void setHeight(int &_h);
    void setWidth(int &_w);
    
    double &getC_X();
    double &getC_Y();
    double &getC_Z();

    void parseVertex(std::vector<std::string> &parse);
    void display();
    void timer();
};

