#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        int age;
        string name;

    public:
        Person();
        Person(int, string);
        int getage() const;
        string getname() const;
        
};

Person :: Person()
: age(22), name("knr")
{
    cout << "Person1" << endl;
}

Person :: Person(int age, string name)
// : age(age), name(name) ���� �̰Ÿ� �������� �ű��?
{
    this -> age = age; // a = 5ó�� �ڿ��� �տ��ٰ� �ִ°ǵ�, �츰 ���� �Ű������� ���� �� �Ӽ�(Ŭ���� ����)���ٰ� �ִ°Ŵϱ� �տ��ٰ� this �־��ֱ�
    this -> name = name; // this�� ���� ��ü �ڽ��� ��Ÿ���Ƿ�
    cout << "Person2" << endl;
}

int Person :: getage() const 
{
    return age;
}

string Person :: getname() const 
{
    return name;
}

int main() {
    Person person1;
    cout << "name : " << person1.getname() << endl;
    cout << "age : " << person1.getage() << endl;

    Person person2(23, "asdf");
    cout << "name : " << person2.getname() << endl;
    cout << "age : " << person2.getage() << endl;

    return 0;
}