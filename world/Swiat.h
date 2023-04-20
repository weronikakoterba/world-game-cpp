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
	Organizm*** tab;
protected:
	vector<Organizm*> wektor;
public:
	Swiat(int x,int y);
	~Swiat();
	 void wykonajTure();
	 void rysujSwiat();
	 void rysujStanGry();
	 void sortowanie();
	 void usunOrganizm(Organizm* organizm);
	 void dodajOrganizm(Organizm* organizm, int x, int y);
	 void przesunOrganizm(int temp_x, int temp_y, int x, int y, bool sprawdzaj);
};

