#pragma once
#include "../include/scop.hpp"
#include <iostream>

class Vertex
{
    private:
        double x;
        double y;
        double z;
        std::map<int, Vertex> listVer;
    public:
        Vertex();
        Vertex(double &_x, double &_y, double &_z);
        ~Vertex();


        //Getters
        double &getX(void);
        double &getY(void);
        double &getZ(void);
        std::map<int, Vertex> &getMap(void);
        //Setters
        void setX(double &_x);
        void setY(double &_y);
        void setZ(double &_z);
};

std::ostream &operator<<(std::ostream &stream, Vertex &ver);