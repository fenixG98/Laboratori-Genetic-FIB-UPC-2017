#include "poblacio.hh"
#include <algorithm>

//Constants
const char *ER1 = "  error";
const char *ER2 = "no es posible reproduccion";
const char *ER3 = "no es arbol parcial";

poblacio::poblacio(class especie espe) {
	nind = 0;
	this->esp = espe;
}


poblacio::~poblacio() {}



void poblacio::afegir_individu(const individu& ind)
{
	if (vind.count(ind.consultar_NOM())>0) cout << ER1 << endl;
	else
	{
	++nind;
	vind[ind.consultar_NOM()]=ind;
	}
}

void poblacio::reproduir(const string mare, const string pare, const string fill)
{

}

int poblacio::mida() const
{
	return nind;
}

int poblacio::mida_maxima() const
{
	return MAX_NIND;
}


void poblacio::llegir()
{

	cin >> nind;
	for (int a = 0; a < nind; ++a)
	{
		individu ind(esp);
		ind.llegir();
		vind[ind.consultar_NOM()]=ind;
	}
}

void poblacio::escriure() const
{
	for(map<string,individu>::const_iterator it = vind.begin(); it != vind.end(); ++it) it->second.escriure();
}

void poblacio::escriure_particular(string ind) const
{
	if (vind.count(ind)==0) cout << ER1 << endl;
	else vind.find(ind)->second.escriure_particular();
}




































