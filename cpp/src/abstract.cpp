// virtual = 추상 클래스, 추상 클래스는 내부적으로 가상 함수와 순수 가상 함수를 모두 가질 수 있다.

#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Shape {
    protected:
        virtual bool isValid() const = 0;
    public:
        virtual void print() const = 0;
        virtual double getArea() const = 0;
};

class Square : public Shape {
    private:
        double side;
        bool isValid() const; // isValid()를 호출했을 때, 0보다 크면 참을 출력하게 된다.
    public:
        Square(double side);
        void print() const;
        double getArea() const;
};

bool Square :: isValid() const {
    return (side > 0.0); // isValid()를 호출했을 때, 0보다 크면 참을 출력하게 된다.
}

Square :: Square(double s)
: side(s) {
    if(!isValid()) {
        cout << "invalid square : " << side << endl;
        assert(false);
    }
}

void Square :: print() const {
    cout << "square size = " << side << endl;
}

double Square :: getArea() const {
    return (side * side);
}

class Rectangle : public Shape {
    private:
        double length;
        double width;
        bool isValid() const;
    public:
        Rectangle(double length, double width);
        void print() const;
        double getArea() const;
};

bool Rectangle :: isValid() const {
    return (length > 0.0 && width > 0.0);
}

Rectangle :: Rectangle(double lg, double wd)
: length(lg), width(wd) {
    if(!isValid()) {
        cout << "invalid rectangle : " << length << " X " << width << endl;
        assert(false);
    }
}

void Rectangle::print() const {
    cout << "rectangle size = " << length << " X " << width << endl;
}

double Rectangle :: getArea() const {
    return length * width;
}



int main() {
    Square sqr(5.0);
    sqr.print();
    cout << sqr.getArea() << endl;

    Rectangle rtg(5.0, 3.0);
    rtg.print();
    cout << rtg.getArea() << endl;

    return 0;
}
