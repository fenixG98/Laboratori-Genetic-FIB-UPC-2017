/**
 * @mainpage Ejemplo de diseño modular: Practica PRO2: Experimentos genéticos en laboratorio.

 Se ha construido un programa modular que ofrece un menú de opciones para realizar un experiemento genetico. Se introducen las clases <em>especie</em>, <em>poblacio</em> y <em>individu</em>.
*/

/** @file main.cc
 @brief Programa principal para la practica <em>Experimentos genéticos en laboratorio</em>.
 */

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "especie.hh"
#include "poblacio.hh"
#include "individu.hh"


#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include <iostream>
#include <string>
//#include "arbre.hh>
#endif

/** @brief Programa principal para la practica <em>Experimentos genéticos en laboratorio</em>.
 */

using namespace std;

int main()
{
	cout << " PROGRAM RUNNING " << endl;

	especie esp;
	esp.llegir();
	
	poblacio POBL(esp);
	POBL.llegir();

	string comando;

	while (cin >> comando)
	{
		if (comando == "anadir_individuo")
		{

			individu ind(esp);
			ind.llegir();
			cout << "añadir_individuo " << ind.consultar_NOM() << endl;
			POBL.afegir_individu(ind);
		}

		else if(comando == "escribir_poblacion")
		{
			cout << "escribir_poblacion" << endl;
			POBL.escriure();
		}
		else if(comando == "reproduccion_sexual")
		{
			cout << "operacion nula" << endl;
		}

		else if(comando == "escribir_arbol_genealogico")
		{
			cout << "operacion nula" << endl;
		}

		else if(comando == "completar_arbol_genealogico")
		{
			cout << "operacion nula" << endl;
		}

		else if(comando == "escribir_genotipo")
		{
			string ind;
			cin >> ind;
			POBL.escriure_particular(ind);
		}

		else if(comando == "acabar")
		{
			return 0;
		}

	}
}


