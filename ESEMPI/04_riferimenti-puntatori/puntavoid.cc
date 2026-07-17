using namespace std;
#include <iostream>

int main () {
  int i; 
  int *pi=&i;
  
  char c; 
  char *pc=&c;
  
  void *tp;
  tp = pi;       // punta a int
  *(int*)tp=3;   // prima faccio il cast del mio puntatore "void* tp" in "int* tp"
  cout << "*tp = " << *(int*)tp << endl;  // devo fare sempre il cast per il mio puntatore "void* tp"!!!

  tp = pc;         // punta a char
  *(char*)tp='C';  // prima faccio il cast del mio puntatore "void* tp" in "char* tp"
  cout << "*tp = " << *(char*)tp << endl;  // devo fare sempre il cast per il mio puntatore "void* tp"!!!

  return 0;
}
