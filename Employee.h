#include "Person.h"

using namespace std;

class Employee : public Person, public Identifiable
{
private:
    string cardNumber;
    string position;
    string type = "Pracownik";
    string id = cardNumber;

public:
    string getCardNumber();

    void setCardNumber(string cardNumber);

    string getPosition();

    void setPosition(string position);

    string getType();

    string getId();

    string toString();
};