#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


// 1. Employee 클래스

class Employee
{
    protected:
        string name;
        int id;
        int salary;

    public:
        Employee();
        Employee(const string& n, int i, int s);

        void showInfo() const;
        virtual void work() const = 0;

        string getName() const;
        int getID() const;
        int getSalary() const;
};

// --------- Employee 함수 정의 ----------

Employee::Employee() 
{
    name = "";
    id = 0;
    salary = 0;
}

Employee::Employee(const string& n, int i, int s) 
{
    name = n;
    id = i;
    salary = s;
}

void Employee::showInfo() const 
{
    cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << "\n";
}

string Employee::getName() const 
{
    return name;
}

int Employee::getID() const 
{
    return id;
}

int Employee::getSalary() const 
{
    return salary;
}



// 2. Manager 클래스

class Manager : public Employee
{
    private:
        int teamSize;

    public:
        Manager();
        Manager(const string& n, int i, int s, int t);

        void work() const override;
        int getTeamSize() const;
};

// --------- Manager 함수 정의 ----------

Manager::Manager() 
{
    name = "";
    id = 0;
    salary = 0;
    teamSize = 0;
}

Manager::Manager(const string& n, int i, int s, int t) 
{
    name = n;
    id = i;
    salary = s;
    teamSize = t;
}

void Manager::work() const 
{
    cout << name << " is managing a team of " << teamSize << " people.\n";
}

int Manager::getTeamSize() const 
{
    return teamSize;
}



// 3. Engineer 클래스

class Engineer : public Employee
{
    private:
        string specialty;

    public:
        Engineer();
        Engineer(const string& n, int i, int s, const string& sp);

        void work() const override;
        string getSpecialty() const;
};

// --------- Engineer 함수 정의 ----------

Engineer::Engineer() 
{
    name = "";
    id = 0;
    salary = 0;
    specialty = "";
}

Engineer::Engineer(const string& n, int i, int s, const string& sp) 
{
    name = n;
    id = i;
    salary = s;
    specialty = sp;
}

void Engineer::work() const 
{
    cout << name << " is doing coding work in " << specialty << ".\n";
}

string Engineer::getSpecialty() const 
{
    return specialty;
}



// 4. main 함수

int main() 
{
    vector<Manager> managers;
    vector<Engineer> engineers;

    
    // 5개의 Manager 객체 생성
    
    managers.push_back(Manager("Kim Minjae", 101, 6000, 5));
    managers.push_back(Manager("Park Seoyeon", 102, 6500, 6));
    managers.push_back(Manager("Jung Jaehoon", 103, 6200, 4));
    managers.push_back(Manager("Oh Siyoon", 104, 7000, 7));
    managers.push_back(Manager("Hwang Doyoon", 105, 6800, 5));

    
    // 5개의 Engineer 객체 생성
    
    engineers.push_back(Engineer("Lee Harin", 201, 5000, "AI"));
    engineers.push_back(Engineer("Choi Minho", 202, 4800, "Web"));
    engineers.push_back(Engineer("Han Jiwoo", 203, 5200, "Mobile"));
    engineers.push_back(Engineer("Song Daeun", 204, 5100, "Embedded"));
    engineers.push_back(Engineer("Yoo Seunghyun", 205, 5300, "Database"));

    
    // 파일에 저장
    
    ofstream outFile("employees.txt");

    for (auto& m : managers) 
    {
        outFile << "Manager," << m.getName() << "," << m.getID() << "," << m.getSalary() << "," << m.getTeamSize() << "\n";
    }

    for (auto& e : engineers) 
    {
        outFile << "Engineer," << e.getName() << "," << e.getID() << "," << e.getSalary() << "," << e.getSpecialty() << "\n";
    }

    outFile.close();


    
    // 파일에서 읽어서 객체 생성 + work() 출력
    
    cout << "\n===== Work Info from File =====\n";

    ifstream inFile("employees.txt");
    string line;

    while (getline(inFile, line)) 
    {
        string type, name, temp;
        int id, salary;
        string extra;

        stringstream ss(line);

        getline(ss, type, ',');
        getline(ss, name, ',');
        getline(ss, temp, ','); id = stoi(temp);
        getline(ss, temp, ','); salary = stoi(temp);
        getline(ss, extra);

        if (type == "Manager") 
        {
            Manager m(name, id, salary, stoi(extra));
            m.work();
        } 
        else if (type == "Engineer") 
        {
            Engineer e(name, id, salary, extra);
            e.work();
        }
    }

    inFile.close();

    return 0;
}
