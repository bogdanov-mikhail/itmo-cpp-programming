#pragma once

#include <map>
#include <string>
#include <vector>

struct StudentGrade {
    std::string student_name;
    char grade;
};

class GradeSystem {
   private:
    std::map<std::string, std::vector<StudentGrade>> grade_2_student_name;

   public:
    void addStudentGrade(const std::string& student_name, char grade);

    std::vector<StudentGrade> findStudentGrades(const std::string& student_name);
};
