#include <iostream>
#include "Organizm.h"
using namespace std;

Organizm::Organizm(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat) 
	:sila(n_sila), inicjatywa(n_inicjatywa),x(n_x),y(n_y),gatunek(n_gatunek), swiat(n_swiat) {}

Organizm::~Organizm() {}

int Organizm::getWiek()
{
	return wiek;
}

int Organizm::getInicjatywa() 
{
	return inicjatywa;
}

int Organizm::getSila() 
{
	return sila;
}

Gatunek Organizm::getGatunek() 
{
	return gatunek;
}

int Organizm::getX() 
{
	return x;
}

int Organizm::getY()
{
	return y;
}

Swiat* Organizm::getSwiat() 
{
	return swiat;
}

void Organizm::zwiekszWiek()
{
	wiek++;
}

void Organizm::setX(int n_x) 
{
	x = n_x;
}

void Organizm::setY(int n_y)
{
	y = n_y;
}

DaneOrganizm Organizm::pobierz_dane() 
{
	DaneOrganizm wynik;
	wynik.gatunek = gatunek;
	wynik.sila = sila;
	wynik.wiek = wiek;
	wynik.x = x;
	wynik.y = y;
	return wynik;
}