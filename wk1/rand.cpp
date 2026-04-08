// Sean Coulter Coding 1 Spring 2026
// Random Numbers, Switch statements & While Loops

// fill out the rest of the code so that it displays the words "Random Numbers" to the console
// then run it.

#include <iostream>
#include <cstdlib>  // for srand and rand
#include <ctime>    // for time

using namespace std;

int main() {
    // only once, at the beginning of the program
    // seed the random number generator
    srand(time(0));

    cout << "Random numbers\n";

    cout << "Here is the first random number: " << rand() << " \n";

    int counter = 0;
    while(counter++ < 10) {
        int number = rand();
        int min = 50;
        int max = 100;
        int range = max - min;
        int clampedNumber = (number % range) + min;

        cout << clampedNumber << endl;
    }

    int randomRange = (rand() % 11) + 10;
    int number = (rand() % randomRange) + 1;
    int guess = -1;
    int totalGuesses = 0;
    cout << "I'm thinking of a number between 1 and " << randomRange << ", what is it?\n>>";


    while(true) {
        cin >> guess;
        totalGuesses++;
        if (guess > number) {
            cout << "Too high!\n";
        }
        else if (guess < number) {
            cout << "Too low!\n";
        }
        if(guess == number) {
            cout << "You guessed correctly!\n";
            cout << "It took you " << totalGuesses << " guesses!\n";
            break;
        }
    }

    return 0;
}