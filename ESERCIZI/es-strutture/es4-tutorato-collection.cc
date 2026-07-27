#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Collection {
    int * nums;
};

Collection inizializzaStruct () {
    Collection c;
    int * array_struct = new int[10];

    for (int i=0; i<10; i++) {
        array_struct[i] = rand() % 1001;
        //cout << array_struct[i] << " ";
    }

    c.nums = array_struct;

    return c;
}

void stampaTutto (Collection * & array_tot, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<10; j++) {
            cout << array_tot[i].nums[j] << " ";
        }
        cout << endl;
        cout << endl;
    }
}

int maxAssoluto (Collection * & array_tot, int n) {
    int max = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<10; j++) {
            if (array_tot[i].nums[j] > max) {
                max = array_tot[i].nums[j];
            }
        }
    }
    return max;
}

void deallocaTutto (Collection * & array_tot, int n) {
    for (int i=0; i<n; i++) {
        delete [] array_tot[i].nums;
    }
    delete [] array_tot;
}

int main() {
    srand(time(NULL));

    int n = 5;
    int massimo = 0;
    Collection * array_tot = new Collection[n];


    for (int i=0; i<n; i++) {
        array_tot[i] = inizializzaStruct();
        //cout << endl;
        //cout << endl;
    }

    stampaTutto (array_tot, n);

    massimo = maxAssoluto(array_tot, n);
    cout << "Il valore massimo assoluto è: " << massimo << endl;

    deallocaTutto(array_tot, n);
    
    return 0;
}