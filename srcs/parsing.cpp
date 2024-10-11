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
