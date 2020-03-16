#include "TestResult.h"

#include <ostream>
#include <istream>
#include <iostream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include "Student.h"

TestResult::TestResult(int id, std::string& course, int tId, std::string& name)
{
    TestResult::studentId = id;
    TestResult::course = course;
    TestResult::testId = tId;
    TestResult::name = name;
}

std::ostream& operator<<(std::ostream& os, TestResult& testResult)
{
    std::cout << "student id = " << testResult.studentId << ", course name = " << testResult.course << ", test id = " << testResult.testId << ", test name = " << testResult.name << ", grade = " << testResult.grade;
    return os;
}

std::istream& operator>>(std::istream& is, TestResult& testResult)
{
    std::string input;
    std::cout << "course, test id, test name, grade" << std::endl;
    std::getline(is, testResult.course);
    is >> input;
    std::istringstream num (input);
    num >> testResult.testId;
    std::getline(is, testResult.name);
    std::getline(is, testResult.grade);
    return is;
}

void editTestResult(std::list<Student>& students, std::list<Test>& tests, std::list<TestResult>& testResults, bool edit)
{
    bool exists = false;
    int index = 1, choice;
    std::string input;
    std::cout << "Select student: " << std::endl;
    for(auto& it: students)
    {
        std::cout << index << ". id = " << it.id << ", name = " << it.name << std::endl;
        index++;
    }
    std::cout << index << ". Back" << std::endl;
    std::getline(std::cin, input);
    std::istringstream num (input);
    num >> choice;
    if(choice == index)
        return;
    auto it = std::next(students.begin(), choice - 1);
    std::cout << "Selected student: " << it->id << ", name: " << it->name << std::endl;
    index = 1;
    auto resultIt = testResults.begin();
    std::cout << "Select test: " << std::endl;
    if(edit)
    {
        for(auto& it_t: tests)
        {
            std::cout << index << ". id = " << it_t.id << ", course = " << it_t.course << std::endl;
            index++;
        }
    }
    else{
        for (auto &it_t: testResults) {
            if (it_t.studentId == it->id) {
                std::cout << index << ". id = " << it_t.studentId << ", course = " << it_t.course << std::endl;
                resultIt = std::next(resultIt, 1);
                index++;
            }
        }
    }
    std::cout << index << ". Back" << std::endl;
    std::getline(std::cin, input);
    std::istringstream num_t (input);
    num_t >> choice;
    if(choice == index)
        return;
    auto it_t = std::next(tests.begin(), choice - 1);
    if(edit)
    {
        for (auto &testIt: testResults) {
            if (testIt.testId == it_t->id && testIt.studentId == it->id)
                exists = true;
        }
        if (!exists)
            testResults.push_back(TestResult(it->id, it_t->course, it_t->id, it_t->name));
        resultIt = std::find_if(testResults.begin(), testResults.end(),
                                     [it_t, it](auto &t) { return (t.testId == it_t->id && t.studentId == it->id); });
        std::cout << "Enter grade: " << std::endl;
        std::getline(std::cin, resultIt->grade);
    }
    else
    {
        resultIt = std::find_if(testResults.begin(), testResults.end(), [it, it_t](auto& t){return it_t->id == t.testId && it->id == t.studentId;});
        testResults.erase(resultIt);
    }
}

void printTestResults(std::list<TestResult>& testResults)
{
    for(auto& it: testResults)
        std::cout << it << std::endl;
}

void removeStudentResult(int id, std::list<TestResult>& testResults)
{
    if(id == 0)
        return;
    if (testResults.size() > 1)
    {
        auto it = std::find_if(testResults.begin(), testResults.end(), [id](auto &t) { return id == t.studentId; });
        testResults.erase(it);
    }
}