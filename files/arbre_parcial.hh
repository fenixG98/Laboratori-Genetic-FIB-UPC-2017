/** @file arbre_parcial.hh
 @brief Especificacion de la clase arbre_parcial
 */

#ifndef ARBRE_PARCIAL_HH
#define ARBRE_PARCIAL_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include "Arbre.hh"
#endif

/** @class arbre_parcial
 @brief Representa un arbol genealogico.

 Puede contener un arbol parcial o completo de una persona.
 */
using namespace std;
class arbre_parcial
{

private:

	/** @brief Arbol genealogico.*/
	Arbre<string> ap;

public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automaticamente al declarar un arbol.
	 \pre <em>cierto.</em>
	 \post El resultado es un arbol vacio. */
	arbre_parcial();

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar un arbol.
	 \pre <em>cierto.</em>
	 \post El resultado es un arbol_parcial copia de el arbol copia. */
	arbre_parcial(const Arbre<string> &copia);


	/** @brief Destructora por defecto.
	 \pre <em>cierto.</em>
	 \post Se destruye el arbol.*/
	~arbre_parcial();

	/** @brief Consulta el nombre de la raiz.
	 \pre <em>p.i. no es vacio.</em>
	 \post El resultado es el nombre de la raiz del arbol.*/
	string consultar_NOM() const;

	/** @brief Verifica si el p.i. es un arbol parcial de ag y si lo es modifica el p.i. añadiendo los nodos necesarios.
	 \pre <em>ag no es vacio, p.i. no es vacio.</em>
	 \post p.i. pasa a contener un arbol completo modificado si p.i. es parcial de ag.*/
	bool es_parcial(const arbre_parcial &ag);


	/** @brief Lee un arbol binario.
	 \pre <em>p.i. es vacio, esta preparado en el canal estandar de entrada un arbol en preorden.</em>
	 \post p.i. pasa a contener el arbol binario leido.*/
	void llegir();

	/** @brief Escribe un arbol binario.
	 \pre <em>p.i. no es vacio.</em>
	 \post Se escribe por el canal estandar de salida un arbol binario en preorden.*/
	void escriure();

private:
	/** @brief Lee de forma recursiva un arbol binario
	 \pre <em>a es vacio, esta preparado en el canal estandar de entrada un arbol en preorden</em>
	 \post a pasa a contener un arbol binario */
	void llegir_arbre_string(Arbre<string>& a);

	/** @brief Escribe de forma recursiva un arbol binario
	 \pre <em>a no es vacio</em>
	 \post Se escribe por el canal estandar de salida un arbol binario en preorden*/
	void escriure_arbre_string(Arbre<string>& a);

	/** @brief Verifica si b es un arbol parcial de a y si lo es escribe el completo en res
	 \pre <em>a y b no es vacio, res es vacio</em>
	 \post res pasa a contener un arbol completo modificado si b es parcial de a*/
	bool r_es_parcial ( Arbre<string> &a,  Arbre<string> &b, Arbre<string> &res);

	/** @brief Copia el arbol b en a con las raices modificadas
	 \pre <em>b no es vacio, a es vacio</em>
	 \post a es una copia de b con las raices modificadas*/
	void fills_mod(Arbre<string> &a, Arbre<string> &b);

};

#endif
