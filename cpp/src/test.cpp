#include <iostream>
using namespace std;

class Rectangle {
    private:
        int width;
        int height;
    public: 
        Rectangle();
        Rectangle(int, int);
        int getWidth();
        int getHeight();
};

Rectangle::Rectangle() 
: width(1), height(1) // 앞에 콜론 잊지 말기
{
    cout << "rec1 : " << endl;
}

Rectangle::Rectangle(int width, int height) 
{
    this -> width = width; // 앞 속성, 뒤 매개변수 (매개변수로 받은 값을 속성에다가 넣어줘야 되기 때문에 속성의 주소가 필요)
    this -> height = height; 
    cout << "rec2 : " << endl;
}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}

int main() {
    Rectangle rec1;
    cout << "width : " << rec1.getWidth() << endl;
    cout << "Height : " << rec1.getHeight() << endl << endl;

    Rectangle rec2(3, 4);
    cout << "width : " << rec2.getWidth() << endl;
    cout << "Height : " << rec2.getHeight() << endl << endl;

    return 0;
}