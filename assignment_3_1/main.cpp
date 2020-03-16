#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>

#include "Student.h"
#include "Test.h"
#include "TestResult.h"

void printChoice();

int main()
{
    std::list<Student> students;
    std::list<Test> tests;
    std::list<TestResult> testResults;
    bool remove = false, edit = true, loop = true;
    int choice, studentIndex = 0, testIndex = 0, removeId = 0;
    std::string input;

    while(loop) {
        printChoice();
        std::getline(std::cin, input);
        std::istringstream num (input);
        num >> choice;
        switch (choice) {
            case 1:
                studentIndex++;
                students.push_back(Student(studentIndex));
                std::cin >> *(std::find_if(students.begin(), students.end(), [studentIndex](auto& s){return s.id == studentIndex;}));
                break;

            case 2:
                editStudent(students, edit);
                break;

            case 3:
                removeId = editStudent(students, remove);
                removeStudentResult(removeId, testResults);
                break;

            case 4:
                testIndex++;
                tests.push_back(Test(testIndex));
                std::cin >> *(std::find_if(tests.begin(), tests.end(), [testIndex](auto& t){return t.id == testIndex;}));
                break;

            case 5:
                editTest(tests, edit);
                break;

            case 6:
                editTest(tests, remove);
                break;

            case 7:
                editTestResult(students, tests, testResults, edit);
                break;

            case 8:
                editTestResult(students, tests, testResults, remove);
                break;

            case 9:
                std::cout << "Student details: " << std::endl;
                printStudents(students);
                std::cout << std::endl;
                std::cout << "Test details: " << std::endl;
                printTests(tests);
                std::cout << std::endl;
                std::cout << "Test results: " << std::endl;
                printTestResults(testResults);
                std::cout << std::endl;
                break;

            case 10:
                loop = false;
                break;

            default:
                std::cout << "Invalid option" << std::endl << std::endl;
                break;
        }
    }
    return 0;
}

void printChoice()
{
    std::cout << "What do you want to do?" << std::endl << "1. Add student" << std::endl << "2. Edit student" << std::endl << "3. Remove student" << std::endl << std::endl << "4. Add test" << std::endl << "5. Edit test" << std::endl << "6. Remove test" << std::endl << std::endl << "7. Add / edit test result" << std::endl << "8. Remove test result" << std::endl << "9. Show all info" << std::endl << std::endl << "10. Exit" << std::endl << std::endl;
}