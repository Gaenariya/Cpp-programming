#include <iostream>
using namespace std;

int greeting(int, int); //�������ֱ�
int main()
{
    int a;
    a = greeting(5, 17);
    cout << a;
    return 0;
}

int greeting(int x, int y) //�Լ�
{
    cout << " ************** " <<endl;
    cout << "  *  Hello!  * " << endl;
    cout << " ************** " << endl;
    cout << x + y << endl;
    return x + y;
}
