/** @file arbre.hh
 @brief Especificación de la clase arbre
 */
#ifndef ARBRE_HH
#define ARBRE_HH

#ifndef NO_DIAGRAM
#include <cstddef>
#include <iostream>
#include <string>
#include <list>
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
	node_arbre* copia_node_arbre(node_arbre* m);


	void esborra_node_arbre(node_arbre* m);
	/* Pre: cert */
	/* Post no fa res si m Ès NULL; en cas contrari,
	 allibera espai de tots els nodes de la
	 jerarquia que tÈ el node apuntat per m com a arrel */

public:

	// Constructores
	Arbre();
	/* Pre: cert */
	/* Post: El resultat és un arbre sense cap element */

	Arbre(const Arbre& original);
	/* Pre: cert */
	/* Post: El resultat és una còpia d'original */
	// Destructora: Esborra automàticament els objectes locals en sortir
	// d'un àmbit de visibilitat

	~Arbre();

	// Modificadores
	Arbre& operator=(const Arbre& original);


	void a_buit();
	/* Pre: cert */
	/* Post: El paràmetre implícit no té cap element */

	void swap(Arbre& a);
	/* Pre: a=A, p.i. = P */
	/* Post: el p.i. passa a ser A; a passa a ser P */

	void plantar(const string& x, Arbre& a1, Arbre& a2);
	/* Pre: El paràmetre implícit és buit, a1 = A1, a2 = A2, el p.i. no és el mateix
	 objecte que a2 ni que a2 */
	/* Post: El paràmetre implícit té x com a arrel, A1 com a fill esquerre i A2 com
	 a fill dret; a1 i a2 són buits; si A1 i A2 són el mateix objecte, el fill dret
	 n'és una còpia */

	void fills(Arbre& fe, Arbre& fd);
	/* Pre: El paràmetre implícit no està buit i li diem A; fe i fd són buits i no
	 són el mateix objecte */
	/* Post: fe és el fill esquerre d'A; fd és el fill dret d'A; el paràmetre
	 implícit és buit */

	// Consultores

	list<string> preordre(Arbre &a);


	string arrel() const;
	/* Pre: El paràmetre implícit no és buit */
	/* Post: El resultat és l'arrel del paràmetre implícit */

	bool es_buit() const;
	/* Pre: cert */
	/* Post: El resultat indica si el paràmetre implícit és buit o no */

	void llegir_arbre_int(Arbre& a, string marca);
	// Lectura d'un arbre binari d'enters, accio.  Els elements
	// s'introdueixen en preordre: primer l'arrel, despres el subarbre
	// esquerre i per ultim el dret. Els arbres buits es
	// representen amb la marca.

	/* Exemple: l'arbre

	   1
	 /   \
	2     3
	 \
	 4

	 es llegeix 1 2 0 4 0 0 3 0 0 (o amb els numeros en distintes linie$
	 */



};
#endif
