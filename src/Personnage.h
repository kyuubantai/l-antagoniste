#ifndef __PERSONNAGE__H
#define __PERSONNAGE__H

#include "Competence.h"
using namespace std;

class Personnage {
	private:
		int vie;
		int vieMax;
		int atkBase;
		int energie;
		Competence comp[3];
	public:
		int getVie();

		void setVie(const int& nvVie);

		int getAtk();

		void setAtk(const int& nvAtk);

		int getNrj();
};

#endif
