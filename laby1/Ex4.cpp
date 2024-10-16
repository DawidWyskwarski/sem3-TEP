#include <iostream>
#include "Table.h"

using namespace std;

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