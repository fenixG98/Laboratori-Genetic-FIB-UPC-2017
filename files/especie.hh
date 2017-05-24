/** @file especie.hh
 @brief Especificacion de la clase c_especie
 */

#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

/** @class c_especie.
 @brief Representa una especie de individuo.

 Puede contener una descripcion de la especie. Puede usarse para crear una poblacion de esta especie.
 */
using namespace std;
class c_especie
{

private:

	/**@brief Numero de pares de cromosomas normales */
	int N;

	/**@brief Longitud del cromosoma X  */
	int lx;

	/**@brief Longitud del cromosoma Y */
	int ly;

	/**@brief  Longitud del cruce y de los cromosomas normales */
	vector<int> l;

public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automaticamente al declarar una especie.
	 \pre <em>cierto</em>
	 \post El resultado es una especie sin descripcion */
	c_especie();

	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Destruye la especie*/
	~c_especie();

	//Consultores

	/** @brief Consulta el numero de pares de cromosomas no sexuales.
	 \pre <em>cierto</em>
	 \post El resultado es el numero de pares de cromosomas normales*/
	int consultar_numero_parells() const;

	/** @brief Consulta la longitud del cromosoma sexual X.
	 \pre <em>cierto</em>
	 \post El resultado es la longitud del cromosoma X */
	int consultar_longitud_x() const;

	/** @brief Consulta la longitud del cromosoma sexual Y.
	 \pre <em>cierto</em>
	 \post El resultado es la longitud del cromosoma Y */
	int consultar_longitud_y() const;

	/** @brief Consulta la longitud del cruce.
	 \pre <em>cierto</em>
	 \post El resultado es la longitud del cruce Y*/
	int consultar_longitud_repro() const;

	/** @brief Consulta la longitud de un cromosoma normal en funcion de su posicion en el genotipo.
	 \pre <em>cierto</em>
	 \post El resultado es la longitud del cromosoma normal i*/
	int consultar_longitud_i(int i) const;

	// Lectura i escriptura

	/** @brief Operación de lectura.
	 \pre <em>Estan preparados en el canal estandar de entrada un entero que representa el numero de pares de cromosomas normlaes, las longitudes de dichos pares y las longitudes de los cromosomas sexuales</em>
	 \post Lee la descripcion del parámetro implícito por el canal estándar de entrada */
	void llegir();

};

#endif
