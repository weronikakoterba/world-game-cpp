#pragma once
#include <iostream>

extern int wysokosc;
extern int szerokosc;

enum Gatunek {
	wilk,
	owca
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