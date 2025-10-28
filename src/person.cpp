#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        int age;
        string name;

    public:
        Person();
        int getage() const;
        string getname() const;
        
};

Person :: Person()
: age(22), name("knr")
{
    cout << "person1" << endl;
}

string Person :: getname() const 
{
    return name;
}

int Person :: getage() const 
{
    return age;
}

int main() {
    Person person1;
    cout << "name : " << person1.getname() << endl;
    cout << "age : " << person1.getage() << endl;

    return 0;
}