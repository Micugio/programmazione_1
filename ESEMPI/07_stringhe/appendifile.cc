using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>

// ESEMPIO uguale a "copiafile.cc" solo che carattere vengono copiati in append.

int main (int argc, char * argv[])
{
  fstream myin,myout;
  char c;

  if (argc!=3) {
    cout << "Usage: ./a.out <sourcefile> <targetfile>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);
  if (myin.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0);
  }

  myout.open(argv[2],ios::out|ios::app);  // NOTA: file aperto in scrittura append
  if (myout.fail()) {
    myin.close();
    cerr << "Il file " << argv[2] << " non e' scrivibile\n";
    exit(0);
  }

  while (myin.get(c)) {
    myout.put(c);
  }

  myin.close();
  myout.close();

  return 0;
}
