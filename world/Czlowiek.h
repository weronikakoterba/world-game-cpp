#pragma once
#include "Zwierze.h"

class Czlowiek :public Zwierze
{
	bool aktywowanaUmiejetnosc;
	int ileDoKonca;
	int ileDoStartu;
public:
	Czlowiek(int n_x, int n_y, Swiat* n_swiat);
	Czlowiek(int n_x, int n_y, Swiat* n_swiat, bool aktywowanaUmiejetnosc, int ileDoKonca,int ileDoStartu);
	~Czlowiek();
	bool getAktywowanaUmijetnpsc();
	int getIleDoKonca();
	int getIleDoStartu();
	void czyMoznaAktywowacUmiejetnosc();
	void akcja();
	void rysowanie();
	void stworzOrganizm(int n_x, int n_y);
};

