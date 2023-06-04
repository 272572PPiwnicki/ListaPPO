#include "Person.h"

using namespace std;

class Student : public Person, public Identifiable
{
private:
    string index;
    string type = "Student";
    string id = index;

public:

    string getIndex();

    void setIndex(int index);

    string getType();
   
    string getId();

    string toString();
};