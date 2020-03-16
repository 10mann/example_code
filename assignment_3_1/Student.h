#ifndef ASSIGNMENT_3_1_STUDENT_H
#define ASSIGNMENT_3_1_STUDENT_H

#include <string>
#include <ostream>
#include <list>



class Student {
public:

    Student();
    Student(int id);
    Student(int id, std::string& name, std::string& email);

    int id;
    std::string name;
    std::string email;
};

std::ostream& operator<<(std::ostream& os, const Student& student);
std::istream& operator>>(std::istream& is, Student& student);

int editStudent(std::list<Student>& students, bool rem_edit);
void printStudents(std::list<Student>& students);

#endif //ASSIGNMENT_3_1_STUDENT_H
