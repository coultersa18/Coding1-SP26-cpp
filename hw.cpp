// include bits
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> games = {"Cyberpunk 2077", "Balatro", "Risk of Rain 2"};

    string input;
    vector<string>::iterator iter;
    do {
        cout << "\nYour list of favorite games is currently: \n";
        
        for (int i = 0; i < games.size(); i++) {
            cout << i + 1 << ". " << games[i] << "\n";
        }

        cout << "\nWhat would you like to do? ('add', 'change', 'remove', 'show all', 'quit')\n";
        getline(cin, input);

//  Add a game to the list
        //  if player's input = 'add'
        if (input == "add") {
            bool addLoop = true;
            cout << "\nWhat would you like to add?\n";
            getline(cin, input);

            //  Vector.push_back() adds input to list
            games.push_back(input);

            cout << input << " has been added.\n";
        }

//  Edit a game on the list
        // if player's input = 'change'
        else if (input == "change") {
            //  ask what name they want to select
            cout << "\nWhat game would you like to change?\n";
            getline(cin, input);
            //  find their input
            iter = games.begin();

            iter = find(games.begin(), games.end(), input);

            if(iter != games.end()) {
                cout << "Are you sure you want to change " << *iter << "? ('yes', 'no')\n";
                getline(cin, input);
                
                if (input == "yes") {
                    cout << "What do you want to change " << *iter << " to?\n";
                    getline(cin, input);

                    *iter = input;
                }
            }
            //  ask what they want to change input to
            //  use *iter = input to change item
        }
//  Remove a game from the list
        else if (input == "remove") {

            //  if player's input = 'remove'
            cout << "\nWhat game would you like to remove?\n";
            getline(cin, input);

            iter = games.begin();

            iter = find(games.begin(), games.end(), input);

            int index = distance(games.begin(), iter);

            if(iter != games.end()) {
                cout << "\nAre you sure you want to remove " << *iter << "? ('yes', 'no')\n";
                getline(cin, input);

                if (input == "yes") {
                    cout << *iter << " has been removed.\n";
                    games.erase(games.begin() + index);
                }
            }

            //  ask player which item they want to remove
            //  if input is on the list
                //  move item to end of the list
                //  use vector.pop_back(); to remove item from list
            //  if players input is wrong, tell them to re-enter
        }
        //  Show all games (sorted)
        else if (input == "show all") {
            sort(games.begin(), games.end());
        }
        //  if player's input = 'show all'
            //  use sort() to sort list
            //  display list
        else if (input == "quit") {
            cout << "\nThank you.\n";
            break;
        }

        else {
            cout << "\nThis command was not recognized.\n";
        }
    } while (true);

    return 0;
}
