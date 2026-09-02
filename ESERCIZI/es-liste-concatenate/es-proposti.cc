#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// Struttura lista di interi
struct nodo {
  int dato;
  nodo * next;
};


// Stampa contenuto della lista
void stampa(nodo * s) {
  int i = 1;
  while(s != NULL) {
    cout << "Elemento " << i++ << " = " << s->dato << endl;
    s = s->next;
  }
}

void delete_list(nodo * & s) {   // Passaggio per riferimento
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

nodo * crea_lista() {
  nodo * s = new nodo;
  int val = rand() % 5;
  s->dato = val;
  s->next = NULL;
  nodo * t = s;
  for (int i=1; i<5; i++) {
    nodo * q = new nodo;
    int val = rand() % 5;
    q->dato = val;
    q->next = NULL;
    t->next = q;
    t = t->next;
  }
  return s;
}

bool occorre(nodo * s, int num) {
  bool res = false;
  while(s!=NULL && res==false) {
    if (num == s->dato) {
      res = true;
    }
    else {
      s = s->next;
    }
  }
  return res;
}

nodo * concatena(nodo * a, nodo * b) {
  nodo * s = a;
  nodo * t = a;
  if (t==NULL) {
    s = b;
  }
  else {
    while (t->next != NULL) {
    t = t->next;
    }
    t->next = b;
  }
  return s;
}

/*
nodo * copia(nodo * a) {
  nodo * s = NULL; // Inizializza a NULL per coprire nativamente il caso di lista vuota

  if (a != NULL) {
    // 1. Alloca e copia il primo nodo per la nuova testa
    s = new nodo;
    s->dato = a->dato;
    s->next = NULL;
    
    nodo * k = s;         
    nodo * t = a->next;   

    // 2. Ciclo per i restanti nodi
    while (t != NULL) {
      nodo * q = new nodo;
      q->dato = t->dato;
      q->next = NULL;
      
      k->next = q;        
      k = k->next;        
      t = t->next;        
    }
  }
  
  return s; // Unico punto di uscita della funzione
}
*/

nodo * copia(nodo * a) {
  nodo * s = NULL;
  nodo * t = a;
  if (t!=NULL) {
    nodo * s = new nodo;
    nodo * k = s;
    s->dato = t->dato;
    s->next = NULL;
    t = t->next;
    while (t!=NULL) {
      nodo * q = new nodo;
      q->dato = t->dato;
      q->next = NULL;
      k->next = q;
      k = k->next;
      t = t->next;
    }
  }

  return s;
}

int restituisci(nodo * s, int x) {
  int t = 0;

  if (s!=NULL && s->dato==x) {
    t = x;
    while (s!=NULL && s->next->dato!=x) {
      s = s->next;
    }
    t = s->dato;
  }
  return t;
}


int main() {
  srand(time(NULL));

  nodo * L1 = crea_lista();
  stampa(L1);

  cout << endl;

  nodo * L2 = crea_lista();
  stampa(L2);

  if (occorre(L1, 2) == true) {
    cout << "Numero presente" << endl;
  }
  else {
    cout << "Numero NON presente" << endl;
  }

  cout << endl;

  nodo * L3 = concatena(L1, L2);
  stampa(L3);

  cout << endl;

  nodo * L4 = copia(L3);
  stampa(L4);

  int t = restituisci(L4, 2);
  cout << "Il valore precedente a 2 contenuto nella lista L4 è: " << t << endl;

  delete_list(L3);
  delete_list(L4);

  /*
  // NOTA: non bisogna fare la delete delle liste L1 e L2 perchè con la concatenazione ora fanno parte di L3 di cui ho già fatto la delete.
  delete_list(L1);
  delete_list(L2);
  */

  return 0;
}