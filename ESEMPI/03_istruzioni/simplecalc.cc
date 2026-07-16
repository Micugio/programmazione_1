using namespace std;
#include <iostream>

// Semplice calcolatrice

int main() {
  double op1, op2; char op;

  cout << "Immetti espressione del tipo \"operando1 operatore operando\": ";  // ESEMPIO:  3 + 7
  cin >> op1 >> op >> op2;

  if (op=='+')
    cout << op1+op2;
  else if (op=='-')
    cout << op1-op2;
  else if (op=='*')
    cout << op1*op2;
  else if (op=='/')
    cout << op1/op2;
  else 
    cout<<"Errore!";

  cout << endl;

  return 0;
}
