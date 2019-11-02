#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;

//Setting values in a 10 by 10 array of random integers (1-100)
//Pre: twoDArray has been declared with row and column size of NUM_COLS
//     Must have constant integer NUM_COLS declared
//     rowSize must be less than or equal to NUM_COLS
//Post: All twoDArray has set integers 1-100
void InitArray(/*OUT*/ int twoDArray[][NUM_COLS], /*IN*/ int rowSize);

//Displays the array & set the int to constant so you cannot change it
//Pre: twoDArray contains integers with row and column size of NUM_COLS
//     Must have constant integer NUM_COLS declared
//     rowSize must be less than or equal to NUM_COLS
//Post: Display all values of array in proper format
void PrintArray( /*IN*/ const int twoDArray[][NUM_COLS], /*IN*/ int rowSize);

//Accepts an integer as a parameter and returns its first location in the array
//Pre: twoDArray contains integers with row and column size of NUM_COLS
//     MUst have constant integer NUm_cols declared
//     rowsize mus be less than or equal to NUM_COLS
//     numGuessed contains valid integer
//Post: Return ture if guessNum is in array as well as set rowLoc and colLoc coordinates
//      Return false if guessNum is not found and set rowLoc and colLoc coordinates

bool FindNumber (/*IN*/ const int twoDArray[][NUM_COLS], /*IN*/ int rowSize,
                 /*IN*/ int guessNum, /*OUT*/ int &rowLoc, /*OUT*/ int &colLoc);

int main(){

    int rowLoc = 0;
    int colLoc = 0;
    int guessNum;
    int twoDArray [NUM_ROWS] [NUM_COLS];
    int found;
    int x, y;
    srand (time(nullptr)); //this will get you genuine random numbers.


    InitArray(twoDArray, NUM_COLS);

    // Do/While loop to loop at least once and then continue to loop until the
    // number is found.
    do{
        //prompt for user to guessNum
        cout << "Please guess a number from 1 - 100 only: " << endl << endl;
        cin >> guessNum;
        found = FindNumber (twoDArray, NUM_ROWS, guessNum, rowLoc, colLoc);

        //if/else statement that will check if the number was guessed correctly or not.
        if (!found) {
            cout << " The Number you guessed: '" << guessNum << "' was not found! "
                 << "Please try again" << endl;
        } else
            cout << "Congratulations, the number you guessed was " << guessNum << endl;

    } while (!found );

    do{
            //Prompt for location (x and y)
            cout << "Guess the coordinates of the number by row then column. " << endl;
            cin  >> x >> y;

            //test x against rowLoc and y against colLoc
              if (x == rowLoc && y == colLoc){
                cout << "Yay, you found the number. The number you guessed was "
                << guessNum << " and was located in row: " << rowLoc
                << " and in column: "<< colLoc << ". You have now graduated to a worm."
                <<"Thanks for playing. How about another game, worm? "<< endl;
                   }else if (x < rowLoc && y < colLoc) {
                        cout << "You suck!!" << "x is lower! and y is lower!"
                             << "Try again maggot!"<< endl;
                   } else if (x > rowLoc && y > colLoc){
                        cout << "You suck!!" << "x is higher! and y is higher!"
                             << "Try again maggot!"<< endl;
                   } else if (x < rowLoc && y > colLoc){
                        cout << "You suck!!" << "x is lower! and y is higher!"
                             << "Try again maggot!"<< endl;
                   } else if (x > rowLoc && y < colLoc){
                        cout << "You suck!!" << "x is higher! and y is lower!"
                             << "Try again maggot!"<< endl;
                   } else if (x == rowLoc && y > colLoc){
                        cout << "You suck!!" << "x is correct! and y is higher!"
                             << "Try again maggot!"<< endl;
                   } else if (x == rowLoc && y < colLoc){
                        cout << "You suck!!" << "x is correct! and y is higher!"
                             << "Try again maggot!"<< endl;
                   } else if (x > rowLoc && y == colLoc){
                        cout << "You suck!!" << "x is higher! and y is correct!"
                             << "Try again maggot!"<< endl;
                   }else if (x < rowLoc && y == colLoc){
                        cout << "You suck!!" << "x is lower! and y is correct!"
                             << "Try again maggot!"<< endl;
                   }

    } while (!(x == rowLoc && y == colLoc));

    PrintArray(twoDArray, NUM_ROWS);

    return 0;
}
 void InitArray(/*OUT*/ int twoDArray[][NUM_COLS], /*IN*/ int rowSize) {

    //cout <<"init\n";
    //Loop through each row
    for (int row = 0; row < 10; row++) {
        //loop through each column
        for (int col = 0; col < 10; col++) {
            //Rand generates only one number. because it is within a four loop it generates 100 random numbers.
        twoDArray [row][col] = rand() % 100 + 1;
            //cout << twoDArray [row][col] << " ";
        }
    }
 }

 void PrintArray( /*IN*/ const int twoDArray[][NUM_COLS], /*IN*/ int rowSize) {

    //cout << "Print \n";
     //Loop through each row
    for (int row = 0; row < NUM_ROWS; row++) {
        //loop through each column
        for (int col = 0; col < NUM_COLS; col++) {
            //Rand generates only one number. because it is within a four loop it generates 100 random numbers.
            cout << setw (4) << twoDArray [row][col] << " ";
        }
        cout << endl;
    }
 }

//Accepts an integer as a parameter and returns its first location in the array
//Pre: twoDArray contains integers with row and column size of NUM_COLS
//     Must have constant integer NUm_cols declared
//     rowsize mus be less than or equal to NUM_COLS
//     numGuessed contains valid integer
//Post: Return true if guessNum is in array as well as set rowLoc and colLoc coordinates
//      Return false if guessNum is not found and set rowLoc and colLoc coordinates

bool FindNumber (/*IN*/ const int twoDArray[][NUM_COLS], /*IN*/ int rowSize,
                 /*IN*/ int guessNum, /*OUT*/ int &rowLoc, /*OUT*/ int &colLoc) {

    //loop through loops and columns and return true is found or false

        for (int rowThing = 0; rowThing < NUM_ROWS; rowThing++){
            //loop through each column
            for (int colThing = 0; colThing < NUM_COLS; colThing++)

                // check if value in array == numguessed
                 if (twoDArray [rowThing] [colThing] == guessNum ) {

                    rowLoc = rowThing +1;
                    colLoc = colThing +1;

                    return true;

       }else;

    }return false;
 }
