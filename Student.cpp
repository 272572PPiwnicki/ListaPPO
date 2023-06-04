#include <iostream>
#include "Student.h"

using namespace std;

string Student::getIndex()
{
    return index;
}

void Student::setIndex(int index)
{
    this->index = index;
}

string Student::getType()
{
    return type;
}

string Student::getId()
{
    return id;
}

string Student::toString()
{
    return "Student:Imie=" + getName() + ",Nazwisko=" + getSurname() + ",Pesel=" + getPesel() + ",Wiek=" + to_string(getAge()) + ",Indeks=" + getIndex();
}