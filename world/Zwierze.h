#pragma once
#include<iostream>
#include"Organizm.h"
using namespace std;

class Zwierze :public Organizm 
{
protected:
	int temp_x;
	int temp_y;
	int mozliwoscRuchu = 1;
public:
	Zwierze(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat);
	~Zwierze();
	virtual void akcja();
	virtual void rozmnazanie(Organizm* organizm);
	virtual void kolizja(Organizm*organizm);
	virtual bool czyOdbijeAtak(Organizm* organizm);
	virtual bool czyZaatakuje(int n_x, int n_y);
	virtual void stworzOrganizm(int n_x, int n_y) = 0;
	virtual bool czyZwiekszaSile(Organizm* organizm);
	virtual bool smierc();
};