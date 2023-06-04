#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include "Identifiable.h"

using namespace std;

class Person
{
protected:
    string name;
    string surname;
    string pesel;
    string type;
    string id;
    int age=0;

    int checkPesel(string pesel);

    void setAge(string pesel);

public:

    string getName();

    string getSurname();

    string getPesel();

    int getAge();

    void setName(string name);

    void setSurname(string surname);

    int setPesel(string pesel);

    virtual string getType();

    virtual string getId();

    virtual string toString();
};

#endif