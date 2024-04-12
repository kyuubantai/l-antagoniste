#ifndef __DEPLACEMENT__H
#define __DEPLACEMENT__H

#include "Monde.h"



/**
 * @class Deplacement
 *
 * @brief gère le déplacement et les interactions sur le Monde  
 **/
class Deplacement {
    private:
        Monde monde;
        int num_pnj=1000;
        int num_dialogue=1000;
    public:

        /**
         * @brief Effectue le déplacement dans le monde.
         * @param action : l'action choisie par le joueur
        **/
        void deplace(char action);

        /**
         * @brief Permet l'interaction avec les PNJs.
        **/
        void interaction();

        /**
         * @brief Récupère l'état actuel du Monde
         * @return une copie du Monde
        **/
        Monde getMonde() const;
        
        int getPnj();
        void setPnj(const int& pnj);
        int getDialogue();
        void setDialogue(const int& dial);
};

inline Monde Deplacement::getMonde () const { return monde; }

#endif