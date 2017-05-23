/** @file poblacio.hh
 @brief Especificación de la clase poblacio
 */

#ifndef CONJ_IND_HH
#define CONJ_IND_HH

#include "individu.hh"
#include "arbre_parcial.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <queue>
#include "Arbre.hh"
#endif

/** @class poblacio
 @brief Representa una poblacion de individuos de una misma especie.

 Solo puede contener individuos de una misma especie. Puede usarse para realizar experimentos con mas de un individuo.
 */

class poblacio
{

private:

	/** @brief Numero de individuos de la poblacion */
	int nind;

	/** @brief Structura de persona, formado por sus padres y el propio individuo */
	struct persona
	{
		individu ind;
		map<string,persona>::const_iterator mare;
		map<string,persona>::const_iterator pare;
	};

	/** @brief Conjunto de personas */
	map<string,persona> vind;

public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar una poblacion.
	 \pre <em>cierto</em>
	 \post El resultado es una poblacion de una determinada especie pero sin individuos. */
	poblacio();

	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Se destruye la especie*/
	~poblacio();

	//Modificadores

	/** @brief Añade un individuo a la poblacion
	 \pre <em>No existe un individuo con el nombre de nom y el numero de individuos del p.i. es mas pequeño que el tamaño permitido ind</em>
	 \post El parámetro implícito pasa a contener el individuo */
	void afegir_individu(const string nom, const individu& ind);


	/** @brief Añade padres a un individuo de la poblacion
	 \pre <em>El individuo c no tiene padres asignados</em>
	 \post El individuo c tiene como madre y padre, a y b respectivamente */
	void afegir_pares(const string a, const string b, const string c);

	//Consultores

	/** @brief Consulta si los dos parametros son compatibles para la reproducción.
	 \pre <em>cierto</em>
	 \post El resultado es true si son de distitno genero. */
	bool compatibles(const string a,const string b);

	/** @brief Consulta el individuo con nombre nom.
	 \pre <em>El individuo nom existe en la poblacion</em>
	 \post El resultado es el individuo de nombre nom */
	individu individu_nom(const string nom) const;

	/** @brief Consulta el individuo con nombre nom.
	 \pre <em>cierto</em>
	 \post El resultado es true si el individuo existe en la poblacion */
	bool existeix_individu(const string nom) const;


	/** @brief Genera el arbol genealogico de un individuo
	 \pre <em>NEl individuo de nombre nom existe en la poblacion</em>
	 \post Devuelve un arbol genealogico  */
	arbre_parcial arbre_genealogic(const string nom);

	// Lectura i escriptura
	
	/** @brief Operación de lectura.
	 \pre <em>Estan preparados en el canal estandar de entrada un entero que representa el numero de individuos que se van a leer y dichos individuos</em>
	 \post Lee un conjunto de individuos por el canal estándar de entrada */
	void llegir(const especie &esp);


	/** @brief Operación de escritura.
	 \pre <em>cierto</em>
	 \post Escribe el nombre, los cromosomas sexuales y los padres (si tiene) del parámetro implícito por el canal estándar de salida */
	void escriure() const;


	/** @brief Operación de escritur del arbre genealogic.
	 \pre <em>cierto</em>
	 \post Escribe el arbol genealogico de sus ascendientes.*/
	void escriure_arbre_genealogic(const string nom);

private:
	
	/** @brief Recorre la poblacion y rellena de forma recursiva un arbol
	 \pre <em>a es vacío y el iterador apunta al primer elemento del arbol</em>
	 \post a es el arbol genealogico de un individuo */
	void r_generar_arbre_genealogic(Arbre<string> &a, map<string,persona>::const_iterator it);

	/** @brief Recorre la poblacion y escribe el arbol genealogico de un individuo de forma recursiva
	 \pre <em>q es vacío y cont es igual a 0 </em>
	 \post Se ha escrito el arbol genealogico por niveles de un individuo */
	void r_arbre_genealogic(queue<string> &q, int cont);

	/** @brief Recorre la poblacion y comprueba que marca este en los ascendientes de x
	 \pre <em> x y marca existen en la poblacion</em>
	 \post true si marca esta en los ascendientes de x, de lo contrario false */
	bool r_comprobar_ascendent(string x, string marca);



};

#endif
