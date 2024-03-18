#ifndef __DEPLACEMENT__H
#define __DEPLACEMENT__H

#include"Monde.h"

class Deplacement {
    private:
        Monde monde;
    public:
        void deplace(char action);
        Monde getMonde() const;
};

inline Monde Deplacement::getMonde () const { return monde; }

#endif