#pragma once
#include <iostream>
#include "Head.h"
#include "Swiat.h"

class Organizm {
	//friend ostream& operator<<(ostream& out, const Organizm& obiekt);
	friend class Swiat;
	friend class Zwierze;
protected:
	Swiat* swiat;
	Gatunek gatunek;
	int sila;
	int inicjatywa;
	int x;
	int y;
public:
	Organizm(int n_sila, int n_inicjatywa, int n_x, int n_y,Gatunek n_gatunek, Swiat* n_swiat);
	~Organizm();
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	virtual void rysowanie() = 0;
};
