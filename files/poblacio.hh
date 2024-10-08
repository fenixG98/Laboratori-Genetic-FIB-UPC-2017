/** @file poblacio.hh
 @brief Especificacion de la clase c_poblacio
 */

#ifndef POBLACIO_HH
#define POBLACIO_HH

#include "individu.hh"
#include "arbre_parcial.hh"
#include "especie.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <queue>
#include "Arbre.hh"
#include <iostream>
#endif

/** @class c_poblacio
 @brief Representa una poblacion de personas de una misma especie.

 Solo puede contener personas de una misma especie. Puede usarse para realizar
 experimentos con mas de una perona o bien consultar la informacion de la
 poblacion.
 */

class c_poblacio
{

private:

	/** @brief Structura de persona, formado por sus padres y el propio individuo.*/
	struct persona
	{
		c_individu ind;
		map<string,persona>::const_iterator mare;
		map<string,persona>::const_iterator pare;
	};

	/** @brief Conjunto de personas.*/
	map<string,persona> vind;

public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automaticamente al declarar una poblacion.
	 \pre <em>cierto.</em>
	 \post El resultado es una poblacion de una determinada especie pero vacia.*/
	c_poblacio();

	/** @brief Destructora por defecto.
	 \pre <em>cierto.</em>
	 \post Se destruye la poblacion.*/
	~c_poblacio();

	//Modificadores

	/** @brief Añade un individuo a la poblacion.
	 \pre <em>No existe un individuo con el nombre de nom.</em>
	 \post El parametro implicito pasa a contener el individuo sin padres.*/
	void afegir_individu(const string nom, const c_individu& ind);

	/** @brief Añade padres a un individuo de la poblacion.
	 \pre <em>El individuo c no tiene padres.</em>
	 \post El individuo c pasa a tener como madre y padre, a y b respectivamente. */
	void afegir_pares(const string a, const string b, const string c);

	//Consultores

	/** @brief Consulta si los dos parametros son compatibles para la
	reproduccion.
	 \pre <em>cierto.</em>
	 \post El resultado es true si son compatibles para la reproduccion. */
	bool compatibles(const string a,const string b);

	/** @brief Consulta el individuo con nombre nom.
	 \pre <em>El individuo nom existe en la poblacion</em>
	 \post El resultado es el individuo de nombre nom */
	c_individu individu_nom(const string nom) const;

	/** @brief Consulta el individuo con nombre nom.
	 \pre <em>cierto.</em>
	 \post El resultado es true si el individuo existe en la poblacion */
	bool existeix_individu(const string nom) const;

	/** @brief Genera el arbol genealogico de un individuo
	 \pre <em>El individuo de nombre nom existe en la poblacion.</em>
	 \post Devuelve el arbol genealogico de nom.  */
	arbre_parcial arbre_genealogic(const string nom);

	// Lectura i escriptura

	/** @brief Operacion de lectura.
	 \pre <em>Estan preparados en el canal estandar de entrada un entero que
	 representa el numero de individuos que se van a leer y dichos individuos</em>
	 \post Lee un conjunto de individuos por el canal estandar de entrada */
	void llegir(const c_especie &esp);

	/** @brief Operacion de escritura.
	 \pre <em>cierto.</em>
	 \post Escribe el nombre, el sexo y los padres (si tiene) de cada persona
	 de la poblacion por el canal estándar de salida */
	void escriure() const;

	/** @brief Operacion de escritura del arbol genealogico.
	 \pre <em>cierto</em>
	 \post Escribe el arbol genealogico de sus ascendientes.*/
	void escriure_arbre_genealogic(const string nom);

private:

	/** @brief Recorre la poblacion y rellena de forma recursiva un arbol.
	 \pre <em>a es vacio y el iterador apunta al primer individuo del arbol.</em>
	 \post a es el arbol genealogico del primer individuo.*/
	void r_generar_arbre_genealogic(Arbre<string> &a, map<string,persona>::const_iterator it);

	/** @brief Recorre la poblacion y escribe el arbol genealogico de un
	individuo por niveles.
	 \pre <em>q es vacío y cont es igual a 0.</em>
	 \post Se ha escrito el arbol genealogico por niveles de un individuo.*/
	void r_arbre_genealogic(queue<string> &q, int cont);

	/** @brief Recorre la poblacion y comprueba que marca este en los
	ascendientes de x.
	 \pre <em> x y marca existen en la poblacion.</em>
	 \post true si marca esta en los ascendientes de x, de lo contrario false. */
	bool r_comprobar_ascendent(string x, string marca);



};

#endif
