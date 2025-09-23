#include <iostream>
using namespace std;

//call by reference (사이드 이펙트 O)
void fun(int& y) {
    y++; //포인터 연산 불가능
}

int main() {
    int x = 10;
    fun(x); //주소 전달 없이 사용
    std :: cout << x << endl;
}


/*
//call by value (사이드 이펙트 X)
void fun(int y){
    y++;
}

int main(){
    int x = 10;
    fun(x); //값을 전달
    std :: cout << x << endl;
}
*/

/*
//call by pointer (사이드 이펙트 O)
void fun(int* y){
    (*y)++;
}

int main(){
    int x = 10;
    fun(&x); //주소를 전달
    std :: cout << x << endl;
}
*/