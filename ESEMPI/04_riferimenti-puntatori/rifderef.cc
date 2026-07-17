using namespace std;
#include <iostream>

int main() {
  int n = 1;
  int *p = &n;
  int &r = *p; //r = &n;
  cout << "r = " << r << endl; //=1
  cout << "p = " << *p << endl; //=1

  int m = 2;
  p = &m;
  cout << "r = " << r << endl; //=1  ->  NO =2 !!!!
  cout << "p = " << *p << endl; //=2

  // Quanto vale r?
  // r "segue" p? -> Le reference vengono legate a una variabile nel momento della loro creazione e non possono più essere "ri-legate" a qualcos'altro per tutta la durata del programma!!!

  return 0;
}
