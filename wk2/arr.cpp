// Sean Coulter
//  Arrays, Loops, and Vectors

#include <iostream>
#include <string>
#include <cstdlib> // for rand and srand
#include <ctime>    // for srand(time(0))
using namespace std;

int main() {
    srand(time(0));

    cout << "Let's learn about arrays!\n";

    // arrays in C++ have a defined size.
    // arrays don't have a way to count how many things are in them.

    cout << "Creating an array of high scores.\n";

    //declaring a new integer array witha  size of 5
    int highScores [5];

    highScores[0] = 4550;   // the first high score is at index 0
    highScores[1] = 2215;
    highScores[4] = 11;

    cout << "The first score is " << highScores[0] << ".\n";

    cout << "here are all of the high scores:\n";

    int index = 0;
    while(index < 5) {
        cout << highScores[index] << "\n";
        index++;
    }

    cout << "Let's learn about for loops to show the scores again.\n";

    // for (intializatiion; test; action)
    // for (create the variable; how long do we loop for; how are we counting)
    for(int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << highScores[i] << "\n";
    }

    // lets create a list of names and let the user choose the names
    string names [10];
    string input;
    index = 0;

    while(index < 10) {
        cout << "What name would you like to add, or type 'done' to stop.";
        cin >> input;

        if (input == "done") {
            cout << "We are done entering names.\n";
            break;
        }

        names[index++] = input;

    }

    cout << "Here are your names:\n";
    for (int i = 0; i < 10; i++) {
        if (names[i] == "") {
            continue;
        }
        cout << i+1 << ". " << names[i] << "\n";
    }

    // pick a random name and save it
    // use a switch statement to pick one random response

    string name = names[rand() % index];

    cout << "Let's talk about " << name << ".\n";

    switch(rand() % 4) {
        case 0:
            cout << "I love " << name << ".\n";
            break;
        case 1:
            cout << "I like " << name << ".\n";
            break;
        case 2:
            cout << "I don't like " << name << ".\n";
            break;
        case 3:
            cout << "I loathe " << name << ".\n";
            break;
            
    }
    return 0;
}