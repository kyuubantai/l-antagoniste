#include "Competence.h"
#include <iostream>

using namespace std;

int Competence::atk(const int& atk,int& vie_ennemi){
    vie_ennemi = vie_ennemi-atk;
    return vie_ennemi;
}

int Competence::soin(const int& vie,int& vie_perso){
    vie_perso = vie_perso + vie;
    return vie_perso;
}
