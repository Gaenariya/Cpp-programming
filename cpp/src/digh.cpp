#include <iostream>
#include <cassert>
using namespace std;

// -------------------- Person 클래스 --------------------
class Person {
private:
    long identity;   // 개인을 식별하는 ID (0 ~ 9999 범위)

public:
    Person();                // 기본 생성자 (ID를 0으로 초기화)
    Person(long id);         // 매개변수 생성자 (ID를 지정하여 생성)
    void setId(long id);     // ID 설정 함수 (유효성 검사 포함)
    long getId() const;      // ID 반환 함수 (읽기 전용)
    // virtual void test();   // 필요하다면 오버라이딩용 가상 함수 추가 가능
};

// -------------------- Student 클래스 --------------------
class Student : public Person {
private:
    double gpa;   // 학생의 학점 (0.0 ~ 4.0 범위)

public:
    using Person::setId;   // 부모의 setId(long)을 Student에서도 사용 가능하게 공개

    Student();                     // 기본 생성자 (ID=0, GPA=0.0)
    Student(long id, double gp);   // 매개변수 생성자 (ID와 GPA를 동시에 설정)

    void setId(long id, double gp); // 오버로딩된 버전 (ID와 GPA 동시에 설정)
    void setGPA(double gpa);        // GPA 설정 함수 (유효성 검사 포함)
    double getGPA() const;          // GPA 반환 함수 (읽기 전용)

    // void test() override { cout << "student" << endl; } // 필요시 오버라이딩 가능
};

// -------------------- Person 구현부 --------------------

Person::Person() 
: identity(0) {   // 기본 생성자: ID를 0으로 초기화
}

Person::Person(long id) { 
    setId(id);    // 매개변수 생성자: 전달받은 id를 설정
}

void Person::setId(long id) {
    assert(id >= 0 && id <= 9999); // ID는 0~9999 범위여야 함
    identity = id;
}

long Person::getId() const {
    return identity;   // 현재 ID 반환
}

// -------------------- Student 구현부 --------------------

Student::Student() 
: gpa(0.0) { 
    cout << "a" << endl;   // 기본 생성자가 호출될 때 출력
}

Student::Student(long id, double gp) 
: Person(id), gpa(gp) {         
    cout << "b" << endl;   // 매개변수 생성자가 호출될 때 출력
}

void Student::setGPA(double gpa) {
    assert(gpa >= 0.0 && gpa <= 4.0);
    this->gpa = gpa;
}

double Student::getGPA() const {
    return gpa;
}

void Student::setId(long id, double gp) {
    Person::setId(id); // 부모의 setId(long) 호출
    setGPA(gp);        // GPA 설정
}

// -------------------- main 함수 --------------------

int main() {
    Person psn;              // Person 객체 생성 (ID=0)
    psn.setId(517L);         // ID를 517로 설정
    cout << psn.getId() << endl; // 출력: 517

    Student std;             // Student 객체 생성 (ID=0, GPA=0.0)
    std.setId(1234);         // 부모 버전 호출 → ID=1234
    cout << std.getId() << endl; // 출력: 1234

    std.setId(5678, 3.9);    // 오버로딩된 Student::setId 호출 → ID=5678, GPA=3.9
    cout << std.getId() << endl;   // 출력: 5678
    cout << std.getGPA() << endl;  // 출력: 3.9

    return 0;
}






// g++ -std=c++11 ./src/tkdthr.cpp -o ./bin/main; ./bin/main