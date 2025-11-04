#include <iostream>
#include <cassert> //c assert라는 뜻
using namespace std;

class Person{ // Person class 만들기
    private:
        long identity;
    public:
        void setId(long id); // set은 세팅이니까 void
        long getId() const;
};

void Person :: setId(long id) {
    assert(id >= 0000 && id <= 9999); // 기존 코드는 1000부터라서 0~999까지의 숫자를 하면 컴파일 에러가 남. 나는 고쳐줬으나, 무조건 4자리를 원하면 0NNN 형태로 써도 오류가 나기 때문에 1000부터 쓰는게 편함!
    this -> identity = id; // this -> 는 없어도 되지만 매개변수와 이름이 같으면 헷갈릴 수 있으니까 써주는 중
}

long Person :: getId() const {
    return this -> identity;
}



class Student : public Person { // Student class 만들기. Person이 부모 클래스, Student가 자식 클래스가 됨.
    private:
        double gpa;
    public:
        void setGPA(double gpa);
        double getGPA() const;
};

void Student :: setGPA(double gpa){
    assert (gpa >= 0 && gpa <= 4.0);
    this -> gpa = gpa;
}

double Student :: getGPA() const {
    return this -> gpa;
}

int main() {
    Person psn;
    psn.setId(517L); // long이기 때문에 뒤에 L을 붙여줌.
    cout << psn.getId() << endl << endl;
    
    Student std;
    std.setId(1111L); // Person을 상속받았기 때문에 Id, GPA, ... 를 모두 가지고 있어 setId를 호출할 수 있음음.
    std.setGPA(3.9);
    cout << std.getId() << endl;
    cout << std.getGPA() << endl;

    return 0;
}

//     g++ ./src/parents.cpp -o ./bin;      ./bin/main 도 되네???
// 난  g++ ./src/parents.cpp -o ./bin/main; ./bin/main 이게 정석정석 완전 정석 변수 없음!!!
//     g++ ./src/parents.cpp -o ./bin/main; 여기까지가 컴파일 코드는 완료라는거임~
