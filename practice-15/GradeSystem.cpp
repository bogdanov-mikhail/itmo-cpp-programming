#include "GradeSystem.h"

void GradeSystem::addStudentGrade(
    const std::string& student_name, char grade
) {
    if (grade_2_student_name.count(student_name) == 0) {
        grade_2_student_name[student_name] = std::vector<StudentGrade> { StudentGrade{student_name, grade} };
    } else {
        grade_2_student_name[student_name].push_back(StudentGrade{student_name, grade});
    }
}

std::vector<StudentGrade> GradeSystem::findStudentGrades(const std::string& student_name) {

    return grade_2_student_name[student_name];
}
