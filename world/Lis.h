#pragma once
#include "Zwierze.h"
class Lis : public Zwierze
{
public:
	Lis(int n_x, int n_y, Swiat* n_swiat);
	~Lis();
	void akcja(Organizm* organizm,Swiat* swiat);
	//void kolizja();
	void rysowanie();
	void stworzOrganizm(int n_x, int n_y);
	bool czyZaatakuje(Organizm* organizm);
};

