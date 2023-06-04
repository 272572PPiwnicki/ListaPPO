#include "PersonVector.h"

using namespace std;

void PersonVector::addPerson(Person* person)
{
    personVector.push_back(person);
}

int PersonVector::getPersonCount()
{
    return personVector.size();
}

int PersonVector::getStudentCount()
{
    int studentCount = 0;
    for (int i = 0; i < personVector.size(); i++)
    {
        if (personVector[i]->getType() == "Student")
        {
            studentCount++;
        }
    }
    return studentCount;
}

int PersonVector::getEmployeeCount()
{
    int employeeCount = 0;
    for (int i = 0; i < personVector.size(); i++)
    {
        if (personVector[i]->getType() == "Pracownik")
        {
            employeeCount++;
        }
    }
    return employeeCount;
}

Person* PersonVector::getPersonById(int index)
{
    return personVector[index];
}

void PersonVector::removePersonById(int index)
{
    personVector.erase(personVector.begin() + index);
}

void PersonVector::removePerson(Person* person)
{
    for (int i = 0; i < personVector.size(); i++)
    {
        if (personVector[i]->getPesel() == person->getPesel())
        {
            personVector.erase(personVector.begin() + i);
        }
    }
}

Person PersonVector::getPersonByName(string name)
{
    Person* person = nullptr;
    for (int i = 0; i < personVector.size(); i++)
    {
        if (personVector[i]->getName() == name)
        {
            person = personVector[i];
        }
    }
    return *person;
}

Person PersonVector::getPersonBySurname(string surname)
{
    Person* person = nullptr;
    for (int i = 0; i < personVector.size(); i++)
    {
        if (personVector[i]->getSurname() == surname)
        {
            person = personVector[i];
        }
    }
    return *person;
}

Person PersonVector::getPersonByPesel(string pesel)
{
    Person* person = nullptr;
    for (int i = 0; i < personVector.size(); i++)
    {
        if (personVector[i]->getPesel() == pesel)
        {
            person = personVector[i];
        }
    }
    return *person;
}

void PersonVector::printAll()
{
    for (int i = 0; i < personVector.size(); i++)
    {
        cout << personVector[i]->toString() << endl;
    }
}

void PersonVector::saveToFile()
{
    ofstream file;
    file.open("data.txt");
    for (int i = 0; i < personVector.size(); i++)
    {
        file << personVector[i]->toString() << endl;
    }
    file.close();
}

void PersonVector::loadFromFile()
{
    ifstream file;
    file.open("data.txt");
    string line;
    while (getline(file, line))
    {
        Person person;
        stringstream ss(line);
        string name, surname, pesel;
        ss.ignore(12);

        getline(ss, name, ',');

        ss.ignore(9); 

        getline(ss, surname, ',');

        ss.ignore(6); 

        getline(ss, pesel, ',');

        person.setName(name);
        person.setSurname(surname);
        person.setPesel(pesel);
        personVector.push_back(&person);
    }
    file.close();
}