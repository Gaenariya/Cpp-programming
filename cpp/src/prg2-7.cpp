#include <iostream>
using namespace std;

int globalVar = 10;

void exampleFunction(){
    // static int localVar = 20; static(����)�� ����ϸ� �Լ��� ������ ���� ������ => �ʱ�ȭ�Ǹ� ��� ���� ȣ��Ǵµ�, �̸� ���� ����.
    int localVar;
    cout << localVar++ << endl;
}

int main(){
    int mainVar = 30; 

    if(true) {
        int blockVar = 40;
        cout << "Inside block; blockVar = " << blockVar << endl;
    }

    // cout << blockVar; ����! blockVar�� ������ ���, C�� �� ������� {} = ��, �� ������ �̷����!
    exampleFunction();
    exampleFunction();
    exampleFunction();
    // cout << localVar; << endl; ����! localVar�� exampleFunction �ȿ����� �����Ѵ�.

    // ���� ������ �̸��� ���� ��, ����� �������� Ž���Ѵ�. (��, ������ ���Ե� ���� ���� ������ ���� ������ ��������)

    cout << "Global variable; globalVar = " << globalVar << endl;
    cout << "Main variable; mainVar = " << mainVar << endl;
    return 0;
}