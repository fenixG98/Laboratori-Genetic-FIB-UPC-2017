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
#include "parametres_repro.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
//#include "Arbre.hh"
#endif

/** @brief Programa principal para la practica <em>Experimentos genéticos en laboratorio</em>.
 */

using namespace std;

//este manda
void llegir_llista_arbre(list<string>& a){
	string x;
  	cin >> x;
  	if (x!= "$")
	{
		a.push_back(x);
    	llegir_llista_arbre(a);
    	llegir_llista_arbre(a);
  	}
	else a.push_back("$");
}

void escriure_llista_arbre(const list<string>& a)
{
	cout << ' ';
	for(list<string>::const_iterator it = a.begin(); it != a.end(); ++it) cout << ' ' << *it;
	cout << endl;	
}

bool completar_ap(list<string>& lp, const list<string>& lg)
{
	list<string>::iterator it1 = lp.begin();
	list<string>::const_iterator it2 = lg.begin();

	while (it1 != lp.end() and it2 != lg.end())
	{
		if (*it1 != "$" and *it1 != *it2) return false; 
		if (*it1 == "$" and *it2 != "$") *it1 = "*"+*it2+"*";

		++it1;
		++it2;
	}
	if (it1 == lp.end() and it2 != lg.end())
	{
		while (it2 != lg.end())
		{	
			if (*it2!="$") lp.push_back("*"+*it2+"*");
			else  lp.push_back("$");
			++it2;
		}
	}
	return true;
}
int main()
{
	especie esp;
	esp.llegir();
	poblacio POBL;
	POBL.llegir(esp);

	string comando;

	while (cin >> comando)
	{
		if (comando == "anadir_individuo")
		{
			string nom;
			cin >> nom;
			individu ind;
			ind.llegir(esp);

			cout << "anadir_individuo " << nom << endl;

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

			cout << "reproduccion_sexual " << a << ' ' << b << ' '<< c << endl;

			par_rep pt(esp);
			pt.llegir_parametres_reproduccio();

			if ((POBL.existeix_individu(a) and POBL.existeix_individu(b) and not POBL.existeix_individu(c))and not((POBL.individu_nom(a).consultar_SEXE() and not POBL.individu_nom(b).consultar_SEXE())))
			{
				if (POBL.compatibles(a,b))
				{
					individu fill(pt, POBL.individu_nom(a),POBL.individu_nom(b));
					POBL.afegir_individu(c, fill);
					POBL.afegir_pares(a, b, c);
				}
				else cout << "  no es posible reproduccion" << endl;

			}
			else cout << "  error" << endl;
		}

		else if(comando == "escribir_arbol_genealogico")
		{
			string nom;
			cin >> nom;
			cout << "escribir_arbol_genealogico " << nom << endl;
		
			if (POBL.existeix_individu(nom)) POBL.escriure_arbre_genealogic(nom);
			else cout << "  error" << endl;
		}

		else if(comando == "completar_arbol_genealogico")
		{
			list<string> lp;
			llegir_llista_arbre(lp);
			string nom = lp.front();

			cout << "completar_arbol_genealogico " << nom << endl;

			

			list<string> lg;
			lg = POBL.arbre_genealogic(nom);

			if (POBL.existeix_individu(nom))
			{
				if (completar_ap(lp, lg)) escriure_llista_arbre(lp);
				else cout << "  no es arbol parcial" << endl; 
			}
			else cout << "  no es arbol parcial"<< endl;
		}

		else if(comando == "acabar")
		{
			cout << "acabar"<<endl;
      		return 0;
		}	     
    }
}
