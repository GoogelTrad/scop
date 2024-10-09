#pragma once
#include "scop.hpp"
#include <iostream>

class Vertex
{
    private:
        static std::map<int, Vertex &> listVer;
        double x;
        double y;
        double z;
    public:
        Vertex();
        Vertex(double &_x, double &_y, double &_z);
        ~Vertex();

        //Getters
        double &getX(void);
        double &getY(void);
        double &getZ(void);
        //Setters
        void setX(double &_x);
        void setY(double &_y);
        void setZ(double &_z);
};

