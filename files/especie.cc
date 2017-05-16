#include "especie.hh"


especie::especie()
{
	N = lx = ly = 0;
	l = vector<int> (0);
}

especie::~especie(){}

int especie::consultar_numero_parells() const
{
	return N;
}

int especie::consultar_longitud_x() const
{
	return lx;
}

int especie::consultar_longitud_y() const
{
	return ly;
}

int especie::consultar_longitud_i(int i) const
{
	return l[i];
}

void especie::llegir()
{
	int x;
	std::cin >> N;
	for (int i = 0; i <= N; ++i)
	{
		std::cin >> x;
		l.push_back(x);
	}
	cin >> lx >> ly;
	pt = vector<pair<pair<bool,bool>,int> > (N+1);
}
