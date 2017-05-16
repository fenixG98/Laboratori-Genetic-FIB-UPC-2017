/** @file especie.hh
 @brief Especificación de la clase especie
 */

#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

/** @class especie
 @brief Representa una especie de individuo.

 Puede contener una descripcion de la especie. Puede usarse para crear una poblacion de esta especie.
 */
using namespace std;
class especie
{

private:

	int N;
	int lx;
	int ly;
	vector<int> l;

	vector<pair<pair<bool,bool>,int> > pt;


public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar una especie.
	 \pre <em>cierto</em>
	 \post El resultado es una especie sin descripcion
	 \coste Constante */
	especie();

	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Destruye la especie
	 \coste Constante*/
	~especie();

	//Consultores

	/** @brief Consulta el numero de pares de cromosomas no sexuales.
	 \pre <em>cierto</em>
	 \post El resultado es el numero de pares de cromosomas normales
	 \coste Constante  */
	int consultar_numero_parells() const;

	/** @brief Consulta la longitud del cromosoma sexual X.
	 \pre <em>cierto</em>
	 \post El resultado es la longitud del cromosoma X
	 \coste Constante  */
	int consultar_longitud_x() const;

	/** @brief Consulta la longitud del cromosoma sexual Y.
	 \pre <em>cierto</em>
	 \post El resultado es la longitud del cromosoma Y
	 \coste Constante  */
	int consultar_longitud_y() const;

	/** @brief Consulta la longitud de un cromosoma normal.
	 \pre <em>cierto</em>
	 \post El resultado es la longitud del cromosoma normal i
	 \coste Constante  */
	int consultar_longitud_i(int i) const;

	// Lectura i escriptura

	/** @brief Operación de lectura.
	 \pre <em>Estan preparados en el canal estandar de entrada un entero que representa el numero de pares de cromosomas normlaes, las longitudes de dichos pares y las longitudes de los cromosomas sexuales</em>
	 \post Lee la descripcion del parámetro implícito por el canal estándar de entrada
	 \coste */
	void llegir();

	void llegir_parametres_reproduccio();


};

#endif
