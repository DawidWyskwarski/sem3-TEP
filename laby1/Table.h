#ifndef TABLE_H
#define TABLE_H
#include<string>

class Table {
public:
    Table();
    ~Table();
    Table(std::string namePar, int tableLen);
    Table(const Table &other);

    void setNewName(std::string namePar);
    bool setNewSize(int tableLen);
    Table* clone();

private:
    std::string name;
    int* table;
    int tableLength;
};

#endif
