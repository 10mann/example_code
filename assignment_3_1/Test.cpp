#include "Test.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <algorithm>
#include <numeric>


Test::Test()
{
    Test::id = -1;
    Test::course = "Uninitialized";
    Test::name = "Uninitialized";
    Test::date = "Uninitialized";
}

Test::Test(int id)
{
    Test::id = id;
}

Test::Test(int id, std::string& course, std::string& name, std::string& date)
{
    Test::id = id;
    Test::course = course;
    Test::name = name;
    Test::date = date;
}

std::ostream& operator<<(std::ostream& os, const Test& test)
{
    os << "test id = " << test.id << ", course name = " << test.course << ", test name = " << test.name << ", date = " << test.date;
    return os;
}

std::istream& operator>>(std::istream& is, Test& test)
{
    std::cout << "Course, name, date: " << std::endl;
    std::getline(is, test.course);
    std::getline(is, test.name);
    std::getline(is, test.date);
    //std::cout << test << std::endl;
    return is;
}

void editTest(std::list<Test>& tests, bool rem_edit)
{
    int index = 1;
    std::cout << "Select test: " << std::endl;
    for(auto& it: tests)
    {
        std::cout << index << ". id = " << it.id << ", course = " << it.course << std::endl;
        index++;
    }
    std::cout << index << ". Back" << std::endl << std::endl;
    std::string input;
    int choice;
    std::getline(std::cin, input);
    std::istringstream num (input);
    num >> choice;
    if(choice == index)
        return;
    auto it = tests.begin();
    it = std::next(it, choice - 1);
    if(!rem_edit)
    {
        tests.erase(it);
        return;
    }
    else
    {
        std::cin >> *it;
    }
}

void printTests(std::list<Test>& tests)
{
    for(auto& it: tests)
        std::cout << it << std::endl;
}