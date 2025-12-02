#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


// 1. Vehicle 추상 클래스

class Vehicle
{
    protected:
        string brand;
        int speed;

    public:
        Vehicle();
        Vehicle(const string& b, int s);

        void setSpeed(int s);

        virtual void displayInfo() const = 0; // 순수 가상 함수

        string getBrand() const;
        int getSpeed() const;
};

// --------- Vehicle 함수 정의 ----------

Vehicle::Vehicle() 
{
    brand = "";
    speed = 0;
}

Vehicle::Vehicle(const string& b, int s) 
{
    brand = b;
    speed = s;
}

void Vehicle::setSpeed(int s) 
{
    speed = s;
}

string Vehicle::getBrand() const 
{
    return brand;
}

int Vehicle::getSpeed() const 
{
    return speed;
}



// 2. Car 클래스 (Vehicle 상속)

class Car : public Vehicle
{
    private:
        int doors;

    public:
        Car();
        Car(const string& b, int s, int d);

        void displayInfo() const override;

        int getDoors() const;
};

// --------- Car 함수 정의 ----------

Car::Car() : Vehicle() 
{
    doors = 0;
}

Car::Car(const string& b, int s, int d) : Vehicle(b, s) 
{
    doors = d;
}

void Car::displayInfo() const 
{
    cout << "Brand: " << brand << "\n";
    cout << "Speed: " << speed << " km/h\n";
    cout << "Doors: " << doors << "\n";
}

int Car::getDoors() const 
{
    return doors;
}



// 3. Bike 클래스 (Vehicle 상속)

class Bike : public Vehicle
{
    private:
        bool hasCarrier;

    public:
        Bike();
        Bike(const string& b, int s, bool carrier);

        void displayInfo() const override;

        bool getHasCarrier() const;
};

// --------- Bike 함수 정의 ----------

Bike::Bike() : Vehicle() 
{
    hasCarrier = false;
}

Bike::Bike(const string& b, int s, bool carrier) : Vehicle(b, s) 
{
    hasCarrier = carrier;
}

void Bike::displayInfo() const 
{
    cout << "Brand: " << brand << "\n";
    cout << "Speed: " << speed << " km/h\n";
    cout << "Has Carrier: " << (hasCarrier ? "Yes" : "No") << "\n";
}

bool Bike::getHasCarrier() const 
{
    return hasCarrier;
}



// 4. main 함수

int main() 
{
    vector<Car> carList;
    vector<Bike> bikeList;

    
    // 5개의 Car 객체 생성
    
    carList.push_back(Car("Hyundai", 180, 4));
    carList.push_back(Car("Kia", 170, 4));
    carList.push_back(Car("Chevrolet", 160, 2));
    carList.push_back(Car("SsangYong", 150, 4));
    carList.push_back(Car("Renault", 140, 2));

    
    // 5개의 Bike 객체 생성
    
    bikeList.push_back(Bike("Samchuly", 25, true));
    bikeList.push_back(Bike("Alton", 30, false));
    bikeList.push_back(Bike("Honda", 50, true));
    bikeList.push_back(Bike("Yamaha", 60, false));
    bikeList.push_back(Bike("Suzuki", 55, true));

    
    // 파일에 저장
    
    ofstream outFile("vehicles.txt");

    if (!outFile) 
    {
        cout << "File open error.\n";
        return 1;
    }

    for (auto& c : carList) 
    {
        outFile << "Car," << c.getBrand() << "," << c.getSpeed() << "," << c.getDoors() << "\n";
    }

    for (auto& b : bikeList) 
    {
        outFile << "Bike," << b.getBrand() << "," << b.getSpeed() << "," << (b.getHasCarrier() ? 1 : 0) << "\n";
    }

    outFile.close();

    
    // 저장된 데이터 읽어서 출력
    
    cout << "\n===== File Output =====\n";

    ifstream inFile("vehicles.txt");

    if (!inFile) 
    {
        cout << "File read error.\n";
        return 1;
    }

    string line;

    while (getline(inFile, line)) 
    {
        cout << line << "\n";
    }

    inFile.close();

    return 0;
}
