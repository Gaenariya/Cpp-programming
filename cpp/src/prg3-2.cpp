#include <iostream>
using namespace std;

class Circle
{   
    private:
        double radius;

    public:
        Circle(double radius);
        Circle();
        Circle(const Circle& circle);
        ~Circle();
        void setRadius(double value);
        double getRadius() const;
        double getArea() const;
        double getPerimeter() const;
};

Circle :: Circle(double rds)
: radius(rds)
{
    cout << radius << endl;
}

Circle :: Circle()
: radius(0.0)
{
    cout << radius << endl;
}

Circle :: Circle(const Circle& circle)
: radius(circle.radius)
{
    cout << radius << endl;
}

Circle :: ~Circle()
{
    cout << radius << endl;
}

double Circle :: getRadius() const 
{return radius;}
double Circle :: getArea() const 
{const double PI = 3.14; return (PI * radius * radius);}
double Circle :: getPerimeter() const 
{const double PI = 3.14; return (2 * PI * radius);}
void Circle :: setRadius(double value) 
{radius = value;}
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
    cout << "Radius : " << circle3.getRadius() << endl;
    cout << "Area : " << circle3.getArea() << endl;
    cout << "Perimeter : " << circle3.getPerimeter() << endl << endl;

    return 0;
}