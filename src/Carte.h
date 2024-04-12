#ifndef __CARTE__H
#define __CARTE__H


#include "Case.h"

/**
 * @struct Carte
 *
 * @brief Structure Carte déterminant la taille d'une Carte qui est un tableau 2D de Case 7*12
 **/
struct Carte{
    Case tabCase[7][12];
};

#endif