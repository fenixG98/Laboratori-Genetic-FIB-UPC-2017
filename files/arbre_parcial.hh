/** @file arbre_parcial.hh
 @brief Especificación de la clase especie
 */

#ifndef arbre_parcial_h
#define arbre_parcial_h

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <list>
#include "Arbre.hh"
#endif

/** @class ArbreP
 @brief Representa una arbre parcial.

 Contiene un arbol parcial.
 */

using namespace std;

class ArbreP
{

private:
	Arbre<string> ap;


public:

	/** @brief Creadora por defecto.
	Se ejecuta automáticamente al declarar una especie.
	\pre <em>cierto</em>
	\post El resultado es una arbol parcual
	\coste Constante */
	ArbreP();

	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Destruye el arbol
	 \coste Constante*/
	~ArbreP();

	// Operadoras
	/** @brief Completa un arbol parcial.
	 \pre <em>cierto</em>
	 \post Es true siEscribe el arbol si este es parcial de otro
	 \coste */

	// Lectura y escritura

	/** @brief Operación de lectura.
	 \pre <em>Esta preparado en el canal estandar de entrada un arbol</em>
	 \post Lee en preorden un arbol
	 \coste */
	void llegir();

	/** @brief Operación de escritura.
	 \pre <em>cierto</em>
	 \post Escribe el arbol en inorden
	 \coste */
	void escriure();

private:
	static list<string> preordre( Arbre<string> &a);

	static bool completar_arbre_parcial(const Arbre<string> &ap, const Arbre<string> &ag);

	/** @brief Operación de lectura de un árbol de strings
	 \pre  N > 0; a es vacío
	 \post a contiene el árbol de strings leído de la entrada
  */
	static void leer_arbol_strings(Arbre<string> &a);

	/** @brief Operación de escritura de un árbol de strings
	 \pre  cierto
	 \post Se ha escrito a por el canal de salida estándard
  */
	static void escribir_arbol_strings_id(Arbre<string> &a);
};


#endif /* arbre_parcial_h */
