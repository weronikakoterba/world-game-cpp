#pragma once
#include "Zwierze.h"
class Wilk :public Zwierze
{
public:
	Wilk(int n_x, int n_y, Swiat* n_swiat);
	~Wilk();
	//void akcja();
	void kolizja();
	void rysowanie();
};
