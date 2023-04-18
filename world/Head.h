#pragma once
#include <iostream>

extern int wysokosc;
extern int szerokosc;

struct Wspolrzedne
{
	int x;
	int y;
};

enum Gatunek {
	wilk,
	owca,
	zolw,
	antylopa,
	lis,
	cyberOwca,
	trawa,
	mlecz,
	guarana,
	wilczeJagody,
	barszczSosnowskiego
};


/*ostream& operator<<(ostream& out, const Gatunek& gatunek)
{
	switch (gatunek) {
	case kot:
		out << 'K';
		return out;
	case pies:
		out << 'P';
		return out;
	default:
		return out;
	}
}*/