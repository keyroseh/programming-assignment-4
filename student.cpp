#include "student.h"
#include <iostream>
using namespace std;

// Constructors
Student::Student():lastName(""), firstName(""), studentNumber(0), finalExam(0.0)
{
    //All assignments in program array iniitialized to 0.0 for each student
    for (int i = 0; i < MAX_PROGRAMS; i++)
    {
        programs[i] = 0.0; //Program Grades
    }
    for (int i = 0; i < MAX_TESTS; i++)
    {
        //All elements in tests array initialized to 0.0 for each student
        for (int i = 0; i < MAX_TESTS; i++)
        {
            tests[i] = 0.0;
        }
    }
}
Student::Student(const string& last, const string& first, int id):lastName(last), firstName(first), studentNumber(id), finalExam(0.0)
{
    //All assignments in program array iniitialized to 0.0 for each student
    for (int i = 0; i < MAX_PROGRAMS; i++)
    {
        programs[i] = 0.0; //Program Grades
    }
    for (int i = 0; i < MAX_TESTS; i++)
    {
        //All elements in tests array initialized to 0.0 for each student
        for (int i = 0; i < MAX_TESTS; i++)
        {
            tests[i] = 0.0;
        }
    }
}
// Student Data
void Student::setName(const string& last, const string& first){
    lastName = last;
    firstName = first;
}
void Student::setStudentNumber(int id)
{
    studentNumber = id;
}

const string& Student::getFirstName() const
{
    return firstName;
}

const string& Student::getLastName() const
{
    return lastName;
}

int Student::getStudentNumber() const
{
    return studentNumber;
}

// P). Program Grades
void Student::setProgramGrade(int i, double grade) {
    programs[i-1] = grade; // if programming assingment is i, index is i-1
}


// T) Record Test Grade
void Student::setTestGrade(int i, double grade) {
    tests[i-1] = grade; // if test is number i, index is i-1
}

// F) Record Final Exam Grade
void Student::setFinalExamGrade(double grade) {
    finalExam = grade;
}

// Calculations

double Student::calcProgramAverage(int num_Of_Programs) const {
    double sum = 0.0; // holding sum of all grades
    for (int i = 0; i < num_Of_Programs; i++) {
        sum += programs[i];
    }
    return sum / num_Of_Programs; // returning avg grade of all prog
}

double Student::calcTestAverage(int num_Of_Tests) const {
    double sum = 0.0; // holding sum of all grades
    for(int i = 0; i < num_Of_Tests; i++) {
        sum += tests[i];
    }
    return sum / num_Of_Tests; // returning avg grade of all tests
}


double Student::calcFinalGrade(double programmingW, double testsW, double finalW, double avgTestGrade, double avgProgrammingGrade) const {
    // changing percentage to decimal
    programmingW = programmingW / 100;
    testsW = testsW / 100;
    finalW = finalW / 100;
    // calculating each final grade
    double finalTestGrade = testsW * avgTestGrade;
    double finalProgrammingGrade = programmingW * avgProgrammingGrade;
    double finalExamGrade = finalW * finalExam;
    // returning sum of grade for all categories
    return finalTestGrade + finalProgrammingGrade + finalExamGrade;
}
// O). Output Student/Grade Data
void Student::printInfo(ostream& out, int num_Of_Programs, int num_Of_Tests, int num_Of_Finals, int programmingW, int testsW, int finalW) const
{
    out << lastName << ", " << firstName << " ID #" << studentNumber << endl;

    // Programs
    out << "Programs: ";
    for (int i = 0; i < num_Of_Programs; i++) {
        out << programs[i] << " ";
    }
    out << endl;

    // Tests
    out << "Tests: ";
    for (int i = 0; i < num_Of_Tests; i++) {
        out << tests[i] << " ";
    }
    out << endl;

    // Final
    if (num_Of_Finals > 0) {
        out << "  Final Exam: " << finalExam << endl;
    }

    // Weighted Final Grade
    double avgProgramming = (num_Of_Programs > 0) ? calcProgramAverage(num_Of_Programs) : 0.0;
    double avgTest = (num_Of_Tests > 0) ? calcTestAverage(num_Of_Tests) : 0.0;
    double finalGrade = calcFinalGrade(programmingW, testsW, finalW, avgTest, avgProgramming);
    out << "  Weighted Final: " << finalGrade << "\n\n";
}

// ---- Persistence ----
void Student::writeDat(ostream& out, int num_Of_Programs, int num_Of_Tests, int num_Of_Finals)
{
    // Write identifiers
    out << lastName << " " << firstName << " " << studentNumber << " ";

    // Write program grades
    for (int i = 0; i < num_Of_Programs; i++) {
        out << programs[i] << " ";
    }

    // Write test grades
    for (int i = 0; i < num_Of_Tests; i++) {
        out << tests[i] << " ";
    }

    // Write final
    if (num_Of_Finals > 0) {
        out << finalExam << " ";
    }

    out << "\n";
}

void Student::readDat(istream& in, int num_Of_Programs, int num_Of_Tests, int num_Of_Finals) {
    // Read identifiers
    in >> lastName >> firstName >> studentNumber;

    // Read program grades
    for (int i = 0; i < num_Of_Programs; i++) {
        in >> programs[i];
    }

    // Read test grades
    for (int i = 0; i < num_Of_Tests; i++) {
        in >> tests[i];
    }

    // Read final
    if (num_Of_Finals > 0) {
        in >> finalExam;
    }
}
