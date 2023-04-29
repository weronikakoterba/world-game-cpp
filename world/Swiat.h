#pragma once
#include <iostream>
#include <vector>

#include "Head.h"

using namespace std;

struct DaneOrganizm
{
	Gatunek gatunek;
	int inicjatywa;
	int sila;
	int wiek;
	int x;
	int y;
};

class Swiat 
{
	int wysokosc;
	int szerokosc;
	int tura = 1;
	Organizm*** tab;
	vector<Organizm*> wektor;
	vector<string> wyniki;
public:
	Swiat(int x, int y);
	Swiat();
	~Swiat();
	int getSzerokosc();
	int getWysokosc();
	Organizm*** getTab();
	void wykonajTure();
	void nowaTura();
	void rysujSwiat();
	void rysujOrganizmy();
	void rysujWyniki();
	void dodajWyniki(string wynik);
	void losujPola(int& x, int& y);
	string wypiszOrganizmy(Organizm* orgnizm);
	void sortowanie();
	void usunOrganizm(Organizm* organizm);
	void dodajOrganizm(Organizm* organizm, int x, int y);
	void przesunOrganizm(int temp_x, int temp_y, int x, int y, bool sprawdzaj);
	int zapiszDoPliku(bool aktywowanaUmiejetnosc, int ileDoKonca, int ileDoStartu);
	int uruchomZPliku();
	void wazneInformacje();
	DaneOrganizm operator[](size_t index);
};

ostream& operator<<(ostream& os, const DaneOrganizm& obiekt);

