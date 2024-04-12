#ifndef __COMPETENCE__H
#define __COMPETENCE__H

/**
 * @class Competence
 *
 * @brief Gere les compétences spéciales du personnage.
 **/
class Competence {
    public:

        /**
         * @brief Constructeur de la classe : initialise les statistiques des ennemis.
         * @param vie_ennemi
         * @param energie
         * @param atk
         **/
        int atkMono(int vie_ennemi,int& energie,const int atk);

        /**
         * @brief Constructeur de la classe : initialise les statistiques des ennemis.
         * @param vie_ennemi
         * @param energie
         * @param atk
         **/
        int atkMulti(int vie_ennemi,int& energie,const int atk);

        /**
         * @brief Constructeur de la classe : initialise les statistiques des ennemis.
         * @param vie_perso
         * @param energie
         * @param atk
         **/
        int soin(int vie_perso,int& energie,const int vieMax_perso);


};


#endif