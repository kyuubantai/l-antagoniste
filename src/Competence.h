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
         * @param vie_ennemi vie actuelle de l'ennemi
         * @param energie energie actuelle du heros
         * @param atk attaque de base du heros
         * @return la vie de l'ennemi modifiée
         **/
        int atkMono(int vie_ennemi,int& energie,const int atk);

        /**
         * @brief Constructeur de la classe : initialise les statistiques des ennemis.
         * @param vie_ennemi vie actuelle de l'ennemi
         * @param energie energie actuelle du heros
         * @param atk attaque de base du heros
         * @return la vie de l'ennemi modifiée
         **/
        int atkMulti(int vie_ennemi,int& energie,const int atk);

        /**
         * @brief Constructeur de la classe : initialise les statistiques des ennemis.
         * @param vie_perso vie actuelle du héros
         * @param energie energie actuelle du heros
         * @param vieMax_perso vie maximale du heros
         * @return la vie du héros modifiée
         **/
        int soin(int vie_perso,int& energie,const int vieMax_perso);


};


#endif