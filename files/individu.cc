#include "individu.hh"


individu::individu()
{
	amb_mare = amb_pare = false;
	sex1 = 'X';
	
}

void llegir_vector_pair(vector<pair<pair<bool,bool>,int> > &pt, const especie &esp)
{
	for (int i = 0; i < esp.consultar_numero_parells(); ++i)
	{
		cin >> pt[i].first.first;
		cin >> pt[i].first.second;
		cin >> pt[i].second;
	}
}

individu::individu(const individu a, const individu b, especie esp)
{
	amb_mare = amb_pare = true;

	vector<pair<pair<bool, bool>, int> > pt;
	llegir_vector_pair(pt,esp);
}

individu::~individu(){}

string individu::consultar_SEXE() const
{
	return SEXE;
}

bool individu::te_pare() const
{
	return amb_pare;
}


bool individu::te_mare() const
{
	return amb_mare;
}



void individu::llegir(const especie &esp)
{
	COD_GEN = vector<pair<list<bool>, list<bool> > > (esp.consultar_numero_parells()+1);

	int d = esp.consultar_longitud_x();

	cin >> sex2;

	if (sex2=='X') SEXE = "femeni";

	else if (sex2=='Y')
	{
		SEXE = "masculi";
		d = esp.consultar_longitud_y();
	}

	int x;
	for (int i = 0; i < esp.consultar_longitud_x(); ++i)
	{
		cin >> x;
		COD_GEN[0].first.push_back(x);

	}
	for (int i = 0; i < d; ++i)
	{
		cin >> x;
		COD_GEN[0].second.push_back(x);

	}

	for (int i = 1; i <= esp.consultar_numero_parells(); ++i) 	{
		for (int j = 0; j < esp.consultar_longitud_i(i); ++j)
		{
			cin >> x;
			COD_GEN[i].first.push_back(x);
		}
		for (int j = 0; j < esp.consultar_longitud_i(i); ++j)
		{
			cin >> x;
			COD_GEN[i].second.push_back(x);
		}
	}
}

void individu::escriure(const especie &esp) const
{
	int d = esp.consultar_longitud_y();
	if (sex2=='X') d = esp.consultar_longitud_x();

	cout << "  " << sex1 << ": ";
	for(std::list<bool>::const_iterator it = COD_GEN[0].first.begin(); it != COD_GEN[0].first.end(); ++it) cout << *it << ' ';
	cout << endl;

	cout << "  " << sex2 << ": ";
	for(std::list<bool>::const_iterator it = COD_GEN[0].second.begin(); it != COD_GEN[0].second.end(); ++it) cout << *it << ' ';
	cout << endl;

	for (int i = 1; i < COD_GEN.size(); ++i)
	{
		cout << "  " << i << ".1: ";
		for(std::list<bool>::const_iterator it = COD_GEN[i].first.begin(); it != COD_GEN[i].first.end(); ++it) cout << *it << ' ';
		cout << endl;

		cout << "  " << i << ".2: ";
		for(std::list<bool>::const_iterator it = COD_GEN[i].second.begin(); it != COD_GEN[i].second.end(); ++it) cout << *it << ' ';
		cout << endl;
	}
}
