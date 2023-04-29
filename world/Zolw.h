#pragma once
#include "Zwierze.h"

class Zolw :public Zwierze
{
public:
	Zolw(int n_x, int n_y, Swiat* n_swiat);
	~Zolw();
	void rysowanie();
	bool czyOdbijeAtak(Organizm* organizm);
	void stworzOrganizm(int n_x, int n_y);
};

