#include <iostream>
#include <list>

using namespace std;

list<char> reordenar_llistes(int n, list<char> &l1, list<char> &l2)
{
    list <char> aux;

    list<char>::const_iterator it_end;

	it_end = l1.begin();
	advance(it_end,n);
    for( list<char>::const_iterator it=l1.begin(); it != it_end; ++it)  aux.push_back(*it);

    it_end = l2.begin();
    advance(it_end,n);
    for( list<char>::const_iterator it=it_end; it != l2.end(); ++it) aux.push_back(*it);

    return aux;
}

int main()
{
    list <char> a = {'a','b','c','d','e'};
    list <char> b = {'1','2','3'};
    int n = 2;

    list <char> res = reordenar_llistes(n,a,b);   

    for (list<char>::iterator it = res.begin(); it!=res.end(); ++it) cout << *it << ' ';
    cout << endl;
}