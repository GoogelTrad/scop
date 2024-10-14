#pragma once
#include "../include/scop.hpp"

class Vertex;

class Face
{
private:
	std::vector<Vertex> vertex;

public:
	Face();
	~Face();

	std::vector<Vertex> &getVertex(void);
};

std::ostream &operator<<(std::ostream &stream, Face &face);