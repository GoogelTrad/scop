#include "Vertex.hpp"

Vertex::Vertex()
{
}

Vertex::Vertex(double &_x, double &_y, double &_z)
{
    this->x = _x;
    this->y = _y;
    this->z = _z;
}

Vertex::~Vertex()
{
}

//Getters
double &Vertex::getX(void) {return this->x;}
double &Vertex::getY(void) {return this->y;}
double &Vertex::getZ(void) {return this->z;}

//Setter
void Vertex::setX(double &_x){this->x = _x;}
void Vertex::setY(double &_y){this->y = _y;}
void Vertex::setZ(double &_z){this->z = _z;}

std::ostream &operator<<(std::ostream &stream, Vertex &ver)
{
	stream << ver.getX() << " " << ver.getY() << " " << ver.getZ();
    
	return stream;
}