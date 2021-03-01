#include "grille.hpp"


#include <iostream>

int main()
{
    grille<float> g;
    g.resize(3,5);
    std::cout<<"Connard de virus : "<<g(2,3)<<std::endl;
    return 0;
}
