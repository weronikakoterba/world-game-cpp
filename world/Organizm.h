#pragma once
#include <iostream>
#include "Head.h"
#include "Swiat.h"

class Organizm 
{
protected:
	Swiat* swiat;
	Gatunek gatunek;
	int inicjatywa;
	int sila;
	int wiek = 0;
	int x;
	int y;
public:
	Organizm(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat);
	~Organizm();
	int getX();
	int getY();
	int getWiek();
	int getInicjatywa();
	int getSila();
	Gatunek getGatunek();
	Swiat* getSwiat();
	void setX(int n_x);
	void setY(int n_y);
	void zwiekszWiek();
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	virtual void rysowanie() = 0;
	virtual bool czyOdbijeAtak(Organizm* organizm) = 0;
	virtual bool czyZaatakuje(int n_x,int n_y) = 0;
	virtual void stworzOrganizm(int n_x, int n_y) = 0;
	virtual bool czyZwiekszaSile(Organizm* organizm) = 0;
	virtual bool smierc() = 0;
	virtual DaneOrganizm pobierz_dane();
};
