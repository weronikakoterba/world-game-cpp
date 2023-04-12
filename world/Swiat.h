#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Organizm.h"

using namespace std;
class Swiat {
	friend class Zwierze;
	Organizm*** tab;
protected:
	int szerokosc;
	int wysokosc;
	vector<Organizm*> wektor;
public:
	Swiat(int x,int y);
	int getSzerokosc();
	int getWysokosc();
	 void wykonajTure();
	 void rysujSwiat();
	 void rysujStanGry();
	 ~Swiat();
	 void przesun_organizm(int temp_x, int temp_y, int x, int y);
};

