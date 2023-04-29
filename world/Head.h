#pragma once
#include <iostream>
#include <string>
#include <conio.h>

#define DODATKOWA_SILA 3
#define MAX_ILOSC_POWIADOMIEN 6
#define ILOSC_TUR 5
#define TURY_Z_PELNA_UMIEJTNOSCIA 3
#define PREDKOSC_ANTYLOPY 2
#define	SZANSA 2
#define	SZANSA_NA_ROZSIANIE 20
#define	ILOSC_ROZSIAN_MLECZA 3
#define SZANSA_ZOLWIA_NA_RUCH 4
#define MIN_WYMIARY 10
#define SYSTEM_LICZBOWY 10
#define PROCENT_ZAJMOWAEJ_PLANSZY 100

class Organizm;

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
	trawa,
	mlecz,
	guarana,
	wilczeJagody,
	barszczSosnowskiego,
	czlowiek
};

enum KEYS
{
	key_enter = 0x0d,
	key_left_arrow = 0x4b,
	key_right_arrow = 0x4d,
	key_up_arrow = 0x48,
	key_down_arrow = 0x50,
	key_escape = 0x1b
};