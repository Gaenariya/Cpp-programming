#include <iostream>
using namespace std;

//call by reference (���̵� ����Ʈ O)
void fun(int& y) {
    y++; //������ ���� �Ұ���
}

int main() {
    int x = 10;
    fun(x); //�ּ� ���� ���� ���
    std :: cout << x << endl;
}


/*
//call by value (���̵� ����Ʈ X)
void fun(int y){
    y++;
}

int main(){
    int x = 10;
    fun(x); //���� ����
    std :: cout << x << endl;
}
*/

/*
//call by pointer (���̵� ����Ʈ O)
void fun(int* y){
    (*y)++;
}

int main(){
    int x = 10;
    fun(&x); //�ּҸ� ����
    std :: cout << x << endl;
}
*/