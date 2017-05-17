#include <list>
#include <iostream>
using namespace std;

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

bool r_es_parcial(list<string>::const_iterator itg, list<string>::iterator itp)
{
    
}

bool es_parcial(list<string> &x)
{
    list<string> g;
    llegir_llista_arbre(g);
    
    list<string>::const_iterator itg = g.begin();
    list<string>::iterator itp = x.begin();

    return r_es_parcial(itg, itp);
}

int main()
{   
    list<string> p;
    llegir_llista_arbre(p);
    //escriure_llista_arbre(p);
    bool x = es_parcial(p);
    if (x) escriure_llista_arbre(p);
    else cout << "  no_es_parcial" << endl;
}