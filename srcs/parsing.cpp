#include "../include/scop.hpp"

bool parseObj(char *file, std::vector<std::string> &parse)
{
	std::ifstream fileToOpen(file);

	if (!fileToOpen.is_open())
	{
		std::cerr << "Error! Can't open file!" << std::endl;
		return false;
	}
	std::string line;
	while(std::getline(fileToOpen, line))
		parse.push_back(line);

	fileToOpen.close();

	return true;
}

void parseVertex(std::vector<std::string> &parse, std::map<int, Vertex> &listVer)
{
	double x;
	double y;
	double z;
	char v;
	int index = 1;

	for(unsigned int i = 0; i < parse.size(); i++)
	{
		if(parse[i].find("v ") == 0)
		{
			std::istringstream line(parse[i]);
			if (line >> v >> x >> y >> z)
				listVer.insert(std::pair<int, Vertex>(index++, Vertex(x, y, z)));
			
		}
	}
}