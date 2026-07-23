#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// ESEGUIRE con:  ./a.out es4-file.txt

int main (int argc, char * argv[]) {
  fstream myin1, myin2, myout;
  char str[256];
  char c1, c2;

  int n_str = 0;
  double count = 0;
  double somma = 0;
  double media = 0;

  if (argc!=4) {
    cout << "Usage: ./a.out <fileinput1> <fileinput2> <fileoutput>\n";
    exit(0);
  }

  myin1.open(argv[1],ios::in);
  if (myin1.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0);
  }

  myin2.open(argv[2],ios::in);
  if (myin2.fail()) {
    cerr << "Il file " << argv[2] << " non esiste\n";
    myin1.close();
    exit(0);
  }

  myout.open(argv[3],ios::out);
  if (myout.fail()) {
    cerr << "Il file " << argv[3] << " non è scrivibile\n";
    myin1.close();
    myin2.close();
    exit(0);
  }

  // VERSIONE PIÙ CORRETTA
  while (!myin1.eof() && !myin2.eof()) {
    myin1.get(c1);
    myout.put(c1);
    myin2.get(c2);
    myout.put(c2);
  }

  /*
  // ALTRA VERSIONE
  while (myin1.get(c1) && myin2.get(c2)) {
    myout.put(c1);
    myout.put(c2);
  }
  */

  myin1.close();
  myin2.close();
  myout.close();
  
  return 0;
}
