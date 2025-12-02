#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


// 1. Student 클래스

class Student
{
    private:
        string name;
        int studentID;

    protected:
        double gpa;

    public:
        Student();
        Student(const string& name, int id, double gpa);

        void setGPA(double g);

        virtual void displayInfo() const;

        string getName() const;
        int getID() const;
        double getGPA() const;
};

// --------- Student 함수 정의 ----------

Student::Student() 
{
    name = "";
    studentID = 0;
    gpa = 0.0;
}

Student::Student(const string& name, int id, double gpa) 
{
    this->name = name;
    this->studentID = id;
    this->gpa = gpa;
}

void Student::setGPA(double g) 
{
    gpa = g;
}

void Student::displayInfo() const 
{
    cout << "Name: " << name << endl ;
    cout << "Student ID: " << studentID << endl ;
    cout << "GPA: " << gpa << endl ;
}

string Student::getName() const 
{
    return name;
}

int Student::getID() const 
{
    return studentID;
}

double Student::getGPA() const 
{
    return gpa;
}



// 2. GraduateStudent (Student 상속)

class GraduateStudent : public Student
{
    private:
        string researchTopic;

    public:
        GraduateStudent();
        GraduateStudent(const string& name, int id, double gpa, const string& topic);

        void setResearchTopic(const string& topic);

        void displayInfo() const override;

        string getResearchTopic() const;
};

// --------- GraduateStudent 함수 정의 ----------

GraduateStudent::GraduateStudent() : Student() 
{
    researchTopic = "";
}

GraduateStudent::GraduateStudent(const string& name, int id, double gpa, const string& topic) 
    : Student(name, id, gpa)
{
    researchTopic = topic;
}

void GraduateStudent::setResearchTopic(const string& topic) 
{
    researchTopic = topic;
}

void GraduateStudent::displayInfo() const 
{
    Student::displayInfo();
    cout << "Research Topic: " << researchTopic << endl ;
}

string GraduateStudent::getResearchTopic() const 
{
    return researchTopic;
}



// 3. main 함수

int main() 
{
    vector<GraduateStudent> gradList;

    
    // 5개의 GraduateStudent 객체 생성
    
    gradList.push_back(GraduateStudent("Kim Minjae", 1001, 3.8, "AI Robotics"));
    gradList.push_back(GraduateStudent("Park Seoyeon", 1002, 3.6, "Data Mining"));
    gradList.push_back(GraduateStudent("Jung Jaehoon", 1003, 3.9, "Quantum Computing"));
    gradList.push_back(GraduateStudent("Oh Siyoon", 1004, 4.0, "Bioinformatics"));
    gradList.push_back(GraduateStudent("Hwang Doyoon", 1005, 4.2, "Cybersecurity"));

    
    // 데이터 파일에 저장
    
    ofstream outFile("students.txt");

    if (!outFile) 
    {
        cout << "File open error." << endl ;
        return 1;
    }

    for (auto& gs : gradList) 
    {
        outFile << gs.getName() << ",";
        outFile << gs.getID() << ",";
        outFile << gs.getGPA() << ",";
        outFile << gs.getResearchTopic() << endl ;
    }

    outFile.close();

    
    // 저장된 데이터 읽어서 출력
    
    cout << endl << "===== File Output =====" << endl ;

    ifstream inFile("students.txt");

    if (!inFile) 
    {
        cout << "File read error." << endl ;
        return 1;
    }

    string line;

    while (getline(inFile, line)) 
    {
        cout << line << endl ;
    }

    inFile.close();

    return 0;
}
