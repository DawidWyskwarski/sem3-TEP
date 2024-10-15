#include <iostream>

using namespace std;

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
        delete[] (*table)[i];
    }

    delete[] *table;
    *table = NULL;

    return true;
}

int main() {

    int **table;

    cout << allocTable2Dim(&table,3,5)<<endl;
    cout << allocTable2Dim(&table,5,5)<<endl;

    cout << deallocTable2dim(&table,3)<<endl;
    cout << deallocTable2dim(&table,5)<<endl;

    cout << allocTable2Dim(&table,5,5)<<endl;
    cout << deallocTable2dim(&table,5)<<endl;

    return 0;
}