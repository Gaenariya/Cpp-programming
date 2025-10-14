#include <iostream>
using namespace std;

int greeting(int, int); //선언해주기
int main()
{
    int a;
    a = greeting(5, 17);
    cout << a;
    return 0;
}

int greeting(int x, int y) //함수
{
    cout << " ************** " <<endl;
    cout << "  *  Hello!  * " << endl;
    cout << " ************** " << endl;
    cout << x + y << endl;
    return x + y;
}
