//  Sean Coulter coding 1b week 4
//  Writing to a reading from files

#include <string>
#include <iostream>
#include <vector>
#include <fstream>  //  File Stream

using namespace std;

void read(string path = "save.txt") {
    string line;
    ifstream readFile(path);  //  create a new var, and try to open a file
    if (readFile.is_open()) {
        cout << "File is open.\n\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }
    
    // close file after finished reading
    readFile.close();
}

//  overloaded function name
void read(vector<string>& vec, string path = "save.txt") {
    string line;
    ifstream readFile(path);
    if (readFile.is_open()) {
        cout << "File is open.\n\n";
        while(getline(readFile, line)) {
            vec.push_back(line);    // Add each line to the vector
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }
    
    // close file after finished reading
    readFile.close();
}

void write(vector<string>&vec, string path = "save.txt") {
    ofstream writeFile(path);
    if(writeFile.is_open()) {
        for(int i= 0; i < vec.size(); i++) {
            writeFile << vec[i] << endl;
        }
    }
    else {
        cout << "couldn't open new writeFile.\n";
    }
    writeFile.close();
}

int main() {
    cout << "Let's write to a file!\n";
    vector<string> faves;
    string input = "wt3";

    string path = "save.txt";

    cout << "What file would you like to open?\nEnter 'no' to use default.\n";
    getline(cin, input);
    if (input != "no") {
        path = input;
    }


    read(path); // show current names
    read(faves, path);    // add names to the vector

    cout << "\nWhat would you like to add?\n";
    cout << "Enter an empty line to stop\n";

    while(input != "") {
        cout << "> ";
        getline(cin, input);
        if (input == "") {
            break;  // stop before "" is added to vector
        }
        //  send to file
        //  writeFile << input << endl;
        faves.push_back(input);
    }

    //  call the write function and send it the faves vector
    write(faves, path);

    return 0;
}
