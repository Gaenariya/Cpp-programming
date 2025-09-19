#include <iostream>
using namespace std;

int greeting(int x, int y);
int greeting(int*, int*); //선언해주기
int main()
{
    int a, b;
    int x = 10;
    int y = 20;
    a = greeting(x, y);
    cout << x << " " << y;
    b = greeting(&x, &y);
    cout << x << " " << y;
    cout << a;
    cout << b;
    return 0;
}

int greeting(int x, int y) //함수
{
    cout << " ************** " <<endl;
    cout << "  *  1  * " << endl;
    cout << " ************** " << endl;
    x = x + y;
    return x + y;
}

int greeting(int* c, int* d) //함수
{
    cout << " ************** " <<endl;
    cout << "  *  2  * " << endl;
    cout << " ************** " << endl;
    (*c) = (*c) + (*d);
    return (*c);
}
