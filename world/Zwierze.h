#pragma once
#include<iostream>
#include"Organizm.h"
using namespace std;

class Zwierze :public Organizm {
protected:
	int temp_x;
	int temp_y;
public:
	Zwierze(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat);
	~Zwierze();
	virtual void akcja();
	virtual void rozmnazanie(Organizm* organizm);
	virtual void kolizja(Organizm*organizm);
	virtual bool czyOdbijeAtak(Organizm* organizm);
	virtual bool czyZaatakuje(Organizm* organizm);
	virtual bool czyUcieka();
	virtual void stworzOrganizm(int n_x, int n_y) = 0;
};