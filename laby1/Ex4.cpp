#include <iostream>

using namespace std;

const string initialName = "deafult name";
const int initialTableLength = 5;

class Table {

public:
    Table() {
        name = initialName;
        table = new int[initialTableLength];
        tableLength = initialTableLength;

        cout << "bezp: '"<< name << "'" <<endl;
    }

    Table(string namePar, int tableLen) {
        name = namePar;
        table = new int[tableLen];
        tableLength = tableLen;

        cout<<"parametr: '" << name << "'" <<endl;
    }

    Table(const Table &other) {
        name = other.name + "_copy";
        table = new int[other.tableLength];
        tableLength = other.tableLength;

        for(int i=0; i<other.tableLength; i++) {
            table[i] = other.table[i];
        }

        cout<<"kopiuj: '" << name << "'" <<endl;
    }

    ~Table() {
        cout<<"usuwam: '"<< name << "'" <<endl;
        delete[] table;
    }

    void setNewName(string namePar) {
        name = namePar;
    }

    bool setNewSize(int tableLen) {

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

    Table *clone() const {
        return new Table(*this);
    }

private:
    string name;
    int* table;
    int tableLength;
};

void modTab(Table *tab,int newSize) {
    tab->setNewSize(newSize);
}

void modTab(Table tab,int newSize) {
    tab.setNewSize(newSize);
}

int main() {

    Table tab1;
    Table tab2("dawid",5);

    cout << "modTab z *: "<<endl;
    modTab(&tab1,10);
    cout << "modTab bez *: "<<endl;
    modTab(tab2,10);

    return 0;
}