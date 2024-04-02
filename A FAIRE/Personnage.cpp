#include <iostream>
#include "Personnage.h"

using namespace std;

int Personnage::getVie() const{
    return vie;
}

void Personnage::setVie(int nvVie){
    vie=nvVie;
}

int Personnage::getAtk() const{
    return atkBase;
}

void Personnage::setAtk(int nvAtk){
    atkBase=nvAtk;
}

int Personnage::getNrj() const{
    return energie;
}
