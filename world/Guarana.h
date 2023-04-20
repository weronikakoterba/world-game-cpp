#pragma once
#include "Roslina.h"
class Guarana : public Roslina
{
public:
	Guarana(int n_x, int n_y, Swiat* n_swiat);
	~Guarana();
	void rysowanie();
	void stworzOrganizm(int n_x, int n_y);
	bool czyZwiekszaSile(Organizm* organizm);
};

