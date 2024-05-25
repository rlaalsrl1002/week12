#include <iostream>
#include <string>

class Student {
private:
    double getAvg() const {
        return static_cast<double>(score[0] + score[1] + score[2]) / 3.0;
    }

public:
    std::string name;
    std::string sid;
    int score[3]; 

    void print() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Student ID: " << sid << "\n";
        std::cout << "Scores - Korean: " << score[0] << ", English: " << score[1] << ", Math: " << score[2] << "\n";
        std::cout << "Average Score: " << getAvg() << "\n";
    }
};

int main() {
    Student student;
    std::cout << "Enter student name: ";
    std::getline(std::cin, student.name);
    std::cout << "Enter student ID: ";
    std::getline(std::cin, student.sid);

    std::cout << "Enter Korean score: ";
    std::cin >> student.score[0];
    std::cout << "Enter English score: ";
    std::cin >> student.score[1];
    std::cout << "Enter Math score: ";
    std::cin >> student.score[2];

    student.print();

    return 0;
}
