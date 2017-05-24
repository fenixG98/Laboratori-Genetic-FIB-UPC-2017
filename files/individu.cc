/** @file individu.cc
    @brief Codigo de la clase c_individu
*/
#include "individu.hh"

// Privats

list<bool> c_individu::creurar_llistes(int l, int n, const list<bool> &l1, const list<bool> &l2)
{
	list <bool> aux;
	int cont = 0;
	list<bool>::const_iterator it_end;
	list<bool>::const_iterator it_end_aux;

	it_end = l1.begin();
	advance(it_end,n);
	for(list<bool>::const_iterator it=l1.begin(); it != it_end; ++it)
	{
		aux.push_back(*it);
		++cont;
	}

	it_end = it_end_aux = l2.begin();
	advance(it_end,n);
	advance(it_end_aux,l);
	for( list<bool>::const_iterator it=it_end; it != it_end_aux; ++it)
	{
		aux.push_back(*it);
		++cont;
	}

	if(cont < l1.size())
	{
		it_end = l1.begin();
		advance(it_end,cont);
		for( list<bool>::const_iterator it=it_end; it != l1.end(); ++it)  aux.push_back(*it);
	}

	return aux;
}

// Publics

c_individu::c_individu()
{
	amb_pares = false;
}

c_individu::c_individu(par_rep &pr,const c_individu &a, const c_individu &b)
{
	amb_pares = true;

	if (pr.consultar_ovul_esper(0).second) SEXE = 1;
	else SEXE = 0;

	COD_GEN = vector<pair<list<bool>, list<bool> > > (a.COD_GEN.size());

	list <bool> aux1, aux2;
	for (int i = 0; i < a.COD_GEN.size(); ++i)
	{
		if (not pr.consultar_ovul_esper(i).first) aux1 = a.COD_GEN[i].first;
		else aux1 = a.COD_GEN[i].second;

		if (not pr.consultar_ovul_esper(i).second) aux2 = b.COD_GEN[i].first;
		else aux2 = b.COD_GEN[i].second;

		if (i!=0)
		{
			COD_GEN[i].first = creurar_llistes(int(aux1.size()), pr.consultar_punt_tall(i), aux1, aux2);
			COD_GEN[i].second = creurar_llistes(int(aux2.size()), pr.consultar_punt_tall(i), aux2, aux1);
		}

		else
		{
			COD_GEN[i].first = creurar_llistes(pr.consultar_len_rep(), pr.consultar_punt_tall(i), aux1, aux2);
			COD_GEN[i].second = creurar_llistes(pr.consultar_len_rep(),pr.consultar_punt_tall(i), aux2, aux1);
		}
	}
}

c_individu::~c_individu(){}

bool c_individu::consultar_SEXE() const
{
	return SEXE;
}

bool c_individu::te_pares() const
{
	return amb_pares;
}

void c_individu::llegir(const c_especie &esp)
{
	COD_GEN = vector<pair<list<bool>, list<bool> > > (esp.consultar_numero_parells()+1);

	int d = esp.consultar_longitud_x();
	char sex2;
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

	for (int i = 1; i <= esp.consultar_numero_parells(); ++i)
	{
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

void c_individu::escriure() const
{
	cout << "  " << "X:";
	for(std::list<bool>::const_iterator it = COD_GEN[0].first.begin(); it != COD_GEN[0].first.end(); ++it) cout << ' ' << *it ;
	cout << endl;

	cout << "  ";

	if (consultar_SEXE()) cout << 'Y';
	else cout << 'X';
	cout << ':';
	for(std::list<bool>::const_iterator it = COD_GEN[0].second.begin(); it != COD_GEN[0].second.end(); ++it) cout << ' ' << *it;
	cout << endl;

	for (int i = 1; i < COD_GEN.size(); ++i)
	{
		cout << "  " << i << ".1:";
		for(std::list<bool>::const_iterator it = COD_GEN[i].first.begin(); it != COD_GEN[i].first.end(); ++it) cout << ' ' << *it;
		cout << endl;

		cout << "  " << i << ".2:";
		for(std::list<bool>::const_iterator it = COD_GEN[i].second.begin(); it != COD_GEN[i].second.end(); ++it) cout << ' ' << *it;
		cout << endl;
	}
}
