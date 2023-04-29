#pragma once
#include "Roslina.h"

class BarszczSosnowskiego :public Roslina
{
public:
	BarszczSosnowskiego(int n_x, int n_y, Swiat* n_swiat);
	~BarszczSosnowskiego();
	void rysowanie();
	void stworzOrganizm(int n_x, int n_y);
	bool smierc();
};

