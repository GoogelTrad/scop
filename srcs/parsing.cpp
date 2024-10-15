#include "../include/scop.hpp"

bool parseObj(char *file, std::vector<std::string> &parse)
{
	std::string tmp(file);
	std::string extension = tmp.substr(tmp.size() - 4, tmp.size());
	if (extension.compare(".obj") != 0)
	{
		std::cerr << "Bad input file !" << std::endl;
		exit(1);
	}
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
