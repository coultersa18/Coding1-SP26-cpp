//  Sean Coulter    Coding 1 Week 13
// Functions

#include <iostream>
#include <string>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <vector>   

using namespace std;

void sayHello() {
    cout << "Hello!\n";
}

void doAddition(int firstNum = 2, int secondNum = 2) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Our total is " << firstNum + secondNum << ".\n";
}

int diceRoll(int sides = 6, int min = 1) {
    return rand() % sides + min;
}

bool askYesNo(string question = "Do you want to keep playing?") {
    while(true) {
        cout << "\n" << question << " ('yes'/'no')\n";
        string input;
        getline (cin, input);

        if(input == "yes") {
            return true;
        }
        else if(input == "no") {
            return false;
        }
        else {
            cout << "\nPlease type ('yes'/'no')\n";
        }
    }
}

//  variable scope
//  global variables
//  passing by reference

void showVec(vector<string>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

//  Create a referecne with an '&' next to the variable type
//  int& number; string& name;

// references let us edit the original.
void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    string input;
    getline(cin, input);

    vec.push_back(input);

    // showVec(vec);       // The added name exists here
}

int main() {
    srand(time(0));     //seed the random number generator
    vector<string> names = {"Finn", "Jake", "Marceline", "BMO", "PB"};

    showVec(names);

    addStringToVec(names);

    showVec(names);

    cout << "Finally, functions!\n";

    sayHello();

    doAddition(14,3);

    cout << "Let's roll the dice! Our first number is " << diceRoll(6) << ".\n";

    doAddition(diceRoll(20), diceRoll(20));
    doAddition(diceRoll(), diceRoll(20));

    if(askYesNo()) {
        cout << "Let's start the next level!\n";
    }
    else {
        cout <<  "\nThanks for playing!\n";
        return 0;
    }

    if(askYesNo("Do you like watermelons?")) {
        cout << "They're really good!\n";
    }
    else {
        cout <<  "\nThey're not that good anyways.\n";
    }

    return 0;
}