#ifndef ARBRE_HH
#define ARBRE_HH

#include "PRO2Excepcio.hh"
#include <cstddef>  // per poder fer servir el NULL

template <class T> class Arbre { 

private:     

  struct node_arbre {
    T info;
    node_arbre* segE;
    node_arbre* segD;
  };

  node_arbre* primer_node;

  // especificaci operacions privades

  node_arbre* copia_node_arbre(node_arbre* m)
    /* Pre: cert */
    /* Post: el resultat s NULL si m s NULL; 
       en cas contrari, el resultat apunta al node arrel 
       d'una jerarquia de nodes que s una cpia de la 
       jerarquia de nodes que t el node apuntat per m com a arrel */
  {
    node_arbre* n;
    if (m==NULL) n=NULL;
    else {
      n = new node_arbre;
      n->info = m->info;
      n->segE = copia_node_arbre(m->segE);
      n->segD = copia_node_arbre(m->segD);
    }
    return n;
  }

  void esborra_node_arbre(node_arbre* m)
    /* Pre: cert */
    /* Post no fa res si m s NULL; en cas contrari, 
       allibera espai de tots els nodes de la 
       jerarquia que t el node apuntat per m com a arrel */
  {
    if (m != NULL) {
      esborra_node_arbre(m->segE);
      esborra_node_arbre(m->segD);
      delete m;
    }
  }

public:

  // especificaci operacions pbliques

  Arbre()
    /* Pre: cert */
    /* Post: el p.i. s un arbre buit */
  {
    primer_node= NULL;
  }

  Arbre(const Arbre& original)
    /* Pre: cert */
    /* Post: el p.i. s una cpia d'original */
  {
    if (this != &original)     
      primer_node = copia_node_arbre(original.primer_node);
  }

  ~Arbre() {
    esborra_node_arbre(primer_node);
  }

  Arbre& operator=(const Arbre& original) {
    if (this != &original) {
      esborra_node_arbre(primer_node);
      primer_node = copia_node_arbre(original.primer_node);
    }
    return *this;
  }

  void a_buit()
    /* Pre: cert */
    /* Post: el p.i. s un arbre buit */
  {
    esborra_node_arbre(primer_node);
    primer_node= NULL;
  }  
      
  void swap(Arbre &a)
    /* Pre: a=A, p.i. = P */
    /* Post: el p.i. passa a ser A; a passa a ser P */
  {
    node_arbre* aux;
    aux = a.primer_node;
    a.primer_node = primer_node;
    primer_node = aux;
  }

  void plantar(const T &x, Arbre &a1, Arbre &a2)
    /* Pre: el p.i. s buit, a1=A1, a2=A2, el p.i. no es el mateix objecte 
       que a2 ni que a2 */
    /* Post: el p.i. t x com a arrel, A1 com a fill esquerre i A2 com a 
       fill dret; a1 i a2 sn buits; si A1 i A2 sn el mateix objecte, el
       fill dret n's una cpia */
  {
    if (this != &a1 and this != &a2) {
      if (primer_node==NULL) {
        node_arbre* aux;
        aux= new node_arbre;
        aux->info= x;
        aux->segE= a1.primer_node;
        if (a1.primer_node == a2.primer_node) aux->segD= copia_node_arbre(a1.primer_node);
        else  aux->segD= a2.primer_node;
        primer_node= aux;
        a1.primer_node= NULL;
        a2.primer_node= NULL;
      }
      else
        throw PRO2Excepcio ("El p.i. de plantar ha de ser buit a la crida");
    }
    else
      throw PRO2Excepcio ("El p.i. de plantar no pot coincidir amb els parmetres");    
  }


  void fills (Arbre &fe, Arbre &fd)
    /* Pre: el p.i. no s buit i li diem A, fe i fd sn buits i no sn el 
       mateix objecte */
    /* Post: fe s el fill esquerre d'A, fd s el fill dret d'A,
       el p.i. s buit */
  {
    if (primer_node!=NULL and fe.primer_node==NULL
        and fd.primer_node==NULL) {
      if (&fe != &fd) {       
        node_arbre* aux;
        aux= primer_node;
        fe.primer_node= aux->segE;
        fd.primer_node= aux->segD;
        primer_node= NULL;
        delete aux;
      }
      else 
        throw PRO2Excepcio 
              ("Els dos parmetres de fills no poden coincidir");      
    }
    else if (primer_node==NULL)
      throw PRO2Excepcio ("Un arbre buit no t fills");
    else   
      throw PRO2Excepcio 
        ("Els dos parmetres de fills han de ser buits a la crida");  
  }

  T arrel() const
    /* Pre: el p.i. no s buit */
    /* Post: el resultat s l'arrel del p.i. */
  {
    if (primer_node!=NULL)
      return primer_node->info;    
    else
      throw PRO2Excepcio ("Un arbre buit no t arrel");
  }

  bool es_buit() const 
    /* Pre: cert */
    /* Post: el resultat indica si el p.i. s un arbre buit */
  {
    return (primer_node==NULL);
  }

};

#endif
