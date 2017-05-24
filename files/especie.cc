/** @file especie.cc
    @brief Codigo de la clase c_especie
*/

#include "especie.hh"


c_especie::c_especie()
{
	N = lx = ly = 0;
	l = vector<int> (0);
}

c_especie::~c_especie(){}

int c_especie::consultar_numero_parells() const
{
	return N;
}

int c_especie::consultar_longitud_x() const
{
	return lx;
}

int c_especie::consultar_longitud_y() const
{
	return ly;
}

int c_especie::consultar_longitud_i(int i) const
{
	return l[i];
}

int c_especie::consultar_longitud_repro() const
{
	return l[0];
}

void c_especie::llegir()
{
	int x;
	cin >> N;

	for (int i = 0; i <= N; ++i)
	{
		cin >> x;
		l.push_back(x);
	}

	cin >> lx >> ly;
}
