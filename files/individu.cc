#include "individu.hh"


individu::individu()
{
	amb_mare = amb_pare = false;
	sex1 = 'X';
	
}

individu::individu(const vector<pair<pair<bool, bool>, int> > &pt,const individu a, const individu b, especie esp)
{
	amb_mare = amb_pare = true;
	sex1 = 'X';
	if (pt[0].first.second)
	{
		SEXE = 1;
		sex2 = 'Y';
	}
	else
	{
		SEXE = 0;
		sex2 = 'X';
	}

<<<<<<< HEAD
	COD_GEN = vector<pair<list<bool>, list<bool> > > (a.COD_GEN.size());
	
	this->COD_GEN = a.COD_GEN; ///////////////////// COREGIR
=======
	COD_GEN = vector<pair<list<bool>, list<bool> > > (esp.consultar_numero_parells()+1);
	int n;
	for (int i = 1; i < esp.consultar_numero_parells()+1; ++i)
	{
		n = pt[i].second;

		list<bool> aux1;
		if (not pt[i].first.first) aux1 = a.COD_GEN[i].first;
		else aux1 = a.COD_GEN[i].second;

		list<bool> aux2;	
		if (not pt[i].first.second) aux2 = b.COD_GEN[i].first;
		else aux2 = b.COD_GEN[i].second;
	
		COD_GEN[i].first = creurar_llistes(n, aux1, aux2);
		COD_GEN[i].second = creurar_llistes(n, aux2, aux1);
	}

>>>>>>> master
}

individu::~individu(){}

<<<<<<< HEAD
=======
list<bool> individu::creurar_llistes(int n, const list<bool> &l1, const list<bool> &l2)
{
    list<bool> aux;

    list<bool>::const_iterator it_end = l1.begin();
    advance(it_end,n);

    for( list<bool>::const_iterator it=l1.begin(); it != it_end; ++it) 
    {
        aux.push_back(*it);
    }

    it_end = l2.begin();
    advance(it_end,n);
    for( list<bool>::const_iterator it=it_end; it != l2.end(); ++it) 
    {
        aux.push_back(*it);
    }
    return aux;
}


>>>>>>> master
bool individu::consultar_SEXE() const
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

	if (sex2=='X') SEXE = 0;

	else if (sex2=='Y')
	{
		SEXE = 1;
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

void individu::escriure() const
{
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
