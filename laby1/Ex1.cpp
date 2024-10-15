#include <iostream>

using namespace std;

const int initialValueEx1 = 34;
void allocTableFill34(int size) {

    if(size > 0) {
        int *table = new int[size];

        for(int i = 0; i < size; i++) {
            table[i] = initialValueEx1;
        }

        cout<< "[ ";

        for(int i = 0; i < size; i++) {
            cout << table[i] << " ";
        }

        cout << "]" << endl;

        delete table;
    }
}

int main() {

    allocTableFill34(4);
    allocTableFill34(0);
    allocTableFill34(16);
    allocTableFill34(-1);
    allocTableFill34(2);

    return 0;
}