#pragma once
#include "../include/scop.hpp"

class Vertex;

class Face
{
private:
	std::vector<Vertex> faces;
public:
	Face();
	~Face();

	std::vector<Vertex> &getFaces(void);
};

std::ostream &operator<<(std::ostream &stream, Face &face);