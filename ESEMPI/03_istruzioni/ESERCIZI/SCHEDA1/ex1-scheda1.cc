#include <iostream>
#include <cmath>
using namespace std;

// ax^2 + b*x + c = 0

int main() {
  
  double a, b, c;

  cout << "Inserisci 3 numeri reali:" << endl;
  cin >> a >> b >> c;

  double delta = (b*b) - (4*a*c);
  double x1, x2;

  if (delta >= 0) {
    x1 = (-b + sqrt(delta)) / 2*a;
    x2 = (-b - sqrt(delta)) / 2*a;

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
  }
  else {
    cout << "Non definita" << endl;
  }

  return 0;
}
