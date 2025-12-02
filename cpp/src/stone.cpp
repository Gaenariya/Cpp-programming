#include <iostream>
using namespace std;

class Stone{
    private:
        int weight;
    public:
        Stone();
        Stone(int weight);
        int getWeight();
};

Stone :: Stone()
: weight(0) // 쓰레기값을 방지하기 위해 초기값 넣어주기 (초기화)
{
    // cout << "a" << endl;
};

Stone :: Stone(int weight)
{   
    this -> weight = weight; // 매개변수값 속성으로 넘겨주는거 이제 알지?
    // cout << "a" << endl;
};

int Stone :: getWeight() {
    return weight;
}

int main() {
    Stone stn1;
    cout << stn1.getWeight() << endl;

    Stone stn2(3);
    cout << stn2.getWeight() << endl;
    return 0;
}

// g++ -std=c++11 ./src/stone.cpp -o ./bin/main; ./bin/main (오버라이딩 시)
// g++ ./src/stone.cpp -o ./bin/main; ./bin/main (기존)