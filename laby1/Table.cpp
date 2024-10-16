#include <iostream>
#include "Table.h"
#include "Constants.h"

using namespace std;

Table::Table() {
    name = initialNameEx4;
    table = new int[initialTableLengthEx4];
    tableLength = initialTableLengthEx4;

    cout << "bezp: '"<< name << "'" <<endl;
}
Table::Table(std::string namePar, int tableLen) {
    name = namePar;
    table = new int[tableLen];
    tableLength = tableLen;

    cout<<"parametr: '" << name << "'" <<endl;
}
Table::Table(const Table &other) {
    name = other.name + "_copy";
    table = new int[other.tableLength];
    tableLength = other.tableLength;

    for(int i=0; i<other.tableLength; i++) {
        table[i] = other.table[i];
    }

    cout<<"kopiuj: '" << name << "'" <<endl;
}
Table::~Table() {
    cout<<"usuwam: '"<< name << "'" <<endl;
    delete[] table;
}
void Table::setNewName(std::string namePar) {
    name = namePar;
}
bool Table::setNewSize(int tableLen) {
    if(tableLen <= 0) {return false;}

    int* newTable = new int[tableLen];

    for(int i=0; i<min(tableLength, tableLen); i++) {
        newTable[i] = table[i];
    }

    delete[] table;
    table = newTable;
    tableLength = tableLen;

    return true;
}
Table *Table::clone() {
    return new Table(*this);
}





