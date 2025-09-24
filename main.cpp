#include <iostream>
#include <fstream> // for dat file
#include <cctype> // for toupper, isalpha
#include "Student.h"
using namespace std;

// Global Variables - Will add later

int programming, tests, final;
bool condition = true;

//Functions for Choices, which will call functions from Student.cpp
void setUpNewSemester(); // S - Call function in case/switch
void addStudent(); // A - Call function in case/switch
void recordProgramGrade(); // P - Call function in case/switch
void recordTestGrade(); // T - Call function in case/switch
void recordFinalGrade(); // F - Call function in case/switch
void changeGrade(); // C - Call function in case/switch
void calculateFinal(); // G - Call function in case/switch
void outputGrades(); // O - Call function in case/switch
//(Q) Quit - Call function to save dat file, then break loop in case/switch

// dat File functions

void openDat();
void saveDat();

/* Saving for setUpNewSemester
  cout << "Begin Setup for new semester!" << endl;

  do {
    cout << "Enter the number of programming assignments for this semester: ";
    cin >> programming;
    if (programming > 6) {
      cout << "You've exceeded the max limit of assignments.\n";
    }
  } while (programming > 6);

  do {
    cout << "Enter the number of tests for this semester: ";
    cin >> tests;
    if (tests > 4) {
      cout << "You've exceeded the max limit of tests.\n";
    }
  } while (tests > 4);

  do {
    cout << "Enter the number of final exams for this semester: ";
    cin >> final;
    if (final > 1) {
      cout << "You've exceeded the max limit of final exams.\n";
    }
  } while (final > 1);
*/

void menu()
{
    //Print Menu
    cout << "================ GRADE BOOK ================" << endl;
    cout << "S). Set Up New Semester"
    << "A). Add A Student" << endl
    << "P). Record Programming Assignment Grade for All Students" << endl
    << "T). Record Test Grade for All Students" << endl
    << "F). Record Final Exam Grade for All Students" << endl
    << "C). Change a Grade for a Particular Student" << endl
    << "G). Calculate Final Grade" << endl
    << "O). Output Grade Data" << endl
    << "Q). Quit." << endl;
    
    while (true){ //While loop incase of input error
    
        string input;
        cin >> input;
        
        cout << "Enter choice: ";
        //TEST RUNS 1-3 LISTED BELOW
       
        // 1. If the string is longer than 1 character, it takes the first letter of the string.
        char choice = input[0];
        
        // 2. Repeat if it is not a letter
        if (!isalpha(choice))
        {
            cout << "ERROR! Letters only. Try again. " << endl << endl;
            continue;
        }
        
        // 3. Accepts lower case letters
        choice = toupper(choice); //Changes lower case to upper case
        
        //Function Call
        switch(choice)
        {
            case 'S': //Set Up New Semester
                setUpNewSemester();
                break;
            case 'A': // Add a Student
                addStudent();
                break;
            case 'P': // Record Program Grade
                recordProgramGrade();
                break;
            case 'T': // Record Test Grade
                recordTestGrade();
                break;
            case 'F': // Record Final Exam Grade
                recordFinalGrade();
                break;
            case 'C': // Change a Grade
                changeGrade();
                break;
            case 'G': // Calculate Final Grade
                calculateFinal();
                break;
            case 'O': // Print Grades
                outputGrades();
                break;
            case 'Q': // Quit
                saveDat();
                return;
            default: // Any letter outside of range
                cout << "ERROR! Enter T, F, C, G, O, or Q. Try again. " << endl << endl;
        }
    }
}


int main() {
    
    menu();
    return 0;
}

//Functions for Choices, which will call functions from Student.cpp
void setUpNewSemester() // S - Call function in case/switch
{}
void addStudent() // A - Call function in case/switch
{}
void recordProgramGrade() // P - Call function in case/switch
{}
void recordTestGrade() // T - Call function in case/switch
{}
void recordFinalGrade() // F - Call function in case/switch
{}
void changeGrade() // C - Call function in case/switch
{}
void calculateFinal() // G - Call function in case/switch
{}
void outputGrades() // O - Call function in case/switch
{}
//(Q) Quit - Call function to save dat file, then break loop in case/switch

// dat File functions
void openDat()
{}
void saveDat()
{}
