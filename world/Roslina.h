#pragma once
#include<iostream>
#include"Organizm.h"
using namespace std;

class Roslina :public Organizm {
public:
	Roslina(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat);
	~Roslina();
	virtual void akcja();
	virtual void kolizja(Organizm* organizm);
	virtual void rozsiewanie(int n_x,int n_y);
	virtual bool czyOdbijeAtak(Organizm* organizm);
	virtual bool czyZaatakuje(Organizm* organizm);
	virtual bool czyUcieka();
	virtual int iloscRozsian();
	virtual void stworzOrganizm(int n_x, int n_y) = 0;
};
