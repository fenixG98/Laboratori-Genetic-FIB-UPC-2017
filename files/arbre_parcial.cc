#include "arbre_parcial.hh"

// Constructoras y destructoras

arbre_parcial::arbre_parcial() {}

arbre_parcial::arbre_parcial(const Arbre<string> &original)
{
	this->ap = original;
}

arbre_parcial::~arbre_parcial() {}

// Privadas

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

bool arbre_parcial::r_es_parcial ( Arbre<string> &a,  Arbre<string> &b, Arbre<string> &res)
{
	string x;
	bool bo = true;

	if (a.es_buit() and b.es_buit()) bo = true; // $ $

	else if (not a.es_buit() and not b.es_buit() and a.arrel()==b.arrel()) // arrel1 == arrel1
	{
		x = b.arrel();

		Arbre<string> a1;
		Arbre<string> a2;
		a.fills(a1,a2);

		Arbre<string> b1;
		Arbre<string> b2;
		b.fills(b1,b2);

		Arbre<string> res1;
		Arbre<string> res2;

		bo = r_es_parcial(a1,b1,res1);
		if (bo) bo = r_es_parcial(a2,b2,res2);

		res.plantar(x,res1,res2);
	}

	else if (a.es_buit() and not b.es_buit()) // $ arrel1
	{
		x = "*"+b.arrel()+"*";

		Arbre<string> aux;

		fills_mod(aux,b);

		res = aux;
		bo = true;
	}
	else bo = false;
	return bo;
}

void arbre_parcial::fills_mod(Arbre<string> &a, Arbre<string> &b)
{
	Arbre<string> a1;
	Arbre<string> a2;
	if (not b.es_buit()) {
		string x = "*"+b.arrel()+"*";
		Arbre<string> b1;
		Arbre<string> b2;
		b.fills(b1,b2);
		fills_mod(a1,b1);
		fills_mod(a2,b2);
		a.plantar(x,a1,a2);
	}
}

// Publicas

string arbre_parcial::consultar_NOM() const
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

void arbre_parcial::llegir()
{
	llegir_arbre_string(ap);
}

void arbre_parcial::escriure()
{
	cout << ' ';
	escriure_arbre_string(ap);
	cout << endl;
}



