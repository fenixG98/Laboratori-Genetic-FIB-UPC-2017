#include <iostream>
#include "poblacio.hh"

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


