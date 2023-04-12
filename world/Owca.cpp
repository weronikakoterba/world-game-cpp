#include "Owca.h"
Owca::Owca(int n_x, int n_y, Swiat* n_swiat) : Zwierze(4, 4, n_x, n_y, Gatunek::owca, n_swiat) {
}

Owca::~Owca()
{
	cout << "Owca umiera\n";
}
void Owca::rysowanie() {}
