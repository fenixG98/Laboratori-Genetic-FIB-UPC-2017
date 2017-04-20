#include "especie.hh"


especie::especie()
{

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

vector <int> especie::consultar_longitud() const
{
	return l;
}

void especie::llegir()
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

void especie::escriure() const
{
	cout << N << ' ' << lx << ' ' << ly << endl;
	for (int i = 0; i < l.size(); ++i) cout << l[i] << ' ';
}
