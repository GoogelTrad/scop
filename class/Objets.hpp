#pragma once
#include "../include/scop.hpp"

class Face;

class Objets
{
private:
    std::vector<std::vector<Face>> objet;
    float angleY;
public:
    Objets();
    ~Objets();

    std::vector<std::vector<Face>> &getObj(void);

    float &getAngleY();
    void setAngleY(float &_angleY);

    void parseVertex(std::vector<std::string> &parse);
    void display();
    void timer();
};

