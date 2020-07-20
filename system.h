#pragma once
#ifndef _DATABASE_H_
#define _DATABASE_H_
#include "People.h"
#include <vector>
using namespace std;

class Database
{
private:
    vector<People *> datalist;

public:
    Database();
    ~Database();
    void addmem();
    vector<People *>::iterator searchmem();
    void delmem();
    void stastic();
    void editmem();
    void edit(int, int, vector<People *>::iterator);
    void dispmem();
    void save();
    void read();
};

#endif