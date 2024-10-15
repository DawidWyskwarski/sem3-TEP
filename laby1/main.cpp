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
            cout << table[i] << ", ";
        }

        cout << "]" << endl;

        delete table;
    }
}

bool allocTable2Dim(int ***table,int sizeX, int sizeY) {

    if(sizeX <= 0 || sizeY <=0 || *table != NULL) {
        return false;
    }

    *table = new int*[sizeX];

    for(int i = 0; i < sizeX; i++) {
        (*table)[i] = new int[sizeY];
    }

    return true;
}

bool deallocTable2dim(int ***table,int sizeX/*, int sizeY*/) {

    if( *table==NULL || sizeX <= 0 /*|| sizeY <= 0*/) {
        return false;
    }


    for(int i = 0; i < sizeX; i++) {
        delete (*table)[i];
    }

    delete *table;
    *table = NULL;

    return true;
}

int main() {

    //ex1
    //allocTableFill34(4);

    //ex2
    int **table;

    cout<<allocTable2Dim(&table,5,3)<<endl;

    table[4][2] = initialValueEx1;
    cout<<table[0][0]<<endl;

    //ex3
    cout << deallocTable2dim(&table,5/*,3*/) << endl;

    cout<<allocTable2Dim(&table,6,4)<<endl;

    cout << deallocTable2dim(&table,6) << endl;

    table[0][0] = initialValueEx1;
    cout<<table[0][0]<<endl;

    return 0;
}
