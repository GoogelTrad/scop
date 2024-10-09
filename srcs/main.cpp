#include "../include/scop.hpp"

std::map<int, Vertex> Vertex::listVer;

int main(int ac, char **av)
{
    std::vector<std::string> parse;

    if (ac)
        std::cout << std::endl;
    if (!parseObj(av[1], parse))
        exit(1);

    parseVertex(parse, Vertex::listVer);
    // for(auto &pair : Vertex::listVer)
    //     std::cout << pair.first << " : " << pair.second << std::endl;

    

    initDisplay(ac, av);
}