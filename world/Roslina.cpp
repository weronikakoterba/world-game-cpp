#include<iostream>
#include"Roslina.h"
#include "Swiat.h"
using namespace std;

Roslina::Roslina(int n_sila, int n_inicjatywa, int n_x, int n_y, Gatunek n_gatunek, Swiat* n_swiat) :
	Organizm(n_sila, n_inicjatywa, n_x, n_y, n_gatunek, n_swiat) {}

Roslina::~Roslina() {}

void Roslina::rozsiewanie(int x, int y)
{
	if (swiat->getTab()[y][x] == nullptr) {
		stworzOrganizm(x, y);
	}
	else {
		return;
	}
}

void Roslina::akcja()
{
	for (int i = 0; i < iloscRozsian; i++) 
	{
		short szansaZasiania = rand() % SZANSA_NA_ROZSIANIE;
		if (szansaZasiania == 0) 
		{
			vector<Wspolrzedne> dostepne;
			Wspolrzedne kierunek;
			if (x > 0)
			{
				kierunek.x = x - 1;
				kierunek.y = y;
				dostepne.push_back(kierunek);
			}
			if (x < swiat->getSzerokosc() - 1)
			{
				kierunek.x = x + 1;
				kierunek.y = y;
				dostepne.push_back(kierunek);
			}
			if (y < swiat->getWysokosc() - 1)
			{
				kierunek.x = x;
				kierunek.y = y + 1;
				dostepne.push_back(kierunek);
			}
			if (y > 0)
			{
				kierunek.x = x;
				kierunek.y = y - 1;
				dostepne.push_back(kierunek);
			}

			kierunek = dostepne[rand() % dostepne.size()];
			rozsiewanie(kierunek.x, kierunek.y);
		}
	}
	if (czyZabijaSasiadow == true) {
		zabijanieSasiadow();
	}
}

void Roslina::zabijanieSasiadow()
{
	if (x < swiat->getSzerokosc() - 1)
	{
		if (swiat->getTab()[y][x + 1] != nullptr)
		{
			if (swiat->getTab()[y][x + 1]->getGatunek() != getGatunek())
			{
				if (swiat->getTab()[y][x + 1]->getInicjatywa() != 0)
				{
					swiat->usunOrganizm(swiat->getTab()[y][x + 1]);
				}
			}
		}
	}
	if (x > 0) {
		if (swiat->getTab()[y][x - 1] != nullptr)
		{
			if (swiat->getTab()[y][x - 1]->getGatunek() != getGatunek())
			{
				if (swiat->getTab()[y][x - 1]->getInicjatywa() != 0)
				{
					swiat->usunOrganizm(swiat->getTab()[y][x - 1]);
				}
			}
		}
	}
	if (y < swiat->getWysokosc() - 1)
	{
		if (swiat->getTab()[y + 1][x] != nullptr)
		{
			if (swiat->getTab()[y + 1][x]->getGatunek()!= getGatunek())
			{
				if (swiat->getTab()[y + 1][x]->getInicjatywa() != 0)
				{
					swiat->usunOrganizm(swiat->getTab()[y + 1][x]);
				}
			}
		}
	}
	if (y > 0) {
		if (swiat->getTab()[y - 1][x] != nullptr)
		{
			if (swiat->getTab()[y - 1][x]->getGatunek() != getGatunek())
			{
				if (swiat->getTab()[y - 1][x]->getInicjatywa() != 0)
				{
					swiat->usunOrganizm(swiat->getTab()[y - 1][x]);
				}
			}
		}
	}
}

void Roslina::kolizja(Organizm* organizm) {}

bool Roslina::czyOdbijeAtak(Organizm* organizm)
{
	return false;
}

bool Roslina::czyZaatakuje(int n_x,int n_y)
{
	return true;
}
bool Roslina::czyZwiekszaSile(Organizm* organizm)
{
	return false;
}
bool Roslina::smierc()
{
	return false;
}

