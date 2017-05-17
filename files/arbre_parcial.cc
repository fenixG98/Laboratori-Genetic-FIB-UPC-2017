#include "arbre_parcial.hh"


arbre_parcial::arbre_parcial()
{
}

arbre_parcial::arbre_parcial(Arbre<string> &copia)
{
	Arbre<string> APcopiat(copia);
	ap = APcopiat;
}

arbre_parcial::~arbre_parcial() {}


void arbre_parcial::llegir()
{
	llegir_arbre_string(ap);
}

void arbre_parcial::escriure()
{
	escriure_arbre_string(ap);
}

void arbre_parcial::escriure_arbre_string(Arbre<string>& a) {
	if (not a.es_buit()) {
		string x = a.arrel();
		cout << ' '<< x;
		Arbre<string> a1;
		Arbre<string> a2;
		a.fills(a1,a2);
		escriure_arbre_string(a1);
		escriure_arbre_string(a2);
	}
	else cout << ' ' << "$";
}

void arbre_parcial::llegir_arbre_string(Arbre<string>& a){
	Arbre<string> a1;
	Arbre<string> a2;
	string x;
	cin >> x;
	if (x!= "$") {
		llegir_arbre_string(a1);
		llegir_arbre_string(a2);
		a.plantar(x,a1,a2);
	}
}

string arbre_parcial::arrel()
{
	return ap.arrel();
}

