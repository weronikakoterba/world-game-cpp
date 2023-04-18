#pragma once
#include "Roslina.h"
class Guarana : public Roslina
{
public:
	Guarana(int n_x, int n_y, Swiat* n_swiat);
	~Guarana();
	void kolizja(Organizm* organizm);
	void rysowanie();
	void stworzOrganizm(int n_x, int n_y);
};

