#include <iostream>
using namespace std;

void fun(int, int); // �Ű������� ����
void fun(int);
void fun(int, float); // �Ű������� ������ Ÿ�԰� �� ����(float, int �������� �ñ״�ó�� �ٸ� �Ͱ�)

// �Լ� �ñ״�ó�� �Ű������� ������ ������. ���ϰ��� �ش���� �ʴ´�.
//int fun(int); ���ϰ��� void, int�� �ٸ����� fun(int)�� ���� ��ġ�� ������ �����ε��� ���� �ʴ´�.

int main(){
    int a = 10;
    int b = 20;
    int c = 30;
    fun(a, b);
    fun(a);
    fun(3, 4.1f);
    // c = fun(b);
}

void fun(int x, int y){
    std :: cout << x + y << endl ;
}

void fun(int x) {
    std :: cout << x << endl ;
}

void fun(int x, float y){
    std :: cout << x * y ;
}

/*
int fun(int x){
    return x;
}
*/    