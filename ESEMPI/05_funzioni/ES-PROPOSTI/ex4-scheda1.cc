#include <iostream>
using namespace std;

void ruota(int& a, int& b, int& c) {
  int t = 0;

  t = c;
  c = a;
  a = b;
  b = t;

  return;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  ruota(a, b, c);

  cout << "a = " << a << "  b = " << b << "  c = " << c << endl;

  return 0;
}
