#include<iostream>
#include"Swiat.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;


Swiat::Swiat(int wysokosc, int szerokosc) :wysokosc(wysokosc), szerokosc(szerokosc)
{
	tab = new Organizm **[wysokosc];
	for (int y = 0; y < wysokosc; y++) {
		tab[y] = new Organizm *[szerokosc];
		for (int x = 0; x < szerokosc; x++) {
			tab[y][x] = nullptr;
		}
	}
}
Swiat::Swiat() {}

Swiat::~Swiat()
{
	for (int i = 0; i < wysokosc; ++i) {
		for (int j = 0; j < szerokosc; ++j) {
			if (tab[j][i] != nullptr) {
				delete tab[j][i];
			}
		}
	}
	for (int i = 0; i < wysokosc; ++i)
		delete[] tab[i];
	delete[] tab;
}
int Swiat::getSzerokosc()
{
	return szerokosc;
}

int Swiat::getWysokosc()
{
	return wysokosc;
}

Organizm*** Swiat::getTab() 
{
	return tab;
}

void Swiat::losujPola(int& x, int& y)
{
	while (true) {
		x = rand() % (szerokosc - 1);
		y = rand() % (wysokosc - 1);
		if (tab[y][x] == nullptr) {
			return;
		}
	}
}

void Swiat::rysujOrganizmy()
{
	Organizm* nowy;
	int x;
	int y;
	losujPola(x, y);
	nowy = new Czlowiek(x, y, this);
	tab[y][x] = nowy;
	wektor.push_back(nowy);
	for (int i = 0; i < (getSzerokosc() * getWysokosc()) / PROCENT_ZAJMOWAEJ_PLANSZY; i++) {
		losujPola(x, y);
		nowy = new Owca(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
		losujPola(x, y);
		nowy = new Wilk(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
		losujPola(x, y);
		nowy = new Lis(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
		losujPola(x, y);
		nowy = new Zolw(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
		losujPola(x, y);
		nowy = new Antylopa(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
		losujPola(x, y);
		nowy = new Trawa(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
		losujPola(x, y);
		nowy = new Mlecz(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
		losujPola(x, y);
		nowy = new Guarana(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
		losujPola(x, y);
		nowy = new BarszczSosnowskiego(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
		losujPola(x, y);
		nowy = new WilczeJagody(x, y, this);
		tab[y][x] = nowy;
		wektor.push_back(nowy);
	}
}

void Swiat::dodajWyniki(string wynik) 
{
	wyniki.push_back(wynik);
}

void Swiat::rysujWyniki() 
{
	int ilosc;
	if (wyniki.size() < MAX_ILOSC_POWIADOMIEN) 
	{
		ilosc = wyniki.size();
	}
	else 
	{
		ilosc = MAX_ILOSC_POWIADOMIEN;
	}
	for (int i = 0; i < ilosc; i++) {
		cout << wyniki[i] << endl;
	}
}

void Swiat::rysujSwiat()
{
	for (int y = 0; y < wysokosc; y++) {
		for (int x = 0; x < szerokosc; x++) {
			if (tab[y][x] == nullptr) cout << '_';
			else
			{
				tab[y][x]->rysowanie();
			}
		}
		cout << endl;
	}
}

void Swiat::przesunOrganizm(int temp_x, int temp_y, int x, int y, bool sprawdzaj)
{
	Organizm* temp = tab[temp_y][temp_x];
	if (sprawdzaj && tab[y][x] != nullptr)
	{
		temp->kolizja(tab[y][x]);
	}
	else
	{
		tab[temp_y][temp_x] = nullptr;
		tab[y][x] = temp;
		temp->setX(x);
		temp->setY(y);
	}
}

void Swiat::wykonajTure()
{
	wyniki.clear();
	cout << "TURA:" << tura << endl;
	sortowanie();
	unsigned ile = wektor.size();
	for (unsigned i = 0; i < ile; i++)
	{
		if (wektor[i] != nullptr) {
			wektor[i]->akcja();
		}
	}
	wektor.erase(remove(wektor.begin(), wektor.end(), nullptr), wektor.end());
	for (int i = 0; i < wektor.size(); i++) {
		if (wektor[i] != nullptr) {
			wektor[i]->zwiekszWiek();
		}
	}
	tura++;
}

void Swiat::nowaTura() {
	char znak;
	while (true)
	{
		znak = _getch();
		if (znak == 't') {
			break;
		}
	}
	system("cls");
}

bool porownanieOrganizmu(Organizm*& lewy, Organizm*& prawy) {
	if (lewy->getInicjatywa() > prawy->getInicjatywa()) {
		return true;
	}
	else if (lewy->getInicjatywa() == prawy->getInicjatywa()) {
		if (lewy->getWiek() > prawy->getWiek()) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void Swiat::sortowanie()
{
	sort(wektor.begin(), wektor.end(), porownanieOrganizmu);
}

void Swiat::usunOrganizm(Organizm* organizm)
{
	// usuniêcie z wektora
	unsigned size = wektor.size();
	for (unsigned i = 0; i < size; i++) 
	{
		if (wektor[i] == organizm) 
		{
			wektor[i] = nullptr;
			break;
		}
	}
	// usuniêcie z planszy
	for (int x = 0; x < szerokosc; x++) 
	{
		for (int y = 0; y < wysokosc; y++) 
		{
			if (tab[y][x] == organizm)
			{
				delete tab[y][x];
				tab[y][x] = nullptr;
				return;
			}
		}
	}

}

void Swiat::dodajOrganizm(Organizm* organizm, int x, int y)
{
	tab[y][x] = organizm;
	wektor.push_back(organizm);
}

int Swiat::zapiszDoPliku(bool aktywowanaUmiejetnosc, int ileDoKonca, int ileDoStartu)
{
	ofstream plik;
	string nazwaPliku;
	cout << "PODAJ NAZWE PLIKU:";
	cin >> nazwaPliku;
	plik.open(nazwaPliku);
	plik << aktywowanaUmiejetnosc << endl;
	plik << ileDoKonca << endl;
	plik << ileDoStartu << endl;
	plik << szerokosc << endl;
	plik << wysokosc << endl;
	plik << tura << endl;

	unsigned size = wektor.size();

	for (unsigned i = 0; i < size; ++i)
	{
		if (wektor[i] != nullptr) 
		{
			DaneOrganizm dane = wektor[i]->pobierz_dane();
			plik << dane;
		}
	}

	plik.close();
	return 0;
}

int Swiat::uruchomZPliku()
{
	ifstream plik;
	string nazwaPliku;
	bool aktywowanaUmiejetnosc;
	int ileDoKonca;
	int ileDoStartu;
	while (true) {
		cout << "PODAJ NAZWE PLIKU:";
		cin >> nazwaPliku;
		plik.open(nazwaPliku);
		if (plik.is_open()) {
			break;
		}
		cout << "PODANY PLIK NIE ISTNIEJE" << endl;
	}
	plik >> aktywowanaUmiejetnosc;
	plik >> ileDoKonca;
	plik >> ileDoStartu;
	plik >> szerokosc;
	plik >> wysokosc;
	plik >> tura;
	Organizm* nowy;

	int gatunek, x, y, sila, wiek;
	while (plik >> gatunek >> sila >> wiek >> x >> y) 
	{
		switch (gatunek)
		{
		case Gatunek::wilk:
			nowy = new Wilk(x, y, this);
			break;
		case Gatunek::owca:
			nowy = new Owca(x, y, this);
			break;
		case Gatunek::zolw:
			nowy = new Zolw(x, y, this);
			break;
		case Gatunek::antylopa:
			nowy = new Antylopa(x, y, this);
			break;
		case Gatunek::lis:
			nowy = new Lis(x, y, this);
			break;
		case Gatunek::trawa:
			nowy = new Trawa(x, y, this);
			break;
		case Gatunek::mlecz:
			nowy = new Mlecz(x, y, this);
			break;
		case Gatunek::guarana:
			nowy = new Guarana(x, y, this);
			break;
		case Gatunek::wilczeJagody:
			nowy = new WilczeJagody(x, y, this);
			break;
		case Gatunek::barszczSosnowskiego:
			nowy = new BarszczSosnowskiego(x, y, this);
			break;
		case Gatunek::czlowiek:
			nowy = new Czlowiek(x, y, this, aktywowanaUmiejetnosc, ileDoKonca, ileDoStartu);
			break;
		}
		wektor.push_back(nowy);
	}
	tab = new Organizm * *[wysokosc];
	for (int y = 0; y < wysokosc; y++) 
	{
		tab[y] = new Organizm * [szerokosc];
		for (int x = 0; x < szerokosc; x++) 
		{
			tab[y][x] = nullptr;
		}
	}
	for (int i = 0; i < wektor.size(); i++) 
	{
		int x = wektor[i]->getX();
		int y = wektor[i]->getY();
		tab[y][x] = wektor[i];
	}
	return 0;
}

void Swiat::wazneInformacje() 
{
	cout << "Weronika Koterba, 193127" << endl;
	cout << "MENU" << endl;
	cout << "\30 - gora, \31 - dol, \20 - prawo, \21 - lewo " << endl;
	cout << "t - nowa tura" << endl;
	cout << "s - zapisz stan gry do pliku" << endl;
	cout << "enter - szybkosc antylopy" << endl;
}

string Swiat::wypiszOrganizmy(Organizm* organizm)
{
	switch (organizm->getGatunek())
	{
	case Gatunek::wilk:
		return "wilk ";
	case Gatunek::owca:
		return "owca ";
	case Gatunek::zolw:
		return "zolw ";
	case Gatunek::antylopa:
		return "antylopa ";
	case Gatunek::lis:
		return "lis ";
	case Gatunek::trawa:
		return "trawa ";
	case Gatunek::mlecz:
		return "mlecz ";
	case Gatunek::guarana:
		return "guarana ";
	case Gatunek::wilczeJagody:
		return "wilcze jagody ";
	case Gatunek::barszczSosnowskiego:
		return "barszcz sosnowskiego ";
	case Gatunek::czlowiek:
		return "czlowiek ";
	}
}

ostream& operator<<(ostream& os, const DaneOrganizm& obiekt)
{

	os << obiekt.gatunek << ' ' << obiekt.sila << ' ' << obiekt.wiek << ' ' << obiekt.x << ' ' << obiekt.y << endl;
	return os;
}

DaneOrganizm Swiat::operator[](size_t index)
{
	return wektor[index]->pobierz_dane();
}