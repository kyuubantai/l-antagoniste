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
         * @param heros les statistiques du Heros.
         * @param action l'action choisie par le joueur.
         **/
        void menu(Heros &heros,int action);

        /**
         * @brief Permet de sélectionner un ennemi parmi les multiples possibilités.
         * @param pos la position de l'Ennmi.
         * @param ennemis un tableau dynamique (vector) d'Ennemi.
         * @param h statistiques du héros
         * @return l'Ennemi choisi.
         **/
        void selecteurEnnemi(int pos, vector<Ennemi> &ennemis,Heros &h);

        /**
         * @brief Sous-menu des compétences.
         * @param action l'action choisie par le joueur.
         * @param ennemis un tableau dynamique (vector) d'Ennemi.
         * @param h les statistiques du Heros.
         **/
        void selecteurComp(int action,vector<Ennemi>&ennemis,Heros &h);

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
         * @param s les statistiques du Heros.
         * @return une chaine de caractères correspondant à l'objet choisi.
         **/
        string selecteurObj(int pos,Heros &h);

    public:
        Tour tour;
        bool fin;

        /**
         * @brief Constructeur de la classe : initialise les combats.
         **/
        Combat();

        /**
         * @brief Destructeur de la classe.
         **/
        ~Combat();

        /**
         * @brief Destructeur de la classe.
         * @param heros statistiques du Heros.
         * @param action action choisie par le joueur.
         **/
        void combat(Heros &heros,int action);

};


#endif