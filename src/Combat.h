#ifndef __COMBAT__H
#define __COMBAT__H

#include "Heros.h"
#include "Ennemi.h"
#include "Competence.h"
#include <vector>


enum Tour {MOI,ENNEMI};
enum Etat{MENUBASE,SELECT,COMP,OBJ,GUARD,RETREAT};
enum EtatComp{MENUCOMP,MONO,MULTI,HEAL};


/**
 * @class Combat
 *
 * @brief Gère les combats.
 **/
class Combat {
    private:
        Ennemi en;
        Etat etat;
        EtatComp et;
        vector<Ennemi> ennemis;

        /**
         * @brief Menu principal des options de combat.
         * @param action l'action choisie par le joueur.
         **/
        void menu(int action);

        /**
         * @brief Permet de sélectionner un ennemi parmi les multiples possibilités.
         * @param pos la position de l'Ennmi.
         * @param ennemis un tableau dynamique (vector) d'Ennemi.
         * @return l'Ennemi choisi.
         **/
        void selecteurEnnemi(long unsigned int pos, vector<Ennemi> &ennemis);

        /**
         * @brief Sous-menu des compétences.
         * @param action l'action choisie par le joueur.
         * @param ennemis un tableau dynamique (vector) d'Ennemi.
         **/
        void selecteurComp(int action,vector<Ennemi>&ennemis);

        /**
         * @brief Permet d'effectuer un choix.
         * @param choix l'action choisie par le joueur.
         * @return un nouvel Etat.
         **/
        Etat saisirchoix(int choix);

        /**
         * @brief Permet de choisir la compétence vouleur par le joueur.
         * @param choix l'action choisie par le joueur.
         * @return un nouvel EtatComp.
         **/
        EtatComp saisirComp(int choix);

        /**
         * @brief Récupère un objet dans l'inventaire à partir du choix du joueur.
         * @param pos la position de l'objet dans l'inventaire.
         * @return une chaine de caractères correspondant à l'objet choisi.
         **/
        int selecteurObj(int pos);

    public:
        Tour tour;
        bool fin;
        Heros heros;

        /**
         * @brief Constructeur de la classe : initialise les combats.
         **/
        Combat();

        /**
         * @brief Constructeur de la classe par copie : initialise un ennemi spécial
         **/

        Combat(Ennemi ennemi);

        /**
         * @brief Destructeur de la classe.
         **/
        ~Combat();

        /**
         * @brief Destructeur de la classe.
         * @param action action choisie par le joueur.
         **/
        void combat(int action);
        /**
         * @brief initialise a 0 les cases de l'inventaire
        **/
        void initInventory();

        /**
         * @brief Modifie le numéro du dialogue.
         * @param dial : son nouveau numéro.
        **/
        void setInventory(const int& objet);

};


#endif