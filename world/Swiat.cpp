#include<iostream>
#include"Swiat.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include <vector>
#include <algorithm>
using namespace std;


Swiat::Swiat(int n_wysokosc, int n_szerokosc) :wysokosc(n_wysokosc),szerokosc(n_szerokosc){
	tab = new Organizm ** [n_wysokosc];
	for (int i = 0; i < n_wysokosc; i++) {
		tab[i] = new Organizm* [n_szerokosc];
		for (int j = 0; j < n_szerokosc; j++) {
			tab[i][j] = nullptr;
		}
	}

	// dodawanie wilków
	/*Organizm* nowy = new Wilk(1, 1, this);
	tab[1][1] = nowy;
	wektor.push_back(nowy);*/
	//Organizm* nowy = new Owca(2, 2, this);
	//tab[2][2] = nowy;
	//wektor.push_back(nowy);
	//nowy = new Owca(4, 4, this);
	//tab[4][4] = nowy;
	//wektor.push_back(nowy);
	/*nowy = new Zolw(3, 3, this);
    tab[3][3] = nowy;
	wektor.push_back(nowy);*/
	Organizm* nowy = new Owca(1, 1, this);
	tab[1][1] = nowy;
	wektor.push_back(nowy);
	nowy = new Lis(2, 2, this);
	tab[2][2] = nowy;
	wektor.push_back(nowy);
	/*Organizm* nowy = new Antylopa(1, 1, this);
	tab[1][1] = nowy;
	wektor.push_back(nowy);*/

	//wektor.push_back(nowy);

	/*nowy = new Wilk(5, 5, this);
	tab[5][5] = nowy;
	wektor.push_back(nowy);
	nowy = new Wilk(10, 10, this);
	tab[10][10] = nowy;
	wektor.push_back(nowy);*/
}
Organizm*** Swiat::getTab() {
	return tab;
}

void Swiat::rysujSwiat() {
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			if (tab[i][j] == nullptr) cout << '_';
			else
			{
				tab[i][j]->rysowanie();
			}
		}
		cout << endl;
	}
}
void Swiat::rysujStanGry() {
	cout << "wyniki";
}
Swiat::~Swiat() {
	for (int i = 0; i < wysokosc; ++i) {
		for (int j = 0; j < szerokosc; ++j) {
			if (tab[i][j] != nullptr) {
				cout << "Wywoluje destruktor dla pozycji " << i << ',';
				delete tab[i][j];
			}
		}
	}
	for (int i = 0; i <wysokosc; ++i)
		delete[] tab[i];
	delete[] tab;
	cout << "Zniszczono swiat\n";
}

void Swiat::przesun_organizm(int temp_x, int temp_y, int x, int y)
{
	Organizm* temp = tab[temp_x][temp_y];
	Organizm* noweMiejsce = tab[x][y];
		// czy dochodzi do kolizji?
		if (tab[x][y] != nullptr /*&& temp->czyZaatakuje(noweMiejsce)*/)
		{
			temp->kolizja(tab[x][y]);
		}
		/*else if (tab[x][y] != nullptr && temp->czyZaatakuje(noweMiejsce)==false) {
			return;
		}*/
		else
		{
			tab[temp_x][temp_y] = nullptr;
			tab[x][y] = temp;
		}

	//cout << "Wykonano ruch\n";
}

void Swiat::wykonajTure()
{
	usuwanieZabitych();
	sortowanie();
	unsigned ile = wektor.size();
	for (unsigned i = 0; i < ile; i++)
	{
		if (wektor[i]->getZyje() == true) {
			cout << "chce wykonac akcje " << i << endl;
			wektor[i]->akcja();
		}
	}
	for (int i = 0; i < wektor.size(); i++) {
		wektor[i]->zwiekszWiek();
	}

	
}

bool porownanieOrganizmu(Organizm*& lewy, Organizm*& prawy) {
	if (lewy->getInicjatywa() > prawy->getInicjatywa()) {
		return true;
	}
	else if (lewy->getInicjatywa() == prawy->getInicjatywa()) {
		if (lewy->getWiek()>prawy->getWiek()) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void Swiat::sortowanie() {
	sort(wektor.begin(), wektor.end(), porownanieOrganizmu);
}

bool czyUsunac(Organizm*& organizm) {
	if (organizm->getZyje() == false) {
		return true;
	}
	else {
		return false;
	}
}

void Swiat::usuwanieZabitych() {
	auto zabijanie = remove_if(wektor.begin(), wektor.end(), czyUsunac);
	for (auto i = zabijanie; i != wektor.end(); i++) {
		delete *i;
	}
	wektor.erase(zabijanie,wektor.end());
}

void Swiat::dodajOrganizm(Organizm* organizm, int x, int y)
{
	tab[x][y] = organizm;
	wektor.push_back(organizm);
}
