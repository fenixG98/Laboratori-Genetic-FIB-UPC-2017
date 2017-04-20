#include "parell_cromosoma.hh"


parell_cromosoma::parell_cromosoma()
{
	l = 0;

}

parell_cromosoma::parell_cromosoma(int l, int i)
{
	c1 = vector <bool> (l);
	c2 = vector <bool> (l);
	this->i = i;

}


parell_cromosoma::~parell_cromosoma(){}


int parell_cromosoma::consultar_longitud() const
{
	return l;
}

void parell_cromosoma::llegir()
{
	bool x;
	for (int j = 0; j < l; ++j)
	{
		cin >> x;
		c1[j] = x;
	}
	for (int j = 0; j < l; ++j)
	{
		cin >> x;
		c2[j] = x;
	}
}

void parell_cromosoma::escriure() const
{

}
