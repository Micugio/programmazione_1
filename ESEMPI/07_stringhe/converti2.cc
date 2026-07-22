using namespace std;
#include <iostream>
#include <cstdlib>
#include <iomanip>

int main () 
{
  const float euro = 1936.27;

  int value;
  float liravalue;
  
  cin >> value;
  while (!cin.eof()) {
    if (!cin.fail()) {
      liravalue = euro*value;
      cout << value << " " << fixed << setw(8) << setprecision(0) 
           << liravalue << endl;
    }
    else { // (cin.fail() ma non cin.eof(
      char s [100]; // Crea un buffer cestino dove inserire la parola letta (che ha generato l'errore)
      cin.clear(); // Ripristina lo stato normale
      cin >> s; // Inserisce nel buffer s la parola letta da input.
    }
    cin >> value;
  }
  return 0;
}
