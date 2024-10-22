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

void fillTable(int*** table,int sizeX,int sizeY) {
    for(int i = 0; i < sizeX; i++) {
        for(int j = 0; j < sizeY; j++) {
            (*table)[i][j] = 20;
        }
    }
}

void printTable(int**table,int sizeX,int sizeY) {
    for(int i = 0; i < sizeX; i++) {
        cout<<"[ ";
        for(int j = 0; j < sizeY; j++) {
            cout<< table[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}

//Mod
bool insertCols(int*** table, int index, int cols,int sizeX, int sizeY) {

    if(*table == NULL || index<0 || index>sizeY || cols <0 || sizeX <0 || sizeY <0) {
        return false;
    }

    int **newTable = NULL;
    allocTable2Dim(&newTable, sizeX, sizeY + cols);

    for(int i = 0; i < sizeX; i++) {
        for(int j = 0; j < index; j++) {
            newTable[i][j] = (*table)[i][j];

        }

        for(int j = index; j < sizeY; j++) {
            newTable[i][j + cols] = (*table)[i][j];
        }
    }
    deallocTable2dim(table, sizeX);

    *table = newTable;

    return true;
}

int main() {

    int **table;

    /*cout << allocTable2Dim(&table,3,5)<<endl;
    cout << allocTable2Dim(&table,5,5)<<endl;

    cout << deallocTable2dim(&table,3)<<endl;
    cout << deallocTable2dim(&table,5)<<endl;

    cout << allocTable2Dim(&table,5,5)<<endl;
    cout << deallocTable2dim(&table,5)<<endl;
    */

    allocTable2Dim(&table, 10, 10);
    fillTable(&table, 10, 10);
    printTable(table, 10, 10);

    cout<<endl;

    insertCols(&table, 8, 2, 10, 10);
    printTable(table, 10, 14);

    return 0;
}