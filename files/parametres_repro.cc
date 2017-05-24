/** @file parametres_repro.cc
    @brief Codigo de la clase par_rep
*/

#include "parametres_repro.hh"

par_rep::par_rep(c_especie &esp)
{
	pr = vector <pair<pair<bool,bool>,int> > (esp.consultar_numero_parells()+1);
	lenRep = esp.consultar_longitud_repro();
}

par_rep::~par_rep(){}

int par_rep::consultar_punt_tall(int i) const
{
	return pr[i].second;
}

pair<bool,bool> par_rep::consultar_ovul_esper(int i) const
{
	pair<bool,bool> res;

	res.first = pr[i].first.first;
	res.second =  pr[i].first.second;

	return res;
}

int par_rep::consultar_len_rep() const
{
	return lenRep;
}

void par_rep::llegir_parametres_reproduccio()
{
	for (int i = 0; i < pr.size(); ++i)
	{
		cin >> pr[i].first.first;
		cin >> pr[i].first.second;
		cin >> pr[i].second;
	}
}
