#include <iostream>
using namespace std;


/* Inserire qui sotto la dichiarazione della funzione extract */

int lenght (const char[], int);
void extract_aux(char[], int, int);
char * extract(const char[]);

/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
  char answer;

  do {
    cout << "Inserire la stringa da controllare: ";
    cin >> input_string;

    extracted = extract(input_string);
    cout << "La stringa estratta è: " << extracted << endl;

    delete [] extracted;
    cout << "Si vuole inserire un'altra stringa? [s/n]";
    cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');

  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */

int lenght(const char string[], int i) {
  if (string[i] != '\0') {
    if (string[i] == '@') {
      return 1 + lenght(string, i+1);
    }
    else {
      return 0 + lenght(string, i+1);
    }
  }
  return 0;
}

void extract_aux(char nuovoArray[], int nuovaDIM, int i) {
  if (i < nuovaDIM) {
    nuovoArray[i] = '@';
    return extract_aux(nuovoArray, nuovaDIM, i+1);
  }
  else {
    nuovoArray[i] = '\0';
    return;
  }
}

char * extract(const char string[]) {
  int nuovaDIM = lenght(string, 0);
    
  char * nuovoArray = new char[nuovaDIM+1];

  extract_aux(nuovoArray, nuovaDIM, 0);

  return nuovoArray;
}

/* Inserire qui sopra la definizione della funzione estract */
