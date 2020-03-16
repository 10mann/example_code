#ifndef ASSIGNMENT_3_1_TEST_H
#define ASSIGNMENT_3_1_TEST_H

#include <string>
#include <ostream>
#include <list>

class Test {
public:

    Test();
    Test(int id);
    Test(int id, std::string& course, std::string& name, std::string& date);

    int id;
    std::string course;
    std::string name;
    std::string date;
};

std::ostream& operator<<(std::ostream& os, const Test& test);
std::istream& operator>>(std::istream& is, Test& test);

void editTest(std::list<Test>& tests, bool rem_edit);
void printTests(std::list<Test>& tests);

#endif //ASSIGNMENT_3_1_TEST_H
