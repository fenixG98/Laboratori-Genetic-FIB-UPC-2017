/** @file arbre.hh
 @brief Especificación de la clase arbre
 */
#ifndef ARBRE_HH
#define ARBRE_HH

#ifndef NO_DIAGRAM
#include <cstddef>
#include <iostream>
#include <string>
#endif

/** @class arbre
 @brief Representa un arbol binario de un determiando tipo.

 Puede contener una informacion del tipo de arbol. Puede usarse para crear un arbol de tipo string.
 */
using namespace std;
class Arbre {

private:

	struct node_arbre {
		string info;
		node_arbre* segE;
		node_arbre* segD;
	};

	node_arbre* primer_node;

	// especificació operacions privades

	/** @brief Copia dos nodos.
	 \pre <em>cierto</em>
	 \post El resultado es NULL si m es NULL;
	 en caso contrario, el resultado apunta al nodo raiz
	 de una jerarquia de nodos que es una copia de la
	 jerarquia de nodos que tiene el nodo apuntado por m como raiz */
	node_arbre* copia_node_arbre(node_arbre* m)
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

	void esborra_node_arbre(node_arbre* m)
	/* Pre: cert */
	/* Post no fa res si m Ès NULL; en cas contrari,
	 allibera espai de tots els nodes de la
	 jerarquia que tÈ el node apuntat per m com a arrel */
	{
		if (m != NULL) {
			esborra_node_arbre(m->segE);
			esborra_node_arbre(m->segD);
			delete m;
		}
	}

public:

	// especificaciÛ operacions p˙bliques

	Arbre()
	/* Pre: cert */
	/* Post: el p.i. Ès un arbre buit */
	{
		primer_node= NULL;
	}

	Arbre(const Arbre& original)
	/* Pre: cert */
	/* Post: el p.i. Ès una cÚpia d'original */
	{
		if (this != &original)
			primer_node = copia_node_arbre(original.primer_node);
	}

	~Arbre() {
		esborra_node_arbre(primer_node);
	}

	Arbre& operator=(const Arbre& original) {
		if (this != &original) {
			esborra_node_arbre(primer_node);
			primer_node = copia_node_arbre(original.primer_node);
		}
		return *this;
	}

	void a_buit()
	/* Pre: cert */
	/* Post: el p.i. Ès un arbre buit */
	{
		esborra_node_arbre(primer_node);
		primer_node= NULL;
	}

	void swap(Arbre &a)
	/* Pre: a=A, p.i. = P */
	/* Post: el p.i. passa a ser A; a passa a ser P */
	{
		node_arbre* aux;
		aux = a.primer_node;
		a.primer_node = primer_node;
		primer_node = aux;
	}

	void plantar(const string &x, Arbre &a1, Arbre &a2)
	/* Pre: el p.i. Ès buit, a1=A1, a2=A2 */
	/* Post: el p.i. tÈ x com a arrel, A1 com a fill esquerre i A2 com a
	 fill dret; a1 i a2 sÛn buits; si A1 i A2 sÛn el mateix objecte, el
	 fill dret n'Ès una cÚpia */
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
				throw PRO2Excepcio ("El p.i. de plantar ha de ser buit a la crida");
		}
		else
			throw PRO2Excepcio ("El p.i. de plantar no pot coincidir amb els par‡metres");
	}


	void fills (Arbre &fe, Arbre &fd)
	/* Pre: el p.i. no Ès buit i li diem A, fe i fd sÛn buits */
	/* Post: fe Ès el fill esquerre d'A, fd Ès el fill dret d'A,
	 el p.i. Ès buit */
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
				throw PRO2Excepcio
				("Els dos par‡metres de fills no poden coincidir");
		}
		else if (primer_node==NULL)
			throw PRO2Excepcio ("Un arbre buit no tÈ fills");
		else
			throw PRO2Excepcio
			("Els dos par‡metres de fills han de ser buits a la crida");
	}

	T arrel() const
	/* Pre: el p.i. no Ès buit */
	/* Post: el resultat Ès l'arrel del p.i. */
	{
		if (primer_node!=NULL)
			return primer_node->info;
		else
			throw PRO2Excepcio ("Un arbre buit no tÈ arrel");
	}

	bool es_buit() const
	/* Pre: cert */
	/* Post: el resultat indica si el p.i. Ès un arbre buit */
	{
		return (primer_node==NULL);
	}

};

#endif
