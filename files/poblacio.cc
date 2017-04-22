#include "poblacio.hh"
#include <algorithm>

const char *ER1 = "  error";
const char *ER2 = "  no es posible reproduccion";
const char *ER3 = "  no es arbol parcial";

poblacio::poblacio(const especie &espe) {
	nind = 0;
	this->esp = espe;
}

poblacio::~poblacio() {}

void poblacio::afegir_individu(const string nom, const individu& ind)
{
	++nind;
	vind[nom]=ind;
}

void poblacio::reproduir(const string mare, const string pare, const string fill)
{

}
bool poblacio::existeix_individu(string nom) const
{
	if (vind.count(nom)==0) return false;
	return true;
}

individu poblacio::individu_nom(string nom) const
{
	return vind.find(nom)->second;
}

void poblacio::llegir()
{

	cin >> nind;
	for (int a = 0; a < nind; ++a)
	{
		string nom;
		individu ind(esp);
		cin >> nom;
		ind.llegir();
		vind[nom]=ind;
	}
}

void poblacio::escriure() const
{
	for(map<string,individu>::const_iterator it = vind.begin(); it != vind.end(); ++it)
	{
		cout << "  " << it->first;
		if (it->second.consultar_SEXE()=="masculi") cout << " XY (";
		else cout << " XX (";
		if (not it->second.te_pare()) cout << "$";
		//else cout << it->second.consultar_PARE()->first;
		cout << ',';
		if (not it->second.te_mare()) cout << "$";
		//else cout << it->second.consultar_MARE().consultar_SEXE();
		cout << ')';
		cout << endl;
	}
}
