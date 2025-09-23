#include <iostream>
using namespace std;

int globalVar = 10;

void exampleFunction(){
    // static int localVar = 20; static(정적)을 사용하면 함수가 끝나도 값이 유지됨 => 초기화되면 계속 새로 호출되는데, 이를 방지 가능.
    int localVar;
    cout << localVar++ << endl;
}

int main(){
    int mainVar = 30; 

    if(true) {
        int blockVar = 40;
        cout << "Inside block; blockVar = " << blockVar << endl;
    }

    // cout << blockVar; 오류! blockVar는 범위를 벗어남, C는 블럭 기반으로 {} = 블럭, 블럭 단위로 이루어짐!
    exampleFunction();
    exampleFunction();
    exampleFunction();
    // cout << localVar; << endl; 오류! localVar는 exampleFunction 안에서만 존재한다.

    // 만약 변수의 이름이 같을 시, 가까운 범위부터 탐색한다. (즉, 본인이 포함된 가장 하위 블럭부터 상위 블럭으로 차례차례)

    cout << "Global variable; globalVar = " << globalVar << endl;
    cout << "Main variable; mainVar = " << mainVar << endl;
    return 0;
}