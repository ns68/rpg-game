#pragma once
//#define TEST_UTILITIES
#include <string>
#include <vector>
#include "generator.hpp"

class Arme
{
    
        std::string _name;
        int _degats;
        //const std::vector<std::string> armList;

        
        
        

    public:
        Arme();
        //Arme(std::string nom, int degats);
        ~Arme();
        void change(std::string nom, int degats);
        void print(void) const;
        
        
        

        

        // getters & setters

        inline std::string get_name_arme() {return this->_name;}
        inline void set_name_arme(std::string name) {this->_name = name;}
        inline int get_degats_arme() {return this->_degats;}
        inline void set_degats_arme(int degats) {this->_degats = degats;}



};