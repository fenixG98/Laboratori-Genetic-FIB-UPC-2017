#include "poblacio.hh"

const char *ER1 = "  error";
const char *ER2 = "  no es posible reproduccion";
const char *ER3 = "  no es arbol parcial";

poblacio::poblacio() {
	nind = 0;
}

poblacio::~poblacio() {}

void poblacio::afegir_individu(const string nom, const individu& ind)
{
	++nind;
	vind[nom].ind=ind;
	vind[nom].pare=vind.end();
	vind[nom].mare=vind.end();
}


bool poblacio::compatibles(const string a,const string b)
{
	if(vind.find(a)->second.ind.consultar_SEXE() or not vind.find(b)->second.ind.consultar_SEXE() )
	if (vind.find(a)->second.ind.consultar_SEXE() == vind.find(b)->second.ind.consultar_SEXE()) return false;
		bool x, y;
		x = comprobar_ascendent(a,b);
		y = comprobar_ascendent(b,a);
		return not (x or y);

}

bool poblacio::comprobar_ascendent(string x, string marca)
{
	bool b;
	if (x==marca) return true;
	if (vind.find(x)->second.mare == vind.end()) return false;
		string a1 = vind.find(x)->second.mare->first;
		string a2 = vind.find(x)->second.pare->first;
		b=comprobar_ascendent(a1,marca);
		if (not b) b=comprobar_ascendent(a2,marca);

	return b;
}

void poblacio::afegir_pares(string a, string b, string c)
{
	vind.find(c)->second.mare = vind.find(a);
	vind.find(c)->second.pare = vind.find(b);
}

bool poblacio::existeix_individu(const string nom) const
{
	return vind.find(nom) != vind.end();
}

individu poblacio::individu_nom(const string nom) const
{
	return vind.find(nom)->second.ind;
}

void poblacio::llegir(const especie &esp)
{

	cin >> nind;
	for (int a = 0; a < nind; ++a)
	{
		string nom;
		individu ind;
		cin >> nom;
		ind.llegir(esp);
		vind[nom].ind=ind;
		vind[nom].pare=vind.end();
		vind[nom].mare=vind.end();
	}
}

void poblacio::escriure() const
{
	for(map<string,persona>::const_iterator it = vind.begin(); it != vind.end(); ++it)
	{
		cout << "  " << it->first;
		if (it->second.ind.consultar_SEXE()) cout << " XY (";
		else cout << " XX (";
		if (not it->second.ind.te_pare()) cout << "$";
		else cout << it->second.pare->first;
		cout << ',';
		if (not it->second.ind.te_mare()) cout << "$";
		else cout << it->second.mare->first;
		cout << ')';
		cout << endl;
	}
}


void poblacio::r_arbre_genealogic(queue<string> &q, int cont)
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

void poblacio::escriure_arbre_genealogic(const string nom) 
{
	queue<string> qu;
	qu.push(nom);
	r_arbre_genealogic(qu, 0);
}




