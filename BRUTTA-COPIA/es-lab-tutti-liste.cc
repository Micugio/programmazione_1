#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


// Struttura lista di interi
struct nodo {
  int dato;
  nodo * next;
};

void insert_last(nodo * & s, int d) {
  nodo * n = new nodo;
  n->dato = d; 
  n->next = NULL;

  // Se la lista e' vuota, allora s dovra' puntare al nuovo nodo
  if (s == NULL) {
    s = n;
  }
  else {
    // Cerco l'ultimo elemento, q->next qui e' lecito perche' siamo sicuri che s e' diverso da NULL
    nodo * q = s;
    while(q->next != NULL) {
      q = q->next;
    }
    // Una volta trovato ultimo elemento campo next punta al nodo nuvo.
    q->next = n;
  }
}
/*
nodo * reverse(nodo * x) {
  nodo * t;
  nodo * y = x;
  nodo * r = NULL;

  while ( y != NULL ) {
    t = y->next;
    y->next = r;
    r = y;
    y = t;
  }
  return r;
}
*/
void reverse(nodo *& x) {
  nodo * prev = NULL;
  nodo * curr = x;
  nodo * next = NULL;

  while (curr != NULL) {
    next = curr->next;  // Salva il resto della lista
    curr->next = prev;  // Inverte il puntatore del nodo corrente
    prev = curr;        // prev avanza al nodo appena processato
    curr = next;        // curr avanza al nodo successivo da processare
  }
  
  // Aggiorna il puntatore originale del chiamante
  // in modo che punti al nuovo primo nodo (ex ultimo)
  x = prev;
}

void remove_element(nodo * & p, int d) {
  if (p != NULL) {
    nodo* q = p;
    if (q->dato == d) {
      p = p->next;
      delete q;
    }
    else {
      while(q->next != NULL) {
        if (q->next->dato == d) {
          nodo* r = q->next;
          q->next = q->next->next;
          delete r;
          return;
        }
        if (q->next != NULL) {
          q=q->next;
        }
      }
    }
  }
}

void stampa(nodo * s) {
  int i = 0;
  while(s != NULL) {
    cout << "Elemento " << i++ << " = " << s->dato << endl;
    s = s->next;
  }
}

void remove_first(nodo * & s) {
  if (s != NULL) {
    nodo * t = s;
    s = s->next;
    delete t;
  }
}

void remove(nodo * & x) {
  nodo * y = x->next;
  x->next = y->next;
  y->next = NULL;
  delete y;
}

bool non_primalita (int n) {
  if (n <= 1) {
    return true;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return true;
    }
  }
  return false;
}
void primizzaLista(nodo * s) {
  nodo * t = s;
  if (non_primalita(t->next->dato)) {
    remove(t);
  }
  t = t->next;
  while(t != NULL) {
    if (non_primalita(t->next->dato)) {
      remove(t);
    }
    t = t->next;
  }
}

void delete_list(nodo * & s) {
  // Alla fine la lista e' vuota.
  while(s != NULL) {
    // Salvo il valore del nodo corrente
    nodo * t = s;
    // Avanzo al nodo sucessivo
    s = s->next;
    // Dealloco il nodo salvato
    delete t;
  }
}


int main(int argc, char * argv[]) {
  fstream myin;

  char buffer[256];

  // RICORDA: argc = numero di elementi (parole) da input.
  if (argc!=2) {
    cerr << "Usa: ./a.out <fileinput>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);
  if (myin.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0);
  }

  nodo * s = new nodo;

  myin >> buffer;
  int numero = atoi(buffer);
  s->dato = numero;

  while (myin >> buffer) {
    int numero = atoi(buffer);
    insert_last(s, numero);
  }

  myin.close();

  stampa(s);
  cout << endl;
  
  /*
  //s = reverse(s);
  reverse(s);
  stampa(s);
  cout << endl;
  */

  primizzaLista(s);
  stampa(s);

  delete_list(s);
    
  return 0;
}