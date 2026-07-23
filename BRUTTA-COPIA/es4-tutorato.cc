#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// ESEGUIRE con:  ./a.out es4-file.txt

int main (int argc, char * argv[]) {
  fstream myin;
  char str[100];
  char c;
  int n_str = 0;
  double count = 0;
  double somma = 0;
  double media = 0;

  if (argc!=2) {
    cout << "Usage: ./a.out <sourcefile>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);

  if (myin.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0);
  }

  while (myin.get(c)) {
    if (c != ',') {
      str[n_str] = c;
      n_str++;
    }
    else {
      str[n_str] = '\0';
      somma += atof(str);
      count++;
      n_str = 0;
    }
  }

  cout << "Somma = " << somma << endl;

  if (somma != 0) {
    media = somma/count;
  }
  else {
    media = 0;
  }

  cout << "Media = " << media << endl;

  myin.close();
  
  return 0;
}
