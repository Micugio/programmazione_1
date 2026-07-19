using namespace std;
#include <iostream>

int a,b;

void scambia (int * px, int * py)
{
  //cout << "indirizzo a cui punta px= " << px << ", indirizzo a cui punta py= " << py << endl;

  int t;
  t = *px;
  *px = *py;
  *py = t;

  //cout << "indirizzo a cui punta px= " << px << ", indirizzo a cui punta py= " << py << endl;
}

int main ()
{
  cout << "a e b?: ";
  cin >> a >> b;

  cout << "a= " << a << ", b= " << b << endl;
  //cout << "indirizzo a= " << &a << ", indirizzo b= " << &b << endl;

  scambia(&a,&b);

  cout << "a= " << a << ", b= " << b << endl;
  //cout << "indirizzo a= " << &a << ", indirizzo b= " << &b << endl;

	return 0;
}
