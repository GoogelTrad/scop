#pragma once
#include "../include/scop.hpp"

class Vertex;

class Face
{
private:
	std::vector<Vertex> vertex;
	float red;
	float blue;
	float green;

public:
	Face();
	~Face();

	std::vector<Vertex> &getVertex(void);
	float &getRed();
	float &getBlue();
	float &getGreen();
	void setBlue(float &_blue);
	void setRed(float &_red);
	void setGreen(float &_green);

};

std::ostream &operator<<(std::ostream &stream, Face &face);