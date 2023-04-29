#pragma once
#include "Roslina.h"

class Trawa :public Roslina
{
public:
	Trawa(int n_x, int n_y, Swiat* n_swiat);
	~Trawa();
	void rysowanie();
	void stworzOrganizm(int n_x, int n_y);
};

