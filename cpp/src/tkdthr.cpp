#include <iostream>
#include <cassert>
using namespace std;

/*
 * [기본 클래스 Person]
 * - setId(long), getId()를 가상 함수(virtual)로 선언
 * - test()도 virtual로 선언 → 파생 클래스에서 오버라이딩 가능
 */
class Person {
private:
    long identity;
public:
    virtual void setId(long id);   // 오버라이딩 대상
    virtual long getId() const;    // 오버라이딩 대상

    // 오버라이딩 대상 함수
    virtual void test() {
        cout << "person" << endl;
    }
};

/*
 * [파생 클래스 Student]
 * - Person을 상속받음
 * - using Person::setId; → 부모의 setId(long)을 Student에서도 그대로 사용 가능하게 함
 * - setId(long, double) → 오버로딩: 같은 이름, 다른 매개변수
 * - test() → 오버라이딩: 부모의 virtual 함수를 재정의
 */
class Student : public Person {
private:
    double gpa;
public:
    using Person::setId;   // 숨김 방지: 부모의 setId(long)을 Student에서도 공개

    void setId(long id, double gp); // 오버로딩된 버전 (ID와 GPA 동시에 설정)
    void setGPA(double gpa);
    double getGPA() const;

    void test() override { // 오버라이딩: 부모의 test()를 재정의
        cout << "student" << endl;
    }
};

// -------------------- 구현부 --------------------

void Person::setId(long id) {
    assert(id >= 0 && id <= 9999);
    identity = id;
}

long Person::getId() const {
    return identity;
}

void Student::setGPA(double gpa) {
    assert(gpa >= 0.0 && gpa <= 4.0);
    this->gpa = gpa;
}

double Student::getGPA() const {
    return gpa;
}

/*
 * Student::setId(long, double)
 * - 오버로딩된 함수
 * - 부모의 setId(long) 호출 + GPA 설정
 */
void Student::setId(long id, double gp) {
    Person::setId(id); // 부모의 setId(long) 호출
    setGPA(gp);        // GPA 설정
}

// -------------------- main 함수 --------------------

int main() {
    Person psn;
    psn.setId(517L);       // Person::setId(long) 호출
    cout << psn.getId() << endl << endl;
    psn.test();            // "person" 출력 (Person 버전)

    Student std;
    std.setId(1234);       // using Person::setId 덕분에 부모 버전 호출 가능
    cout << std.getId() << endl;
    std.test();            // "student" 출력 (오버라이딩된 Student 버전)

    std.setId(5678, 3.9);  // 오버로딩된 Student::setId(long,double) 호출
    cout << std.getId() << endl;
    cout << std.getGPA() << endl;

    return 0;
}



// g++ -std=c++11 ./src/tkdthr.cpp -o ./bin/main; ./bin/main 오버라이딩을 사용하려면 최신 버전이어야 해서 설정해줘야함.





// 한 번 빠졌더니 진짜 모르겠음.