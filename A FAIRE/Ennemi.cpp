#include "Ennemi.h"
#include <iostream>

using namespace std;

Ennemi::Ennemi(){
    stats.setVie(100);
    stats.setAtk(30);
}

Personnage Ennemi::boss(){
    stats.setVie(600);
    stats.setAtk(60);
}

Personnage Ennemi::tank(){
    stats.setVie(300);
    stats.setAtk(40);
}

Personnage Ennemi::light(){
    stats.setVie(50);
    stats.setAtk(15);
}



