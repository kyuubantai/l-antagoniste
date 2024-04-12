#ifndef __CASE__H
#define __CASE__H


/**
 * @struct Case
 * 
 * @brief Détermine les propriétés possibles d'une Case.
 **/
struct Case {
    bool libre=false;
    bool sortie=false;
    bool coffre=false;
    bool ennemi=false;
    bool pnj=false;
};

#endif