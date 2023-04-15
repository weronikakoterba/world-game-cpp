#pragma once
#include <iostream>
#include "Head.h"


class Organizm {
	//friend ostream& operator<<(ostream& out, const Organizm& obiekt);
	friend class Swiat;
	friend class Zwierze;
protected:
	
	Swiat* swiat;
	Gatunek gatunek;
	bool zyje = true;
	int inicjatywa;
	int sila;
	int wiek = 0;
	int x;
	int y;
public:
	int getWiek();// todo zrobic privte!
	int getInicjatywa();
	int getSila();
	bool getZyje();
	Organizm(int n_sila, int n_inicjatywa, int n_x, int n_y,Gatunek n_gatunek, Swiat* n_swiat);
	~Organizm();
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	virtual void rysowanie() = 0;
	virtual bool czyOdbijeAtak(Organizm* organizm) = 0;
	virtual bool czyZaatakuje(Organizm* organizm) = 0;
	virtual void stworzOrganizm(int n_x, int n_y) = 0;
	void zwiekszWiek();
};
