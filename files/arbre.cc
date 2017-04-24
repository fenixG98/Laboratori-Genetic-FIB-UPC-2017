#include "arbre.hh"

Arbre::node_arbre* Arbre::copia_node_arbre(node_arbre* m)
{
	node_arbre* n;
	if (m==NULL) n=NULL;
	else {
		n = new node_arbre;
		n->info = m->info;
		n->segE = copia_node_arbre(m->segE);
		n->segD = copia_node_arbre(m->segD);
	}
	return n;
}

Arbre::Arbre()
{
	primer_node= NULL;
}

Arbre::Arbre(const Arbre& original)
{
	if (this != &original) primer_node = copia_node_arbre(original.primer_node);
}

Arbre::~Arbre() {
	esborra_node_arbre(primer_node);
}

list<string> Arbre::preordre(Arbre &a)
{
	list<string> l;
	if (not a.es_buit()) {
		string node=a.arrel();
		Arbre a1;
		Arbre a2;
		a.fills(a1,a2);
		l=preordre(a1);
		list<string> m;
		m=preordre(a2);
		l.insert(l.begin(),node);
		l.splice(l.end(),m);
	}
	return l;
}

void Arbre::esborra_node_arbre(node_arbre* m)

{
	if (m != NULL) {
		esborra_node_arbre(m->segE);
		esborra_node_arbre(m->segD);
		delete m;
	}
}

void Arbre::a_buit()
{
	esborra_node_arbre(primer_node);
	primer_node= NULL;
}

Arbre& Arbre::operator=(const Arbre& original) {
	if (this != &original) {
		esborra_node_arbre(primer_node);
		primer_node = copia_node_arbre(original.primer_node);
	}
	return *this;
}

void Arbre::swap(Arbre &a)
{
	node_arbre* aux;
	aux = a.primer_node;
	a.primer_node = primer_node;
	primer_node = aux;
}

void Arbre::plantar(const string &x, Arbre &a1, Arbre &a2)

{
	if (this != &a1 and this != &a2) {
		if (primer_node==NULL) {
			node_arbre* aux;
			aux= new node_arbre;
			aux->info= x;
			aux->segE= a1.primer_node;
			if (a1.primer_node == a2.primer_node) aux->segD= copia_node_arbre(a1.primer_node);
			else  aux->segD= a2.primer_node;
			primer_node= aux;
			a1.primer_node= NULL;
			a2.primer_node= NULL;
		}
		else
			cout << "El p.i. de plantar ha de ser buit a la crida" << endl;;
	}
	else
		cout << "El p.i. de plantar no pot coincidir amb els par‡metres" << endl;
}

void Arbre::fills (Arbre &fe, Arbre &fd)
{
	if (primer_node!=NULL and fe.primer_node==NULL
		and fd.primer_node==NULL) {
		if (&fe != &fd) {
			node_arbre* aux;
			aux= primer_node;
			fe.primer_node= aux->segE;
			fd.primer_node= aux->segD;
			primer_node= NULL;
			delete aux;
		}
		else
			cout << "Els dos par‡metres de fills no poden coincidir" << endl;
	}
	else if (primer_node==NULL)
		cout <<"Un arbre buit no tÈ fills"<<endl;
	else
		cout <<"Els dos par‡metres de fills han de ser buits a la crida"<<endl;
}

string Arbre::arrel() const
{
	return primer_node->info;
}

bool Arbre::es_buit() const

{
	return (primer_node==NULL);
}

void Arbre::llegir_arbre_int(Arbre& a, string marca)
{
	Arbre a1;
	Arbre a2;
	string x;
	cin >> x;
	if (x!= marca) {
		llegir_arbre_int(a1, marca);
		llegir_arbre_int(a2, marca);
		a.plantar(x,a1,a2);
	}
}















