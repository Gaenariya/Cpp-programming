#include <iostream>
using namespace std;

void fun(int, int); // 매개변수의 개수
void fun(int);
void fun(int, float); // 매개변수의 데이터 타입과 그 순서(float, int 순서여도 시그니처가 다른 것것)

// 함수 시그니처는 매개변수만 영향을 가진다. 리턴값은 해당되지 않는다.
//int fun(int); 리턴값은 void, int로 다르지만 fun(int)의 형이 겹치기 때문에 오버로딩이 되지 않는다.

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