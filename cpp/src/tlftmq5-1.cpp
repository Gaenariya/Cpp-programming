#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


// 1. Student 클래스

class Student {
private:
    string name;
    int studentID;

protected:
    double gpa;

public:
    Student() : name(""), studentID(0), gpa(0.0) {}
    Student(const string& name, int id, double gpa)
        : name(name), studentID(id), gpa(gpa) {}

    void setGPA(double g) { gpa = g; }

    virtual void displayInfo() const {
        cout << "Name: " << name << endl 
             << "Student ID: " << studentID << endl 
             << "GPA: " << gpa << endl ;
    }

    // 파일 저장용 getter

    string getName() const { return name; }
    int getID() const { return studentID; }
    double getGPA() const { return gpa; }
};



// 2. GraduateStudent (Student 상속)

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent() : Student(), researchTopic("") {}

    GraduateStudent(const string& name, int id, double gpa, const string& topic)
        : Student(name, id, gpa), researchTopic(topic) {}

    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    // 오버라이딩
    void displayInfo() const override {
        Student::displayInfo();
        cout << "Research Topic: " << researchTopic << endl ;
    }

    string getResearchTopic() const { return researchTopic; }
};



// 3. 메인 함수

int main() {

    vector<GraduateStudent> gradList;

    // 5개의 GraduateStudent 객체 생성

    gradList.push_back(GraduateStudent("Kim min jae", 1001, 3.8, "AI Robotics"));
    gradList.push_back(GraduateStudent("Park seo hyun", 1002, 3.6, "Data Mining"));
    gradList.push_back(GraduateStudent("Jung jae hun", 1003, 3.9, "Quantum Computing"));
    gradList.push_back(GraduateStudent("Oh si yun", 1004, 4.0, "Bioinformatics"));
    gradList.push_back(GraduateStudent("Hwang do yun", 1005, 4.2, "Cybersecurity"));


    
    // 데이터 파일에 저장
    
    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "File open error.\n";
        return 1;
    }

    for (auto& gs : gradList) {
        outFile << gs.getName() << ","
                << gs.getID() << ","
                << gs.getGPA() << ","
                << gs.getResearchTopic() << endl ;
    }

    outFile.close();


    
    // 저장된 데이터 읽어서 출력
    
    cout << "\n===== File Output =====\n";

    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "File read error.\n";
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl ;
    }

    inFile.close();

    return 0;
}
