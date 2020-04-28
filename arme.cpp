#include "arme.hpp"
#include <iostream>

Arme::Arme()
{
    const std::vector<std::string> armList 
    {"Espadon", "Arc", "Ensis", "Latte", "Umbo", "Fauchon", "Pique", "Anicroche"};
    _name = gen::from_vector_generator(armList);
    _degats = gen::int_generator(5,25);
}


/*
Arme::Arme(std::string name, int degats) : _name(name), _degats(degats)
{

}
*/

Arme::~Arme() {}

void Arme::print(void) const
{
    std::cout << "\nArme: " << _name << std::endl;
    std::cout << "Degats: " << _degats << std::endl;
}

void Arme::change(std::string nom, int degats)
{
    _name = nom;
    _degats = degats;

}


 


#ifdef TEST_UTILITIES
int main()
{
    
    Arme a; 
    a.print();
}
#endif