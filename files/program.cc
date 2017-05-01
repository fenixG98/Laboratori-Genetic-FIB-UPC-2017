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
#include "arbre_parcial.hh"

#ifndef NO_DIAGRAM
#include "Arbre.hh"
#include <iostream>
#include <string>
//#include "Arbre.hh"
#endif

/** @brief Programa principal para la practica <em>Experimentos genéticos en laboratorio</em>.
 */

using namespace std;

void llegir_vector_pair(vector<pair<pair<bool,bool>,int> > &pt, const especie &esp)
{
	for (int i = 0; i < esp.consultar_numero_parells()+1; ++i)
	{
		cin >> pt[i].first.first;
		cin >> pt[i].first.second;
		cin >> pt[i].second;
	}
}

int main()
{
	cout << " PROGRAM RUNNING " << endl;

	especie esp;
	esp.llegir();
	// especie creada
	poblacio POBL;
	POBL.llegir(esp);
	//poblacio llegida

	string comando;

	while (cin >> comando)
	{
		if (comando == "anadir_individuo")
		{
			individu ind;
			string nom;
			cin >> nom;
			ind.llegir(esp);

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
				ind.escriure(esp);
			}
			else cout << "  error" << endl;

		}

		else if(comando == "reproduccion_sexual")
		{
			/*
			 reproduccion_sexual
			 a1 b3 c1
			 0 1 2
			 1 1 3
			 1 0 5
			 1 1 4
			 0 0 3
			 1 1 4
			 */
			string a, b, c;
			cin >> a >> b >> c;

			cout << "reproduccion_sexual" << a << ' ' << b << ' '<< c << endl;
			vector<pair<pair<bool,bool>,int> > pt;
			llegir_vector_pair(pt,esp);
			
			if ((POBL.existeix_individu(a) and POBL.existeix_individu(b) and not POBL.existeix_individu(c)) and POBL.compatibles(a,b))
			{
				individu fill(pt,POBL.individu_nom(a),POBL.individu_nom(b),esp);
				POBL.afegir_individu(c, fill);
				POBL.afegir_pares(a, b, c);
			}
			else cout << "  error" << endl;
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
			//string nom;
			//cin >> nom;

			ArbreP ap;
			ap.llegir();
			ap.escriure();
			//if (POBL.existeix_individu(nom)) POBL.completar_ap(ap);
		}
	
		else if(comando == "acabar")
		{
			return 0;
		}

	}
}



















