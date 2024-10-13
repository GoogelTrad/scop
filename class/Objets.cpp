#include "Objets.hpp"

Objets::Objets()
{
    this->angleY = 0.0f;
}

Objets::~Objets()
{
}

std::vector<Face> &Objets::getObj(void) {return this->objet;}

float &Objets::getAngleY(void) {return this->angleY;}
void Objets::setAngleY(float &_angleY) {this->angleY = _angleY;}

void Objets::parseVertex(std::vector<std::string> &parse)
{
	double x;
	double y;
	double z;
	char v;
	int index = 1;
    Face faces;
    Vertex coucou;


	for(unsigned int i = 0; i < parse.size(); i++)
	{
		if(parse[i].find("v ") == 0)
		{
			std::istringstream line(parse[i]);
			if (line >> v >> x >> y >> z)
				coucou.getMap().insert(std::pair<int, Vertex>(index++, Vertex(x, y, z)));
		}
	}
    for(unsigned int i = 0; i < parse.size(); i++)
    {
        if (parse[i].find("f ") == 0)
        {
            std::istringstream line(parse[i]);
            int j = 0;

            while(parse[i][j])
                j++;

            std::string sub = parse[i].substr(2, j);
            std::istringstream lines(sub);

            while (lines >> j)
                faces.getFaces().push_back(coucou.getMap()[j]);
            
            std::cout << "faces size = " << faces.getFaces()[i].<< std::endl;

            this->objet.push_back(faces);
        }
    }
}

void Objets::timer()
{
    this->angleY += 0.5f;
    timerMain(0);
}