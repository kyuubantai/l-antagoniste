#ifndef __DEPLACEMENT__H
#define __DEPLACEMENT__H

#include "Monde.h"
#include "Combat.h"



/**
 * @class Deplacement
 *
 * @brief gère le déplacement et les interactions sur le Monde.
 **/
class Deplacement {
    private:
        Monde monde;
        int num_pnj=1000;
        int num_dialogue=1000;
    public:

        /**
         * @brief Effectue le déplacement dans le monde.
         * @param action : l'action choisie par le joueur (touche du clavier)
        **/
        void deplace(char action);

        /**
         * @brief Permet l'interaction avec les PNJs, coffres et ennemis.
        **/
        void interaction();

        /**
         * @brief Récupère l'état actuel du Monde.
         * @return une copie du Monde.
        **/
        Monde getMonde() const;

        /**
         * @brief Récupère le numéro du PNJ.
        **/
        int getPnj();

        /**
         * @brief Modifie le numéro du PNJ.
         * @param pnj : son nouveau numéro.
        **/
        void setPnj(const int& pnj);

        /**
         * @brief Récupère le numéro du dialogue.
        **/
        int getDialogue();

        /**
         * @brief Modifie le numéro du dialogue.
         * @param dial : son nouveau numéro.
        **/
        void setDialogue(const int& dial);
        
};

inline Monde Deplacement::getMonde () const { return monde; }

#endif