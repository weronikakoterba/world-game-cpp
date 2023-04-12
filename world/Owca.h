#pragma once
#include "Zwierze.h"
#include "Swiat.h"
class Owca : public Zwierze
{
public:
	Owca(int n_x, int n_y, Swiat* n_swiat);
	~Owca();
	void rysowanie();
};

