#include "bataille.hpp"
#include "personnage.hpp"
#include <iostream>




void Bataille::bataille(void)
{
    int nb = 3;
    std::vector<Personnage*> vR; 
    std::vector<Personnage*> vB; 
    
    for(int i=0; i < nb; ++i)
    {
        vR.push_back( new Personnage());
        vB.push_back( new Personnage());
    }
    
    std::vector<Personnage*>::iterator itR = vR.begin();
    std::vector<Personnage*>::iterator itB = vB.begin();
    Personnage *p1 = nullptr;
    Personnage *p2 = nullptr;
    
    p1 = *itR;
    p2 = *itB;
    
    while(vR.size() && vB.size())
    {
        for(;itR != vR.end();){
            
            if( (*itR)->estVivant() == false){
            std::cout << (*itR)->estVivant() << std::endl;
            std::cout << "deleting -> " << *itR << "\n";
    		delete *itR;
     		itR = vR.erase(itR);
            std::cout << "Size after delete:" << vR.size() << " ";
            
            p1 = *itR; 
            
            }else if( (*itB)->estVivant() ){
            
            p1->attaquer(*p2);
            std::cout << "Vie: " << p1->get_vie() << " ";
            std::cout << p1->get_name() << " attaque " << p2->get_name() << ". ";
            std::cout << "Il perd " << (100 - p2->get_vie()) << " de vie." << std::endl;
            //int possion = gen::int_generator(20,25);
            //p2->boirePotionDeVie(possion);
    		
            }
            else
                break;
        }

        
        for(;itB != vB.end();){
            
    	    if( (*itB)->estVivant() == false ){
            std::cout << "deleting -> " << *itB << "\n";
    		delete *itB;
     		itB = vB.erase(itB);
            std::cout << "Size after delete:" << vB.size() << " ";
            
            p2 = *itB; std::cout << *itB << std::endl;
            
            }else if( (*itR)->estVivant() ){
            
            p2->attaquer(*p1);
            std::cout << "Vie: " << p2->get_vie() << " ";
            std::cout << p2->get_name() << " attaque " << p1->get_name() << ". ";
            std::cout << "Il perd " << (100 - p1->get_vie()) << " de vie." << std::endl;
    		//int possion = gen::int_generator(2,5);
            //p1->boirePotionDeVie(possion);
            }  
            else
                break;
        }
        
    }
    
    std::cout << "\nIl y a actuellement " << Personnage::nombreInstances() 
                                   << " personnages en jeu." << std::endl;  


    std::cout << vR.size() << std::endl;
    std::cout << vB.size() << std::endl;

    if(vR.size() > vB.size()){
        std::cout << vR.size() << std::endl;
        std::cout << "Rouges gagnes!" << std::endl;
    }
    else
    {
        std::cout << vB.size() << std::endl;
        std::cout << "Blueus gagnes!" << std::endl;
    }
    
    
    std::cout << "Reds: ";
    for(auto a : vR)
        std::cout << a << " ";
    std::cout << "\nBlues: ";
    for(auto a : vB)
        std::cout << a << " ";
    std::cout << "\n\n";   
    
}