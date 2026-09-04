#ifndef RECEPTION_H
#define RECEPTION_H

// dichiarazioni per la gestione della coda di interi

using namespace std;
#include <iostream>

struct node {
  int val;
  node * next;
};

struct queue {
  node * tail;
  node * head;
};

void init (queue &);
void deinit (queue &);
void enqueue(int,queue &);
void dequeue(queue &);
void print(const queue &);

int length(queue);

void enqueueCustomer(int,queue[]);
void serveCustomer(queue[]);
void deinit_array (queue[]);
void print_array (const queue []);

#endif