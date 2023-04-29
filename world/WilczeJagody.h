#pragma once
#include "Roslina.h"

class WilczeJagody :public Roslina
{
public:
	WilczeJagody(int n_x, int n_y, Swiat* n_swiat);
	~WilczeJagody();
	void rysowanie();
	void stworzOrganizm(int n_x, int n_y);
	bool smierc(Organizm* organizm);
};

