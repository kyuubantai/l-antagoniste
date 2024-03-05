#include <iostream>
#include "Personnage.h"

using namespace std;

int Personnage::getVie(){
    return vie;
}

void Personnage::setVie(const int& nvVie){
    vie=nvVie;
}

int Personnage::getAtk(){
    return atkBase;
}

void Personnage::setAtk(const int& nvAtk){
    atkBase=nvAtk;
}