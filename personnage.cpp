#include "personnage.hpp"
#include <iostream>
#include <string>

int Personnage::compteur = 0;

 

Personnage::Personnage() : _vie(100), _mana(100), _arme(nullptr) 
{
    
    _name = gen::s_generator();
    _arme = new Arme();
    ++compteur;
}


Personnage::Personnage(Personnage const& personnageACopier) 
   : _vie(personnageACopier._vie), _mana(personnageACopier._mana), _arme(0)
{
    _arme = new Arme(*(personnageACopier._arme));
}

/*
Personnage::Personnage(std::string name) : _arme(nullptr)
{
    _name = name;
    _arme = new Arme();
    _vie = 100;
    _mana = 100;
}
*/
Personnage::~Personnage() 
{
    --compteur;
    delete _arme;

}


void Personnage::recevoirDegats(int nbDegats)
{
    if(_vie > 0){
        _vie -= nbDegats;
        //std::cout << _name << " a reçu " << _arme->get_degats_arme() << " de degats" << std::endl;
    }else{
        _vie = 0;
        std::cout << "vie=0" << std::endl;
    }
        
}

void Personnage::attaquer(Personnage &cible)
{
    if(_vie > 0 && cible._vie > 0)
        cible.recevoirDegats(_arme->get_degats_arme());
    //std::cout << _name << " -> " << cible._name << std::endl;
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    if(_vie > 5 && _vie < 100)
        _vie += quantitePotion;
}
    
void Personnage::changerArme(std::string nomNouvelleArme, int degatsNouvelleArme)
{
    _arme->set_name_arme(nomNouvelleArme);
    _arme->set_degats_arme(degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    if(_vie > 0)
        return true;
    else
        return false;
}


void Personnage::etat() const
{
      
}


void Personnage::print(void) const
{
    std::cout << "----------------" << std::endl;
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Vie restante: " << _vie << std::endl;
    std::cout << "Mana: " << _mana << std::endl;
    std::cout << "Arme: " << _arme->get_name_arme() << std::endl;
    std::cout << "Puisance: " << _arme->get_degats_arme() << std::endl;
    std::cout << "EstVivant? " << estVivant() << std::endl;
    std::cout << "-----------------" << std::endl;
    
}

int Personnage::nombreInstances()
{
    return compteur;   //On renvoie simplement la valeur du compteur
}