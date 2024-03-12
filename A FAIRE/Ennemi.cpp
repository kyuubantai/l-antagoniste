#include "Ennemi.h"
#include <iostream>

using namespace std;

Ennemi::Ennemi(){
    mob.setVie(100);
    mob.setAtk(30);
}
Ennemi::~Ennemi(){
    mob.setVie(0);
    mob.setAtk(0);
}

Personnage Ennemi::boss(){
    mob.setVie(600);
    mob.setAtk(60);
}

Personnage Ennemi::tank(){
    mob.setVie(300);
    mob.setAtk(40);
}

Personnage Ennemi::light(){
    mob.setVie(50);
    mob.setAtk(15);
}



