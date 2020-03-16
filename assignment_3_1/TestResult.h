#ifndef ASSIGNMENT_3_1_TESTRESULT_H
#define ASSIGNMENT_3_1_TESTRESULT_H

#include "Student.h"
#include "Test.h"

#include <string>
#include <ostream>
#include <istream>
#include <list>


class TestResult {
public:

    TestResult(int id, std::string& course, int tId, std::string& name);

    int studentId, testId;
    std::string course, name, grade;
};

std::ostream& operator<<(std::ostream& os, TestResult& testResult);
std::istream& operator>>(std::istream& is, TestResult& testResult);

void editTestResult(std::list<Student>& students, std::list<Test>& tests, std::list<TestResult>& testResults, bool edit);
void printTestResults(std::list<TestResult>& testResults);
void removeStudentResult(int id, std::list<TestResult>& testResults);
#endif //ASSIGNMENT_3_1_TESTRESULT_H
