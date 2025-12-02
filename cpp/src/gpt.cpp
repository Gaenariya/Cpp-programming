#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <memory>

using namespace std;

// ==========================================================
// 1. Student 클래스
// ==========================================================
class Student {
private:
    string name;
    int studentID;
protected:
    double gpa;

public:
    Student(const string& name, int studentID, double gpa)
    {
        this->name = name;
        this->studentID = studentID;
        this->gpa = gpa;

        cout << "Student 객체 생성: " << this->name << endl;
    }

    virtual void displayInfo() const {
        cout << "--- Student Information ---" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Student ID: " << this->studentID << endl;
        cout << fixed << setprecision(2);
        cout << "GPA: " << this->gpa << endl;
    }

    void setGPA(double gpa) {
        if (gpa >= 0.0 && gpa <= 4.5) {
            this->gpa = gpa;
            cout << this->name << "의 GPA가 " << this->gpa << "(으)로 변경되었습니다." << endl;
        } else {
            cout << "오류: GPA 값은 0.0에서 4.5 사이여야 합니다." << endl;
        }
    }

    string getName() const { return name; }
    int getStudentID() const { return studentID; }
    double getGPA() const { return gpa; }

    virtual ~Student() = default;
};

// ==========================================================
// 2. GraduateStudent 클래스
// ==========================================================
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(const string& name, int studentID, double gpa, const string& researchTopic)
        : Student(name, studentID, gpa)
    {
        this->researchTopic = researchTopic;
        cout << "GraduateStudent 객체 생성: " << this->getName() << endl;
    }

    void setResearchTopic(const string& researchTopic) {
        this->researchTopic = researchTopic;
        cout << this->getName() << "의 연구 주제가 \"" << this->researchTopic << "\"(으)로 설정되었습니다." << endl;
    }

    void displayInfo() const override {
        Student::displayInfo();
        cout << "--- Graduate Student Details ---" << endl;
        cout << "Research Topic: " << this->researchTopic << endl;
    }

    string getResearchTopic() const { return researchTopic; }
};

// ==========================================================
// 3. 파일 저장
// ==========================================================
void saveDataToFile(const vector<unique_ptr<Student>>& students, const string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cerr << "오류: " << filename << " 파일을 열 수 없습니다." << endl;
        return;
    }

    for (const auto& student : students) {
        if (auto* grad = dynamic_cast<GraduateStudent*>(student.get())) {
            outFile << "G | "
                    << grad->getName() << " | "
                    << grad->getStudentID() << " | "
                    << grad->getGPA() << " | "
                    << grad->getResearchTopic() << "\n";
        } else {
            outFile << "S | "
                    << student->getName() << " | "
                    << student->getStudentID() << " | "
                    << student->getGPA() << "\n";
        }
    }

    cout << "\n? 총 " << students.size() << "개의 학생 데이터가 " 
         << filename << "에 저장되었습니다.\n";

    outFile.close();
}

// ==========================================================
// 4. 파일 불러오기 (단순 출력)
// ==========================================================
void loadDataFromFile(const string& filename) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cerr << "오류: " << filename << " 파일을 열 수 없습니다." << endl;
        return;
    }

    cout << "\n=========================================\n";
    cout << "    [파일에서 읽어온 데이터 출력]\n";
    cout << "=========================================\n";

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

// ==========================================================
// 5. main 함수
// ==========================================================
int main() {
    vector<unique_ptr<Student>> students;

    cout << "--- 1. 객체 생성 ---\n";

    students.push_back(make_unique<Student>("홍길동", 2022101, 3.50));
    students.push_back(make_unique<Student>("김철수", 2022102, 4.01));

    students.push_back(make_unique<GraduateStudent>("박민지", 2023001, 4.30, "인공지능 기반 패턴 분석"));
    students.push_back(make_unique<GraduateStudent>("이영호", 2023002, 3.88, "양자 컴퓨터 알고리즘"));
    students.push_back(make_unique<GraduateStudent>("최수연", 2023003, 4.15, "친환경 에너지 효율 연구"));

    cout << "\n--- 2. 메소드 테스트 ---\n";

    students[0]->setGPA(4.25);

    if (auto* grad = dynamic_cast<GraduateStudent*>(students[2].get())) {
        grad->setResearchTopic("향상된 인공지능 기반 패턴 분석");
    }

    cout << "\n--- displayInfo() 테스트 ---\n";
    for (const auto& student : students) {
        student->displayInfo();
        cout << "------------------------------\n";
    }

    const string filename = "student_data_final.txt";
    saveDataToFile(students, filename);
    loadDataFromFile(filename);

    cout << "\n프로그램 종료.\n";
    return 0;
}

