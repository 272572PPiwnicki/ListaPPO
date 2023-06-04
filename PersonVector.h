#include <iostream>
#include "Person.h"
#include "Identifiable.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class PersonVector
{
protected:
    vector<Person*> personVector;

public:
    void addPerson(Person* person);

    int getPersonCount();

    int getStudentCount();

    int getEmployeeCount();

    void removePersonById(int Id);
    
    void removePerson(Person* person);

    Person* getPersonById(int index);

    Person getPersonByName(string name);

    Person getPersonBySurname(string surname);

    Person getPersonByPesel(string pesel);

    void saveToFile();

    void loadFromFile();

    void printAll();
};