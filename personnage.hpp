#pragma once
#include "arme.hpp"
#include <string>


class Personnage
{
    std::string _name;
    int         _vie;
    int         _mana;
    Arme* _arme;
    static int compteur;

    public:

    Personnage();
    Personnage(Personnage const& personnageACopier); // constructor de copie
    //Personnage(std::string name);

    ~Personnage();
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() const;
    void print(void) const;
    void etat(void) const;
    static int nombreInstances();

    std::string get_name() const {return this->_name;}
    int get_vie() const {return this->_vie;}


    
};