#include "arbre_parcial.hh"


ArbreP::ArbreP()
{

}

ArbreP::~ArbreP()
{

}

void ArbreP::llegir()
{
	ap.a_buit();
	leer_arbol_strings(ap);
}

void ArbreP::leer_arbol_strings(Arbre<string> &a)
{
	Arbre<string> a1, a2;
	string c;
	cin >> c;
	if (c!="$") {
		leer_arbol_strings(a1);
		leer_arbol_strings(a2);
		a.plantar(c, a1, a2);
	}
}

void ArbreP::escriure()
{
		Arbre<string> copia(ap);
		list<string> l = preordre(copia);
	for (list<string>::iterator it = l.begin(); it != l.end(); ++it) cout << *it << ' ';
}


void ArbreP::escribir_arbol_strings_id(Arbre<string> &a)
{
	if (not a.es_buit()) {
		Arbre<string> a1, a2;
		string aux = a.arrel();
		a.fills(a1,a2);
		escribir_arbol_strings_id(a1);
		cout << " ";
		cout << aux;
		escribir_arbol_strings_id(a2);
	}
}

list<string> ArbreP::preordre(Arbre<string> &a)
{
	list<string> l;

	if (not a.es_buit()) {
		string node=a.arrel();
		Arbre<string> a1;
		Arbre<string> a2;
		a.fills(a1,a2);
		l=preordre(a1);
		list<string> m;
		m=preordre(a2);
		l.insert(l.begin(),node);
		l.splice(l.end(),m);
	}
	return l;
}

