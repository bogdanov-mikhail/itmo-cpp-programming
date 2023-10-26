//
// Created by bogda on 26.10.2023.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:

    Human(std::string last_name, std::string name, std::string
    second_name) {
        this->last_name = last_name;
        this->name = name;
        this->second_name = second_name;
    }

    std::string get_full_name() {
        std::ostringstream full_name;
        full_name << this->last_name << " "
                  << this->name << " "
                  << this->second_name;
        return full_name.str();
    }

private:
    std::string name; // имя
    std::string last_name; // фамилия
    std::string second_name; // отчество
};

class Student : public Human {
public:
    Student(
            std::string last_name,
            std::string name,
            std::string second_name,
            std::vector<int> scores
    )
            : Human(last_name, name, second_name) {
        this->scores = scores;
    }

    virtual float get_average_grade_score() {
        unsigned int count_scores = this->scores.size();
        unsigned int sum_scores = 0;
        float average_score;
        for (unsigned int i = 0; i < count_scores; ++i) {
            sum_scores += this->scores[i];
        }
        average_score = (float) sum_scores / (float) count_scores;
        return average_score;
    }

private:
    std::vector<int> scores;
};

class Teacher : public Human {
public:
    Teacher(
            std::string last_name,
            std::string name,
            std::string second_name,
            unsigned int work_time
    )
            : Human(last_name, name, second_name) {
        this->work_time = work_time;
    }

    virtual unsigned int get_work_time() {
        return this->work_time;
    }

private:
    unsigned int work_time;
};

int main13_1() {
    system("chcp 65001");

    std::vector<int> scores;
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    Student *stud = new Student("Петров", "Иван", "Алексеевич", scores);

    std::cout << stud->get_full_name() << std::endl;
    std::cout << "Средний балл : " << stud->get_average_grade_score() << std::endl;

    unsigned int teacher_work_time = 40;
    Teacher *tch =
            new Teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);

    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Количество часов: " << tch->get_work_time() << std::endl;

    std::vector<Human> humans;
    humans.push_back(*stud);
    humans.push_back(*tch);

    for (Human& h : humans) {
        cout << h.get_full_name() << '\n';
    }

    return 0;
}