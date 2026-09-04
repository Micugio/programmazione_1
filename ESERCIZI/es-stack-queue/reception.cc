using namespace std;
#include <iostream>

#include "reception.h"


static bool emptyp (const queue & Q) {
  return (Q.head == NULL);
}


void init(queue & Q) {
  Q.head = NULL;
  Q.tail = NULL; // COREZIONE GEMINI: Evita che tail contenga un valore spazzatura prima dell'uso
}

void deinit(queue & Q) {
  while (!emptyp(Q))
    dequeue(Q);
}

void enqueue(int n,queue & Q) {
  node * np = new (nothrow) node;
  if (np!=NULL) {
    np->val=n;
    np->next=NULL;
    if (emptyp(Q)) {
      Q.head=np;
    }
    else {
      Q.tail->next=np;
    }
    Q.tail=np;
  }
}

void dequeue(queue & Q) { 
  if (!emptyp(Q)) {
    node * first = Q.head;
    Q.head = Q.head->next;

    //// CORREZIONE GEMINI -> Se la coda è diventata vuota, azzeriamo anche la tail
    if (Q.head == NULL) {
      Q.tail = NULL;
    }
    ////

    delete first; 
  }
}

void print(const queue & Q) {
    node* first = Q.head;
    while (first != NULL) {
        cout << first->val << endl;
        first = first->next;
    }
}




int length(queue Q) {  // NOTA: SEMPRE passaggio per valore, per riferimento perdo accesso a lista (perchè nodo iniziale s (head) alla fine della funzione punterà a null, cioè avrò una lista vuota senza nodi)
  int result = 0;
  for( ; Q.head != NULL; Q.head = Q.head->next) {
    result++;
  }
  return result;
}


void enqueueCustomer(int num, queue array[]) {
  int coda_min = 0;

  for (int i = 0; i < 3; i++) {
    cout << "Lunghezza Coda " << i << ": " << length(array[i]) << endl;
  }

  // Si confronta la coda corrente con il minimo trovato finora
  for (int i = 1; i < 3; i++) {
    if (length(array[i]) < length(array[coda_min])) {
      coda_min = i;
    }
  }

  enqueue(num,array[coda_min]);

  print_array(array);
}
  


void serveCustomer(queue array[]) {
  for (int i = 0; i < 3; i++) {
    dequeue(array[i]);
  }
  print_array(array);
}

void deinit_array(queue array[]) { 
  for (int i = 0; i < 3; i++) {
    deinit(array[i]);
  }
}

void print_array(const queue array[]) {
  for (int i = 0; i < 3; i++) {
    cout << "Coda " << i << ": " << endl;
    print(array[i]);
    cout << endl;
  }
}