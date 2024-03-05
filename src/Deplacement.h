#ifndef __DEPLACEMENT__H
#define __DEPLACEMENT__H

#include "Monde.h"

class Deplacement {
    private:
        Monde monde;
        void interaction;
    public:
        void deplacement(char action,Monde monde);
        void interaction(char action,Monde monde);
};


#endif