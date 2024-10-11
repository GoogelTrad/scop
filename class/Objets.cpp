#include "Objets.hpp"

Objets::Objets() : angleY(0)
{
}

Objets::~Objets()
{
}

std::vector<std::vector<Face>> &Objets::getObj(void) {return this->objet;}

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
    std::vector<Face> tmp;

	for(unsigned int i = 0; i < parse.size(); i++)
	{
		if(parse[i].find("v ") == 0)
		{
			std::istringstream line(parse[i]);
			if (line >> v >> x >> y >> z)
				coucou.getMap().insert(std::pair<int, Vertex>(index++, Vertex(x, y, z)));
		}
        else if (parse[i].find("f ") == 0)
        {
            std::istringstream line(parse[i]);
            int j = 0;
            while(parse[i][j])
                j++;
            std::string sub = parse[i].substr(2, j);
            std::istringstream lines(sub);

            while (lines >> j)
                faces.getFaces().push_back(coucou.getMap()[j]);

            tmp.push_back(faces);
            this->objet.push_back(tmp);
        }
	}
}

// void Objets::display()
// {
//     //glMatrixMode(GL_MODELVIEW);
//     setupCamera();
//     glRotatef(this->getAngleY(), 0.0f, 1.0f, 0.0f);

//     for(unsigned int i = 0; i < this->objet[i].getFaces().size(); i++)
//     {
//         if (this->objet[i].getFaces().size() == 3)
//             glBegin(GL_TRIANGLES);
//         else if (this->objet[i].getFaces().size() == 4)
//             glBegin(GL_QUADS);
//         else
//             glBegin(GL_POLYGON);
//         for (unsigned int j = 0; j < this->objet[i].getFaces().size(); j++)
//         {
//             glVertex3f(this->objet[i].getFaces()[j].getX(), this->objet[i].getFaces()[j].getY(), this->objet[i].getFaces()[j].getZ());
//             glColor4f(i * 1.0f, (i%2) * 1.0f, (i%3) * 1.0f, 1.0f);

//         }
//         glEnd();
//     }
// }

void Objets::timer()
{
    this->angleY += 0.5f;
    timerMain(0);
}