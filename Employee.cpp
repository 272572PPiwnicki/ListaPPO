#include "Employee.h"

using namespace std;

string Employee::getCardNumber()
{
    return cardNumber;
}

void Employee::setCardNumber(string cardNumber)
{
    this->cardNumber = cardNumber;
}

string Employee::getPosition()
{
    return position;
}

void Employee::setPosition(string position)
{
    this->position = position;
}

string Employee::getType()
{
    return type;
}

string Employee::getId()
{
    return id;
}

string Employee::toString()
{
    return "Pracownik:Imie=" + getName() + ",Nazwisko=" + getSurname() + ",Pesel=" + getPesel() + ",Wiek=" + to_string(getAge()) + ",Numer pracownika=" + getCardNumber() + ",Stanowisko=" + getPosition();
}