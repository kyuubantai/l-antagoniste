#ifndef __PERSONNAGE__H
#define __PERSONNAGE__H

#include "Competence.h"
using namespace std;

struct Personnage {
	public:
		int vie;
		int vieMax;
		int atkBase;
		int energie;
		Competence comp[3];
};

#endif
