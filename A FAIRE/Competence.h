#ifndef __COMPETENCE__H
#define __COMPETENCE__H

/**
 * @class Competence
 *
 * @brief Gere les compétences spéciales du personnage.
 **/
class Competence {
    public:
        int atkMono(int vie_ennemi,int& energie,const int atk);
        int atkMulti(int vie_ennemi,int& energie,const int atk);
        int soin(int vie_perso,int& energie,const int vieMax_perso);


};


#endif