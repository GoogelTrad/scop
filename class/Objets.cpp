#include "Objets.hpp"

Objets::Objets()
{
    this->angleY = 0.0f;
    this->c_x = 0;
    this->c_y = 0;
    this->c_z = 0;
    this->height = HEIGHT;
    this->width = WIDTH;
}

Objets::~Objets()
{
}

std::vector<Face> &Objets::getFaces(void) {return this->faces;}

float &Objets::getAngleY(void) {return this->angleY;}
void Objets::setAngleY(float &_angleY) {this->angleY = _angleY;}
void Objets::setWidth(int &_w) {this->width = _w;}
void Objets::setHeight(int &_h) {this->height = _h;}
int &Objets::getWidth(void) {return this->width;}
int &Objets::getHeight(void) {return this->height;}
double &Objets::getC_X(void) {return this->c_x;}
double &Objets::getC_Y(void) {return this->c_y;}
double &Objets::getC_Z(void) {return this->c_z;}

void Objets::parseVertex(std::vector<std::string> &parse)
{
	double x;
	double y;
	double z;
	char v;

    std::vector<Vertex> coucou;
	for(unsigned int i = 0; i < parse.size(); i++)
	{
		if(parse[i].find("v ") == 0)
		{  
			std::istringstream line(parse[i]);
			if (line >> v >> x >> y >> z)
                coucou.push_back(Vertex(x, y, z));
            
		}
	}
    center(this->c_x, this->c_y, this->c_z, coucou);
    for(unsigned int i = 0; i < parse.size(); i++)
    {
        if (parse[i].find("f ") == 0)
        {
            std::string sub = parse[i].substr(2, parse[i].size());
            std::istringstream lines(sub);

            Face newFace;
            int j = 0;
            while (lines >> j)
            {
                newFace.getVertex().push_back(coucou[j - 1]);
            }
            this->faces.push_back(newFace);
        }
    }
}
