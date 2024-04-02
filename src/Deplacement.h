#ifndef __DEPLACEMENT__H
#define __DEPLACEMENT__H

#include "Monde.h"

class Deplacement {
    private:
        Monde monde;
        int num_pnj;
        int num_dialogue;
    public:
        void deplace(char action);
        void interaction();
        Monde getMonde() const;
        int getPnj();
        int getDialogue();
};

inline Monde Deplacement::getMonde () const { return monde; }

#endif