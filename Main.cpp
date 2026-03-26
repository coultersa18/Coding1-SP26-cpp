// Sean Coulter Coding 1 Spring 2026
// First C++ Program

// cl EDsc main.cpp < to run program

#include <iostream>     // in out steam, for sending texts to the console
#include <string>       // for player name

using namespace std;        // so we dont have to type "std::"" each time


// here is where we start the program
int main() {
    // declared variables at the top is best practice
    string playerName;      //variables use camelCase
    cout << "What is your name, player? \n>> ";

    //  assign what player types as the value of playerName
    cin >> playerName;

    playerName[0] = toupper(playerName[0]);     // [0] = location of character within string, toupper = changes to uppercase

    // greet the player by entered name
    cout << "Hello " << playerName << "." << endl;

    // user Controlslash to comment out lines.

    // cout << "Hello World!" << endl;     // cout = console out, Endl = end line
    // cout << "Hello World Part 2: Electric Boogaloo" << endl;
    
    return 0;       // end the program

}