#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H
#include <string>

using namespace std;

class Identifiable {
    virtual string getType() = 0;
    virtual string getId() = 0;
};
#endif