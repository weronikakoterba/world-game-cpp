#pragma once
#include "Zwierze.h"
class Antylopa :public Zwierze
{
public:
	Antylopa(int n_x, int n_y, Swiat* n_swiat);
	~Antylopa();
	void akcja();
	void stworzOrganizm(int n_x, int n_y);
	void wybieraniePolaObok(int n_x,int n_y);
	void rysowanie();
};

