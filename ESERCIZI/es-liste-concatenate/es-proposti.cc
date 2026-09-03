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

nodo * copia(nodo * a) {
  nodo * s = NULL;
  nodo * t = a;
  if (t!=NULL) {
    s = new nodo;
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
  if (s!=NULL) {
    if (s->dato==x) {
      t = x;
    }
    else {
      while (s->next!=NULL && s->next->dato!=x) {
        s = s->next;
      }
      if (s->next != NULL) {
        t = s->dato;
      }
    }
  }
  return t;
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

void sposta_max(nodo * & s) {
  nodo * t = s;
  if (t!=NULL) {
    int max = t->dato;
    while(t!=NULL) {
      if (t->dato > max) {
        max = t->dato;
        t = t->next;
      }
      else {
        t = t->next;
      }
    }
    remove_element(s, max);
    nodo * n_max = new nodo;
    n_max->dato = max;
    n_max->next = s;
    s = n_max;
  }
}

void sposta_min(nodo * & s) {
  nodo * t = s;
  if (t!=NULL) {
    int min = t->dato;
    while(t!=NULL) {
      if (t->dato < min) {
        min = t->dato;
        t = t->next;
      }
      else {
        t = t->next;
      }
    }
    remove_element(s, min);
    nodo * ultimo = s;
    nodo * n_min = new nodo;
    n_min->dato = min;
    n_min->next = NULL;
    if (ultimo!=NULL) {
      while(ultimo->next!=NULL) {
      ultimo = ultimo->next;
      }
      ultimo->next = n_min;
    }
    else {
      s = n_min;
    }
  }
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

  nodo * vuota = NULL;


  nodo * testa = new nodo;
  testa->dato = 2;
  testa->next = NULL;


  nodo * n1 = new nodo;
  nodo * n2 = new nodo;
  nodo * n3 = new nodo;

  n1->dato = 1;
  n1->next = n2;

  n2->dato = 9;
  n2->next = n3;

  n3->dato = 22;
  n3->next = NULL;

  cout << endl;

  int t = restituisci(L4, 2);
  cout << "Il valore precedente a 2 contenuto nella lista L4 è: " << t << endl;

  t = restituisci(vuota, 2);
  cout << "Il valore precedente a 2 contenuto nella lista vuota è: " << t << endl;

  t = restituisci(testa, 2);
  cout << "Il valore precedente a 2 contenuto nella lista testa è: " << t << endl;

  t = restituisci(n1, 2);
  cout << "Il valore precedente a 2 contenuto nella lista n1-n2 è: " << t << endl;

  cout << endl;

  sposta_max(n1);
  stampa(n1);

  cout << endl;

  sposta_min(n1);
  stampa(n1);

  delete_list(L3);
  delete_list(L4);
  delete_list(vuota);
  delete_list(testa);
  delete_list(n1);   // NOTA: Fa la delete della lista costruita con i nodi n1 e n2.

  /*
  // NOTA: non bisogna fare la delete delle liste L1 e L2 perchè con la concatenazione ora fanno parte di L3 di cui ho già fatto la delete.
  delete_list(L1);
  delete_list(L2);
  */

  return 0;
}