#include "Competence.h"
#include <iostream>

using namespace std;

int Competence::atkMono(int &vie_ennemi,int& energie,const int atk){
    vie_ennemi -= atk*1.5;
    energie-=20;
    return vie_ennemi;
}

int Competence::atkMulti(int &vie_ennemi,int& energie,const int atk){
    vie_ennemi -= atk*0.7;
    energie-=30;
    return vie_ennemi;
}

int Competence::soin(int &vie_perso, int &energie, const int vieMax_perso){
    vie_perso += 50;
    if (vie_perso>vieMax_perso) vie_perso=vieMax_perso;
    return vie_perso;
}
