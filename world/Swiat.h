#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Organizm.h"

using namespace std;
class Swiat {
	friend class Zwierze;
	friend class Lis;
	friend class Roslina;
	friend class Antylopa;
	friend class Guarana;
	Organizm*** tab;
protected:
	int szerokosc;
	int wysokosc;
	vector<Organizm*> wektor;
public:
	Swiat(int x,int y);
	Organizm*** getTab();
	 void wykonajTure();
	 void rysujSwiat();
	 void rysujStanGry();
	 void sortowanie();
	 void usuwanieZabitych();
	 void usun_organizm(Organizm* organizm);
	 void dodajOrganizm(Organizm* organizm, int x, int y);
	 //void zabijOrganizm(Organizm* organizm);
	 ~Swiat();
	 void przesun_organizm(int temp_x, int temp_y, int x, int y);
};

