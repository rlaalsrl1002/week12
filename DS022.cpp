#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int lc_score;
    int rc_score;

    bool isValidScore(int score) const {
        return score >= 0 && score <= 495;
    }
public:
    Student() : name(""), lc_score(0), rc_score(0) {}
    Student(const std::string &name, int lc_score, int rc_score) 
        : name(name), lc_score(lc_score), rc_score(rc_score) {}

    void input() {
        std::cout << "Enter student name: ";
        std::getline(std::cin, name);
        do {
            std::cout << "LC score (0-495): ";
            std::cin >> lc_score;
        } while (!isValidScore(lc_score));
        do {
            std::cout << "RC score (0-495): ";
            std::cin >> rc_score;
        } while (!isValidScore(rc_score));
    }
    void print() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "LC: " << lc_score << " - " << (lc_score >= 350 ? "Pass" : "Fail") << "\n";
        std::cout << "RC: " << rc_score << " - " << (rc_score >= 350 ? "Pass" : "Fail") << "\n";
        std::cout << "Total: " << (lc_score + rc_score) << "\n";
    }
};
int main() {
    Student *student = new Student();
    student->input();
    student->print();
    delete student;
    return 0;
}
