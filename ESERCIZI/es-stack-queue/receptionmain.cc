#include <iostream>
#include "reception.h"
using namespace std;

// COMPILARE CON: g++ reception.cc receptionmain.cc

int main () {
  char res;
  int num;
  
  queue array[3];

  for (int i = 0; i < 3; i++) {
    init(array[i]);
  }


  do {
    cout << "\nOperazioni possibili:\n"
         << "EnqueueCustomer (e)\n" 
         << "ServeCustomer(dequeue) (s)\n" 
         << "Print (p)\n" 
         << "Exit (x)\n";
    cin >> res;
    switch (res) {
      case 'e':
        cout << "Valore: ";
        cin >> num;
        enqueueCustomer(num,array);
        break;
      case 's':
        serveCustomer(array);
        break;
      case 'p':
        print_array(array);
        break;
      case 'x':
        break;
      default:
        cout << "Valore errato!\n";
    }
  } while (res != 'x');

  deinit_array(array);

  return 0;
}




/*
int main () {
  char res;
  int num;  
  queue q;
  
  init(q);
  do {
    cout << "\nOperazioni possibili:\n"
         << "Enqueue (e)\n" 
         << "First (f)\n" 
         << "Dequeue (d)\n" 
         << "Print (p)\n" 
         << "Exit (x)\n";
    cin >> res;
    switch (res) {
    case 'e':
      cout << "Valore: ";
      cin >> num;
      if (enqueue(num,q)==FAIL)
        cout << "Coda piena\n";
      break;
    case 'f':
      if (first(num,q)==FAIL)
        cout << "Coda vuota\n";
      else 
        cout << "Val: " << num << endl;
      break;
    case 'd':
      if (dequeue(q)==FAIL)
        cout << "Coda vuota\n";
      break;
    case 'p':
      print(q);
      break;
    case 'x':
      break;
    default:
      cout << "Valore errato!\n";
    }
  } while (res != 'x');  
  deinit(q);
}
*/