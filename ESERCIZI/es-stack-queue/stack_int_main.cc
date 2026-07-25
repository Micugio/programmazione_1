#include <iostream>
#include <fstream>
//#include <cstdlib>
using namespace std;

#include "stack_int.h"

// COMPILARE CON: g++ stack_int.cc stack_int_main.cc

int main(int argc, char * argv[]) {
    fstream myin, myout;

    Stack s;
    init(s);

    int n = 0;
    //buffer[256];


    if (argc!=3) {
        cerr << "Usa: ./a.out <fileinput> <fileoutput>\n";
        exit(0);
    }

    myin.open(argv[1],ios::in);
    if (myin.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        exit(0);
    }

    myout.open(argv[2],ios::app);
    if (myout.fail()) {
        cerr << "Il file " << argv[2] << " non è scrivibile\n";
        myin.close();
        exit(0);
    }

    /*
    while (myin.getline(buffer,256)) {  
        push(s,atoi(buffer));
    }
    */

    while (myin >> n) {  
        push(s,n);
    }

    cout << endl;

    cout << "Stack s: " << endl;
    print(s);
    cout << endl;

    //int n = 5;
    //char c = n + '0'; // c diventa il carattere '5'  ->  NOTA: funziona solo con i numeri da 0 a 9.

    while (pop(s, n)) {  
        myout << n << "\n";
    }

    deinit(s);

    cout << "Stack s: " << endl;
    print(s);
    cout << endl;
    
    return 0;
}
