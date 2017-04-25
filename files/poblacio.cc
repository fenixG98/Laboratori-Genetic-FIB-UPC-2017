#include "poblacio.hh"
#include <algorithm>

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
}


bool poblacio::compatibles(const string a,const string b)
{
	return vind[a].ind.consultar_SEXE() != vind[b].ind.consultar_SEXE();
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
		vind[nom].ind=ind;
	}
}

void poblacio::escriure() const
{
	for(map<string,persona>::const_iterator it = vind.begin(); it != vind.end(); ++it)
	{
		cout << "  " << it->first;
		if (it->second.ind.consultar_SEXE()=="masculi") cout << " XY (";
		else cout << " XX (";
		if (not it->second.ind.te_pare()) cout << "$";
		else cout << it->second.pare;
		cout << ',';
		if (not it->second.ind.te_mare()) cout << "$";
		else cout << it->second.mare;
		cout << ')';
		cout << endl;
	}
}


void poblacio::escriure_arbre(const string nom) const
{

}




