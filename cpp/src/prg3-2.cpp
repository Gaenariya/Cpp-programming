#include <iostream>
using namespace std;

class Circle
{   
    private:
        double radius;

    public:
        Circle(double radius); // 이게 매개변수가 있는 생성자 (그룹1)(필수 요소, 기본 생성자나 매개변수가 있는 생성자 중 하나는 존재해야 쓰레기 값을 받지 않음.)
        Circle(); // 이게 기본 생성자 (그룹1)(필수 요소, 기본 생성자나 매개변수가 있는 생성자 중 하나는 존재해야 쓰레기 값을 받지 않음.)
        Circle(const Circle& circle); // 이것이 복사생성자 (그룹2)
        ~Circle(); // 소멸자 (그룹3)
        void setRadius(double value);
        double getRadius() const;
        double getArea() const;
        double getPerimeter() const;
};

Circle :: Circle(double rds)
: radius(rds)
{
    cout << "Circle1" << endl;
}

Circle :: Circle()
: radius(0.0) // 기본 생성자의 초기값을 0으로 주는 것
{
    cout << "Circle2" << endl;
}

Circle :: Circle(const Circle& circle) // 이것이 복사생성자
: radius(circle.radius)
{
    cout << "Circle3" << endl;
}

Circle :: ~Circle()
{
    cout << "Circle4" << endl;
}

double Circle :: getRadius() const 
{return radius;}
double Circle :: getArea() const 
{const double PI = 3.14; return (PI * radius * radius);}
double Circle :: getPerimeter() const 
{const double PI = 3.14; return (2 * PI * radius);}
void Circle :: setRadius(double rds) 
{radius = rds;} // this -> radius = radius;
// 클래스 :: 함수 이름() const까지, ::와 const가 멤버 함수 정의만의 2가지 차이점임

int main(){
    Circle circle1(5.2);
    cout << "Radius : " << circle1.getRadius() << endl;
    cout << "Area : " << circle1.getArea() << endl;
    cout << "Perimeter : " << circle1.getPerimeter() << endl << endl;

    Circle circle2(circle1);
    cout << "Radius : " << circle2.getRadius() << endl;
    cout << "Area : " << circle2.getArea() << endl;
    cout << "Perimeter : " << circle2.getPerimeter() << endl;

    Circle circle3;
    circle3.setRadius(99.0); // 그냥 출력
    cout << "Radius : " << circle3.getRadius() << endl; // return값이 있는 출력
    cout << "Area : " << circle3.getArea() << endl;
    cout << "Perimeter : " << circle3.getPerimeter() << endl << endl;

    return 0;
}