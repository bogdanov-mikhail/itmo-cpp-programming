#include "GradeSystem.h"
#include "IdCard.h"
#include "Student.h"

#include <iostream>
#include <string>

using namespace std;

void printStudentGrade(const StudentGrade& grade) {
    std::cout << "Оценка " << grade.grade << std::endl;
}

void printStudentGrades(const std::vector<StudentGrade>& grades) {
    for (const auto& grade: grades) {
        printStudentGrade(grade);
    }
}


int main() {
    system("chcp 65001");

    IdCard* idc = new IdCard(123456, "Студент");
    IdCard* idc2 = new IdCard(654321, "Студент");

    Student student1("Миша", "Богданов", idc);
    Student student2("Леша", "Попович", idc2);

    GradeSystem grades;
    grades.addStudentGrade(student1.get_name(), 'A');
    grades.addStudentGrade(student1.get_name(), 'B');
    grades.addStudentGrade(student2.get_name(), 'C');
    grades.addStudentGrade(student2.get_name(), 'D');

    std::vector<StudentGrade> grade1 = grades.findStudentGrades(student1.get_name());
    printStudentGrades(grade1);

    std::vector<StudentGrade> grade2 = grades.findStudentGrades(student2.get_name());
    printStudentGrades(grade2);
}
