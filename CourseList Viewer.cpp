// Programmers: John Wilson
// Program: Program #3 for CSC-201. The program will manage a student's course
//          list with the following requirements: Store course data in a file
//          with the following information: Course name, Course ID, Meeting
//          Day(s) and Times along with Building and Room. The file should be
//          structured with each course on a separate line and each data item
//          separated by a comma. Allow the user to display all courses, Allow
//          the user to look up a specific course based on Course ID, Allow the
//          user to add new courses, Allow the user to continue to look up and
//          add courses until they choose to exit.
//Date: 29 Oct 2019
//Class: CSC-201 Fall 2019

#include <iostream>     // library for the cout
#include <fstream>      // library to open and close files
#include <cstdlib>      // library to use the return and exit function
#include <string>      // library to use the string function.
#include <cstring>    //library to manipulate cstrings
#include <conio.h>

using namespace std;

//Struct will include strings buildingName & roomNumber
struct CourseLocation {
	string buildingName;
	string roomNumber;
};

//Struct will include strings classMonth, classDay, classHour, & classMinute
struct ClassTimes {
   string classMonth;
   string classDay;
   string classHour;
   string classMinute;
};

//Struct will have strings courseID & CourseID declared & will include
//       structs CourseLocation & ClassTimes
struct CourseList {
    string courseID;
    string courseName;
    CourseLocation location;
    ClassTimes course;
};

// Prompt user for file name and return ifstream
// Pre: inData &  outData declared
// Post: inData contains valid ifstream for data file
//       outData contains valid ofstream for data file
void InOutFileInfo(/*INOUT*/ ifstream &inData, /*INOUT*/ ofstream &outData);

//Welcomes user to the program and begins the choices
//Pre: Will have welcome screen
//Post: Will display choice information
void WelcomeScreen (/*IN*/);

//Will hold the switch statement in a sperate function
//Pre: Will declare enumerator ButtonType
//     Will declare int choice for the switch statement.
//Post: Will execute the course list switch statement
enum ButtonType {DISPLAY = 1, ADD, SEARCH, EXIT};

// Return ifstream
// Pre: inData declared
// Post: inData contains valid ifstream for data file
CourseList GetFileInfo (/*INOUT*/ ifstream &inData);

// Return ifstream
// Pre: onData declared
// Post: onData contains valid ofstream for data file
void WriteCourseInfo(/*INOUT*/ ofstream &outData, /*OUT*/ CourseList program);

//Prompt user for file name and return ifstream
//Function will return the word # searched by the user
//Pre: inData & int c declared.
//Post: inData contains valid ifstream for data file
//      will successfully display the # the word was found
int WordSearch (/*INOUT*/ifstream &inData, /*IN*/ int c);

int main () {

    CourseList program;
    ifstream inData;              // Link to input file
    ofstream outData;             //link to output file
    string inFileName;            // string name for input file
    string outFileName;           // string name for output file
    string lineIn;                //string to get the text from the file
    string textIn [1000];         //string for textIn
    int egress;                  //Variable for the do/while loop
    int choice (ButtonType c);             //enum variable for the switch statement
    int iD = 0;                 // Variable for the loop inside the switch statement-case1
    int c;

    // Call function to get/open the file
    InOutFileInfo(inData, outData);

    cout << "Welcome to the most incrediblest Course List Viewer. " << endl;

        while (true) {

            //Call function to open the welcome screen
            WelcomeScreen ();

            cin >> c; //input choice for the switch

            //Switch Statement to allow the user to make a choice.
            switch (c) {

            case 1: //Case 1 will display the course list.

                cout << "Your current course list is: \n";

                    // Loop until valid input file name provided
                    while (!inData.eof()){
                    getline (inData, lineIn); //Grabs line information
                    textIn[iD] = lineIn;
                    iD++;
                    }

                  //For loop to read all the lines in the file and displays them
                  for (int j=0; textIn[j] != "\0"; j++) {
                     cout << textIn [j] << endl;
                  };
                  cout << endl;
                  break;

            case 2: //Case 2 will add course to a list

                cout << "Please add the course information below: " << endl;

                if (inData.is_open() && outData.is_open()) {

                  //Call function to the GetFileInfo function
                  GetFileInfo (/*IN*/inData);

                  //Call function to the GetFileInfo function
                  WriteCourseInfo(/*OUT*/ outData, program);
                }
                cout << endl;
                break;

            case 3: //Case 3 will search the file for a course ID

                WordSearch (inData, c);

                break;

            case 4:
                cout << endl << "Thanks for using the most incrediblest Course List Viewer.. "
                     << "Have a SMURFY day!!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please choose 1, 2, or 3 only!! \n" << endl;
                break;

            }
            continue;

        };

     cout << endl << "Thanks for using the most incrediblest Course List Viewer.. "
          << "Have a SMURFY day!!" << endl;

    // Closes input file
    inData.close();

    // Closes output file
    outData.close();
}

void InOutFileInfo(/*INOUT*/ ifstream &inData, /*INOUT*/ ofstream &outData) {

    string inFileName;  // string name for input file
    string outFileName;  // string name for output file
    string line;        //string to get the text from the file

    do {
        // Prompt user for input file name and open file
        cout << "Please enter the input file name. "
             << "HINT: the file name is 'inList.dat'. \n"
            << "Put the file name here:  \n";
        cin >> inFileName;

        inData.open(inFileName.c_str(), ios::in); //opens input file

            //Checks to make sure the file is open
            if (!inData) {
                cout << "Unable to open input file.\n\n";
            }else {
                cout << "Successfully opened input file! \n" << endl;
              }

    } while (!inData); // Loop until valid input file name provided

    do {
        // Prompt user for output file name and open file
        cout << "Please enter the output file name. "
             << "HINT: the file name is 'out.txt'. \n"
            << "Put the file name here:  \n";
        cin >> outFileName;

        outData.open(outFileName.c_str(), ios::out); //Opens output file

        //Checks to make sure the file is open
           if (!outData) {
                cout << "Unable to open output file.";
           }else {
                cout << "Successfully opened output file! \n" << endl;
              }

    } while (!outData); // Loop until valid output file name provided
}

//Welcomes user to the program and begins the choices
//Pre: Will have welcome screen
//Post: Will display choice information
void WelcomeScreen (/*OUT*/) {

    cout<< "Please pick a choice below to begin. \n"
        << "To DISPLAY the current Course List, ENTER [1]. \n"
        << "To ADD to the Course List, Enter [2]. \n"
        << "To SEARCH for a course using the course ID, ENTER [3]. \n"
        << "To EXIT the program, ENTER [4]. \n\n";

    return;
}

// Return ifstream
// Pre: inData declared
// Post: inData contains valid ifstream for data file
CourseList GetFileInfo (/*INOUT*/ ifstream &inData) {

    CourseList program; // Local variable to hold and return course list info

     if (inData.is_open())  {
     //Read all data from file into the course list variable
    inData >> program.courseID >> program.courseName
           >> program.location.buildingName >> program.location.roomNumber
           >> program.course.classMonth >> program.course.classDay
           >> program.course.classHour >> program.course.classMinute;
     }
     return program;
}

// Return ifstream
// Pre: onData declared
// Post: onData contains valid ofstream for data file
void WriteCourseInfo(/*INOUT*/ ofstream &outData, /*OUT*/ CourseList program) {

    cout << "Input Course ID: " << program.courseID << endl
         << "Input Course Name: " << program.courseName << endl
         << "Input course Building Name or number: " << program.location.buildingName << endl
         << "Input course Room Number:  " << program.location.roomNumber << endl
         << "Input course month(s): " << program.course.classMonth << endl
         << "Input course day(s) of the week: " << program.course.classDay << endl
         << "Input course hour: " << program.course.classHour << endl
         << "Input course minute:" << program.course.classMinute << endl;

    cin >> program.courseID >> program.courseName
           >> program.location.buildingName >> program.location.roomNumber
           >> program.course.classMonth >> program.course.classDay
           >> program.course.classHour >> program.course.classMinute;

    outData << "Course ID: " << program.courseID << endl
            << "Course Name: " << program.courseName << endl
            << "Course Building Name: " << program.location.buildingName << endl
            << "Course Room Number: " << program.location.roomNumber << endl
            << "Course begins in Month: " <<program.course.classMonth << endl
            << "Course is on Weekday(s)" << program.course.classDay << endl
            << "Course is at: " << program.course.classHour << ":"
            << program.course.classMinute << endl;
}

//Prompt user for file name and return ifstream
//Function will return the word # searched by the user
//Pre: inData & int c declared.
//Post: inData contains valid ifstream for data file
//      will successfully display the # the word was found
int WordSearch (/*INOUT*/ifstream &inData, /*IN*/ int c) {
    string inFileName;  // string name for input file
	string name;
	string line1 = "";
	string word; // hold the word user inputs to be searched for
	unsigned int found = 0;

    cout << "Please input a filename to search. "
         << "HINT: the file name is 'wordSee.txt'. \n" << endl;
    cin >> inFileName;

    // opening the file
    inData.open( inFileName.c_str(), ios::in); //opens input file

    if (inData.is_open())
    {
        cout << "enter the word: " << endl;
        cin >> name;

         while (line1.find(word) == string::npos) { //reads the lines in the file
            (getline(inData, line1)); // reads all the text in the file.
            }

            //if statement that will check if the word is found
        if (line1.find(word) != string::npos)
            ++found;

        cout << "the word " << word << " was found " << found << " times" << endl;
    }
    else
    {
        cout << "the file " << name << " does not exist!" << endl;
    }

    cout << "press enter to exit " << endl;
    c = getch(); // gets character
    cout << endl;
    return 0;
}

