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
#include "arbre.hh"


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
	// especie creada
	poblacio POBL(esp);
	POBL.llegir();
	//poblacio llegida

	string comando;

	while (cin >> comando)
	{
		if (comando == "anadir_individuo")
		{
			individu ind(esp);
			string nom;
			cin >> nom;
			ind.llegir();
			cout << "añadir_individuo " << nom << endl;

			if (not POBL.existeix_individu(nom)) POBL.afegir_individu(nom, ind);
			else cout << "  error" << endl;
		}

		else if(comando == "escribir_poblacion")
		{
			cout << "escribir_poblacion" << endl;
			POBL.escriure();
		}

		else if(comando == "escribir_genotipo")
		{
			string nom;
			cin >> nom;
			cout << "escribir_genotipo " << nom << endl;
			
			if (POBL.existeix_individu(nom))
			{
				individu ind = POBL.individu_nom(nom);
				ind.escriure();
			}
			else cout << "  error" << endl;

		}

		else if(comando == "reproduccion_sexual")
		{
			string a, b, c;
			cin >> a >> b >> c;
			cout << "reproduccion_sexual" << a << ' ' << b << ' '<< c << endl;
			POBL.reproduir(a, b, c);
		}

		else if(comando == "escribir_arbol_genealogico")
		{
			string nom;
			cin >> nom;
			cout << "escribir_arbol_genealogico" << nom << endl;

			if (POBL.existeix_individu(nom)) POBL.escriure_arbre(nom);
			else cout << "  error" << endl;
		}

		else if(comando == "completar_arbol_genealogico")
		{
			cout << "operacion nula" << endl;
		}

		else if(comando == "acabar")
		{
			return 0;
		}

	}
}



















