//  Example 7.14, page 199
//  Schaum's Outline of Programming with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1996

using namespace std;
#include <iostream>
#include <cstring>

int main()
{
  char s[] = "The Mississippi is a long river.";
  cout << "s = \"" << s << "\"\n";

  char* p = strchr(s, ' '); // Restituisce puntatore ad una stringa che inzia con la PRIMA occorrezza di " "(spazio).
  cout << "strchr(s, ' ') points to s[" << p - s << "].\n";
  cout << "p = " << p << endl;

  cout << endl;

  p = strchr(s, 's'); // Restituisce puntatore ad una stringa che inzia con la PRIMA occorrezza di "s"(char).
  cout << "strchr(s, 's') points to s[" << p - s << "].\n";
  cout << "p = " << p << endl;

  cout << endl;

  p = strrchr(s, 's'); // Restituisce puntatore ad una stringa che inzia con la ULTIMA occorrezza di "s"(char).
  cout << "strrchr(s, 's') points to s[" << p - s << "].\n";
  cout << "p = " << p << endl;

  cout << endl;

  p = strstr(s, "is"); // Restituisce puntatore ad una stringa che inzia con la PRIMA occorrezza di "is"(string).
  cout << "strstr(s, \"is\") points to s[" << p - s << "].\n";
  cout << "p = " << p << endl;

  cout << endl;

  p = strstr(s, "ciao"); // Restituisce puntatore ad una stringa che inzia con la PRIMA occorrezza di "isi"(string).
  if (p == NULL) {
    cout << "strstr(s, \"ciao\") returns NULL\n";
  }
  cout << "p = " << p << endl;

  return 0;
}
