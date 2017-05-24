/** @file poblacio.cc
    @brief Codigo de la clase c_poblacio
*/

#include "poblacio.hh"

// Privats

void c_poblacio::r_generar_arbre_genealogic(Arbre<string> &a, map<string,persona>::const_iterator it)
{
	Arbre<string> a1;
	Arbre<string> a2;

	if(it!=vind.end())
	{
		r_generar_arbre_genealogic(a1, it->second.pare);
		r_generar_arbre_genealogic(a2, it->second.mare);

		a.plantar(it->first,a1,a2);
	}
}

void c_poblacio::r_arbre_genealogic(queue<string> &q, int cont)
{
	if(not q.empty())
	{
		cout << "  Nivel "<<cont<<':';
		queue<string> aux;
		++cont;

		while (not q.empty())
		{
			cout << ' ' << q.front();

			if (vind.find(q.front())->second.ind.te_pares())
			{
				aux.push(vind.find(q.front())->second.pare->first);
				aux.push(vind.find(q.front())->second.mare->first);
			}

			q.pop();
		}
		cout << endl;

		r_arbre_genealogic(aux, cont);
	}
}

bool c_poblacio::r_comprobar_ascendent(string x, string marca)
{
	bool b;

	if (x==marca) return true;
	if (vind.find(x)->second.mare == vind.end()) return false;

	string a1 = vind.find(x)->second.mare->first;
	string a2 = vind.find(x)->second.pare->first;

	b=r_comprobar_ascendent(a1,marca);
	if (not b) b=r_comprobar_ascendent(a2,marca);
	return b;
}

// Publics

c_poblacio::c_poblacio() {}

c_poblacio::~c_poblacio() {}

void c_poblacio::afegir_individu(const string nom, const c_individu& ind)
{
	vind[nom].ind=ind;
	vind[nom].pare=vind.end();
	vind[nom].mare=vind.end();
}

void c_poblacio::afegir_pares(const string a, const string b, const string c)
{
	vind.find(c)->second.mare = vind.find(a);
	vind.find(c)->second.pare = vind.find(b);
}

bool c_poblacio::compatibles(const string a,const string b)
{
	if (vind.find(a)->second.ind.consultar_SEXE() == vind.find(b)->second.ind.consultar_SEXE()) return false;
	if (vind.find(a)->second.ind.consultar_SEXE() and not vind.find(b)->second.ind.consultar_SEXE()) return false;
	if (vind.find(a)->second.ind.te_pares() and vind.find(b)->second.ind.te_pares()) if((vind.find(a)->second.mare->first == vind.find(b)->second.mare->first)or(vind.find(a)->second.pare->first == vind.find(b)->second.pare->first))return false;

	bool x, y;
	x = r_comprobar_ascendent(a,b);
	y = r_comprobar_ascendent(b,a);

	return not (x or y);
}

c_individu c_poblacio::individu_nom(const string nom) const
{
	return vind.find(nom)->second.ind;
}

bool c_poblacio::existeix_individu(const string nom) const
{
	return vind.count(nom)!=0;
}

arbre_parcial c_poblacio::arbre_genealogic(const string nom)
{
	Arbre<string> aux;
	r_generar_arbre_genealogic(aux,vind.find(nom));
	arbre_parcial res (aux);

	return res;
}

void c_poblacio::llegir(const c_especie &esp)
{
	int nind;
	cin >> nind;

	for (int a = 0; a < nind; ++a)
	{
		string nom;
		cin >> nom;

		c_individu ind;
		ind.llegir(esp);

		vind[nom].ind=ind;
		vind[nom].pare=vind.end();
		vind[nom].mare=vind.end();
	}
}

void c_poblacio::escriure() const
{
	for(map<string,persona>::const_iterator it = vind.begin(); it != vind.end(); ++it)
	{
		cout << "  " << it->first << " X";
		if(it->second.ind.consultar_SEXE()) cout << "Y";
		else cout << "X";
		cout << " (";

		if (not it->second.ind.te_pares()) cout << "$,$";
		else cout << it->second.pare->first << ',' << it->second.mare->first;

		cout << ')' << endl;
	}
}

void c_poblacio::escriure_arbre_genealogic(const string nom)
{
	queue<string> qu;
	qu.push(nom);

	r_arbre_genealogic(qu, 0);
}
