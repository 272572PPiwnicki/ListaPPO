#include <iostream>
#include <vector>
#include "Student.h"
#include "Employee.h"
#include "PersonVector.h"

using namespace std;

PersonVector* people;

void showStudentMenu()
{
    cout << endl << "STUDENT" << endl;
    cout << "1. Dodaj studenta" << endl;
    cout << "2. Pokaz studenta" << endl;
    cout << "3. Pokaz liste studentow" << endl;
}

void showEmployeeMenu()
{
    cout << endl << "PRACOWNIK" << endl;
    cout << "1. Dodaj pracownika" << endl;
    cout << "2. Pokaz pracownika" << endl;
    cout << "3. Pokaz liste pracownikow" << endl;
}

Student addStudent() {
    Student s;
    cout << "Imie ";
    string name;
    cin >> name;
    s.setName(name);
    cout << "Naziwsko: ";
    string surname;
    cin >> surname;
    s.setSurname(surname);
    cout << "Pesel: ";
    string pesel;
    cin >> pesel;
    int err = s.setPesel(pesel);
    if (err == 1)
    {
        cout << "Niepoprawny pesel" << endl;
        return s;
    }
    else if (err == 2)
    {
        cout << "Pesel jest przypisany do innej osoby" << endl;
        return s;
    }
    cout << "Indeks: ";
    int index;
    cin >> index;
    s.setIndex(index);
    return s;
}

Employee addEmployee() {
    Employee e;
    cout << "Imie ";
    string name;
    cin >> name;
    e.setName(name);
    cout << "Nazwisko ";
    string surname;
    cin >> surname;
    e.setSurname(surname);
    cout << "Pesel: ";
    string pesel;
    cin >> pesel;
    int err = e.setPesel(pesel);
    if (err == 1)
    {
        cout << "Niepoprawny pesel" << endl;
        return e;
    }
    else if (err == 2)
    {
        cout << "Pesel jest przypisany do innej osoby" << endl;
        return e;
    }
    cout << "Numer pracownika: ";
    string cardNumber;
    cin >> cardNumber;
    e.setCardNumber(cardNumber);
    cout << "Stanowisko: ";
    string position;
    cin >> position;
    e.setPosition(position);
    return e;
}

int main()
{
    bool exit = false;
    while (!exit)
    {

        cout << endl << "MENU" << endl;
        cout << "1. Menu studentow" << endl;
        cout << "2. Menu pracownikow" << endl;
        cout << "3. Zapisz w pliku" << endl;
        cout << "4. Wczytaj z pliku" << endl;
        cout << "5. Wyjdz" << endl;
        int choice;
        cin >> choice;
        Person* p = nullptr;
        Student st = Student();
        switch (choice) {
        case 1:
            showStudentMenu();
            cout << "Wybor: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                st = addStudent();
                p = &st;
                people->addPerson(p);
                break;
            case 2: {
                cout << "Indeks: ";
                int index;
                cin >> index;
                Student* s = (Student*)people->getPersonById(index);
                cout << s->toString() << endl;
                break;
            }

            case 3:
                cout << "Liczba studentow: " << people->getStudentCount() << endl;
                break;
            default:
                cout << "Nieprawidlowy wybor" << endl;
                break;
            }
            break;

        case 2:
            exit = true;
            break;
        default:
            cout << "Nieprawidlowy wybor" << endl;
            break;


        }
    }
    return 0;
}