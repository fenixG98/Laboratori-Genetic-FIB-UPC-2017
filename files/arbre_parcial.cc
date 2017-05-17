#include "arbre_parcial.hh"


arbre_parcial::arbre_parcial() {}

arbre_parcial::arbre_parcial(const Arbre<string> &original)
{
	Arbre<string> aux(original);
	this->ap = aux;
}

arbre_parcial::~arbre_parcial() {}


void arbre_parcial::llegir()
{
	llegir_arbre_string(ap);
}

void arbre_parcial::escriure()
{
	escriure_arbre_string(ap);
	cout << endl;
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

bool arbre_parcial::es_parcial(const arbre_parcial &ag)
{
	Arbre<string> arP(this->ap);
	Arbre<string> arG(ag.ap);
	Arbre<string> res;

	bool x = r_es_parcial (arP,arG, res);
	this->ap = res;
	return x;
}

bool arbre_parcial::r_es_parcial (const Arbre<string> &a, const Arbre<string> &b, Arbre<string> &res)
{	
	res = b;
	return not a.es_buit() or not b.es_buit() or not res.es_buit();
}


