#include <iostream>
using namespace std;

class Circle
{   
    private:
        double radius;

    public:
        Circle(double radius); // �̰� �Ű������� �ִ� ������ (�׷�1)(�ʼ� ���, �⺻ �����ڳ� �Ű������� �ִ� ������ �� �ϳ��� �����ؾ� ������ ���� ���� ����.)
        Circle(); // �̰� �⺻ ������ (�׷�1)(�ʼ� ���, �⺻ �����ڳ� �Ű������� �ִ� ������ �� �ϳ��� �����ؾ� ������ ���� ���� ����.)
        Circle(const Circle& circle); // �̰��� ��������� (�׷�2)
        ~Circle(); // �Ҹ��� (�׷�3)
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
: radius(0.0) // �⺻ �������� �ʱⰪ�� 0���� �ִ� ��
{
    cout << "Circle2" << endl;
}

Circle :: Circle(const Circle& circle) // �̰��� ���������
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
// Ŭ���� :: �Լ� �̸�() const����, ::�� const�� ��� �Լ� ���Ǹ��� 2���� ��������

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
    circle3.setRadius(99.0); // �׳� ���
    cout << "Radius : " << circle3.getRadius() << endl; // return���� �ִ� ���
    cout << "Area : " << circle3.getArea() << endl;
    cout << "Perimeter : " << circle3.getPerimeter() << endl << endl;

    return 0;
}