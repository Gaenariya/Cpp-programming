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
// : age(age), name(name) 이제 이거를 내용으로 옮기면?
{
    this -> age = age; // a = 5처럼 뒤에걸 앞에다가 넣는건데, 우린 지금 매개변수로 받은 걸 속성(클래스 변수)에다가 넣는거니까 앞에다가 this 넣어주기
    this -> name = name; // this는 현재 객체 자신을 나타내므로
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