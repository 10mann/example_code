#include "Student.h"
#include <string>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>

Student::Student()
{
    Student::id = -1;
    Student::name = "Uninitialized";
    Student::email = "Uninitialized";
}

Student::Student(int id)
{
    Student::id = id;
}

Student::Student(int id, std::string& name, std::string& email)
{
    Student::id = id;
    Student::name = name;
    Student::email = email;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "student id = " << student.id << ", name = " << student.name << ", email = " << student.email;
    return os;
}

std::istream& operator>>(std::istream& is, Student& student)
{
    std::cout << "Enter name followed by email" << std::endl;
    std::getline(is, student.name);
    std::getline(is, student.email);
    return is;
}

int editStudent(std::list<Student>& students, bool rem_edit)
{
    int index = 1;
    std::cout << "Select student" << std::endl;
    for(auto& it: students)
    {
        std::cout << index << ". id = " << it.id << ", name = " << it.name << std::endl;
        index++;
    }
    std::cout << index << ". Back" << std::endl << std::endl;
    std::string input;
    int choice;
    std::getline(std::cin, input);
    std::istringstream num (input);
    num >> choice;
    if(choice == index)
        return 0;
    auto it = students.begin();
    it = std::next(it, choice - 1);
    if(rem_edit)
    {
        std::cin >> *it;
    }
    else
    {
        students.erase(it);
         return it->id;
    }
    return 0;
}

void printStudents(std::list<Student>& students)
{
    for(auto& it: students)
        std::cout << it << std::endl;
}