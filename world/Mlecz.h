#pragma once
#include "Roslina.h"

class Mlecz :public Roslina
{
public:
	Mlecz(int n_x, int n_y, Swiat* n_swiat);
	~Mlecz();
	void rysowanie();
	void stworzOrganizm(int n_x, int n_y);
};

