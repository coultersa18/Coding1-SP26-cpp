// Sean Coulter Coding 1 Spring 2026   
// Variables and logic

// compile with the Developer Command Prompt
// 'cl /EHsc main.cpp' is what you type to compile
// 'main' or 'main.exe' ro run the program

#include <iostream>
using namespace std;
int main() {
    cout << "Let's learn about variables and logic!\n";

    // declaring and defining variables
    int playerAge = -1;
    string playerName = "john doe";
    float happinessPercent = 0.61f;
    bool keepPlaying = true;

    // just like a branch in unreal engine
    // if_the test is true) run this code.
    if(playerAge == -1){
        cout << "How old are you?\n";
        cin >> playerAge;

        if(playerAge <= 12){
            cout << "You're too young.\n";
            return 0;
        }
        else{
            cout << "Congratulations on reaching " << playerAge << "!\n";

        }
    } //end of if playerAge

    if(playerName == "john doe"){
        cout << "is your name " << playerName << "?\n";
        string input;
        cin >> input;
        // the OR operator '||'
        if (input == "yes" || input == "Yes" || input == "YES"){
            cout << "Well that's convenient!\n";
        }
        else{
            cout <<"What is your name?\n";
            cin >> playerName;
        }

        cout << "Hello, " << playerName << ".\n";
    }

    bool debug = false;
    if(playerAge == 21 && playerName == "Sean"){
        debug = true;
        cout << "Hello Sean, debug mode is on.\n";
    }

    if(debug){
        cout << "\n\tDEBUG MODE\n\n";
        cout << "playerAge = " << playerAge << ".\n";
        cout << "playerName = " << playerName << ".\n";
        cout << "happinessPercent = " << happinessPercent << ".\n";
        cout << "keepPlaying = " << keepPlaying << ".\n";
    }

    return 0;

} // end of main()