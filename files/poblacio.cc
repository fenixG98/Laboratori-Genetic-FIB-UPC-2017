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
	vind[nom].mare=vind.end();
	vind[nom].pare=vind.end();
}


bool poblacio::compatibles(const string a,const string b)
{
	
	if (vind.find(a)->second.ind.consultar_SEXE() == vind.find(b)->second.ind.consultar_SEXE()) return false;	
	if(not vind.find(a)->second.ind.te_mare() or not vind.find(a)->second.ind.te_pare() or not vind.find(b)->second.ind.te_mare() or not vind.find(a)->second.ind.te_pare()) return true;
	else
	{
		if (vind.find(a)->second.mare->first==vind.find(b)->second.mare->first) return false;
		if (vind.find(a)->second.pare->first==vind.find(b)->second.pare->first) return false;
	}
	return true;
}

void poblacio::afegir_pares(string a, string b, string c)
{
	vind.find(c)->second.mare = vind.find(a);
	vind.find(c)->second.pare = vind.find(b);
}

bool poblacio::existeix_individu(const string nom) const
{
	if (vind.count(nom)==0) return false;
	return true;
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
		vind[nom].ind =ind;
		vind[nom].mare=vind.end();
		vind[nom].pare=vind.end();
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


void poblacio::generar_arbre_genealogic(list<string> &l1, map<string,persona>::const_iterator it)
{	
	if(it!=vind.end())
	{
		l1.push_back(it->first);
		generar_arbre_genealogic(l1, it->second.pare);
		generar_arbre_genealogic(l1, it->second.mare);
	}
	else l1.push_back("$");
}

void poblacio::escriure_arbre_genealogic(const string nom) 
{
	list<string> l;
	generar_arbre_genealogic(l, vind.find(nom));
	for(list<string>::const_iterator it=l.begin(); it != l.end(); ++it)cout << *it << ' ';
	cout << endl;
}



