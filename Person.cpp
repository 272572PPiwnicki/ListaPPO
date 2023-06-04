#include <iostream>
#include "Person.h"

using namespace std;

int Person::checkPesel(string pesel)
{
    if (pesel.length() != 11)
        return 1;
    for (int i = 0; i < 11; i++)
    {
        if (pesel[i] < '0' || pesel[i] > '9')
            return 2;
    }
    return 0;
};

void Person::setAge(string pesel)
{
    string rokStr = pesel.substr(0, 2);
    int rok = stoi(rokStr);
    int wiek = 0;
    int pierwszaCyfra = pesel[2] - '0';
    if (pierwszaCyfra >= 0 && pierwszaCyfra <= 1) {
        wiek = 1900 + rok;
    }
    else {
        wiek = 2000 + rok;
    }
    wiek = 2023 - wiek;
    this->age = wiek;
}

string Person::getName()
{
    return name;
}

string Person::getSurname()
{
    return surname;
}

string Person::getPesel()
{
    return pesel;
}

int Person::getAge()
{
    return age;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setSurname(string surname)
{
    this->surname = surname;
}

int Person::setPesel(string pesel)
{
    int check = checkPesel(pesel);
    if (check == 0) {
        this->pesel = pesel;
        setAge(pesel);
    }
    else
        cout << "Zly pesel" << endl;
    return check;
}

string Person::getType()
{
    return type;
}

string Person::getId()
{
    return pesel;
}

string Person::toString()
{
    return "Osoba:Imie=" + name + ",Nazwisko=" + surname + ",Pesel=" + pesel + ",Wiek=" + to_string(age);
}