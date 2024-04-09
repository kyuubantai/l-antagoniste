#ifndef __DEPLACEMENT__H
#define __DEPLACEMENT__H

#include "Monde.h"

class Deplacement {
    private:
        Monde monde;
        int num_pnj=1000;
        int num_dialogue=1000;
    public:
        void deplace(char action);
        void interaction();
        Monde getMonde() const;
        int getPnj();
        void setPnj(const int& pnj);
        int getDialogue();
        void setDialogue(const int& dial);
};

inline Monde Deplacement::getMonde () const { return monde; }

#endif