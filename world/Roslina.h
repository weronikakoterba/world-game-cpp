#pragma once
#include<iostream>
#include"Organizm.h"
using namespace std;

class Roslina :public Organizm 
{
protected:
	int iloscRozsian = 1;
	bool czyZabijaSasiadow = false;
public:
	Roslina(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat);
	~Roslina();
	virtual void akcja();
	virtual void kolizja(Organizm* organizm);
	virtual void rozsiewanie(int n_x,int n_y);
	virtual bool czyOdbijeAtak(Organizm* organizm);
	virtual bool czyZaatakuje(int n_x,int n_y);
	virtual bool czyZwiekszaSile(Organizm* organizm);
	virtual void zabijanieSasiadow();
	virtual void stworzOrganizm(int n_x, int n_y) = 0;
	virtual bool smierc();
};
