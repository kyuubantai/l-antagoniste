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
		int getVie() const;

		void setVie(int nvVie);

		int getAtk() const;

		void setAtk(int nvAtk);

		int getNrj() const;
};

#endif
