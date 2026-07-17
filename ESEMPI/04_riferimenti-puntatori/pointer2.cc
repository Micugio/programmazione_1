using namespace std;
#include <iostream>

int main() {
  int i=0,j=1;
  int *p,*q;

  p = &i;
  q = &j;
  // double x=1.0;
  // p = &x; // ERRORE: tipo incompatibile!!!
  *p = *q;
  i++; //i=2
  j--; //j=0

  cout << "i = " << i << endl; //2
  cout << "j = " << j << endl;  //0
  cout << "*p = " << *p << endl; //2
  cout << "*q = " << *q << endl; //0
  cout << "&i = " << long(&i) << endl; //uguale#
  cout << " p = " << long(p) << endl; //uguale#
  cout << "&j = " << long(&j) << endl; //uguale^
  cout << " q = " << long(q) << endl; //uguale^
  
  q = p;
  (*p)++; //i=3
  (*q)++; //i=4
  i++; //i=5
  j--;  //j=0-1=-1

  cout << "i = " << i << endl; //i=5
  cout << "j = " << j << endl;  //j=-1
  cout << "*p = " << *p << endl;  //i=5
  cout << "*q = " << *q << endl; //i=5
  cout << "&i = " << long(&i) << endl;  //uguale%
  cout << " p = " << long(p) << endl; //uguale%
  cout << " q = " << long(q) << endl; //uguale%

  return 0;
}
