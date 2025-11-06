#include <iostream>
#include <algorithm>

using namespace std;

class Student {
    public:
        string name;
        int score;
        Student(string name, int score) {
            this -> name = name;
            this -> score = score;
        }

        bool operator<(Student &student) {
                return this->score > student.score;
        } // < 오버라이딩을 통해 클래스의 정렬 순서를 바꿀 수 있다.
};

int main(void) {
    Student students[] = {
        Student("lee", 100),
        Student("kim", 94),
        Student("mee", 97),
        Student("park", 84),
        Student("gang", 87)
    };

    sort(students, students+5);
    for(int i=0; i<5; i++) {
        cout << students[i].name << endl;
    }
}