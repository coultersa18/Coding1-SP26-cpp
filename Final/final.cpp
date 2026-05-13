

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class turtle {
private:
    string name;
    int stamina;
    int speed;
    int hunger;
    int xp;
    int lvl;
    int maxStamina;
    int distance;
public:
    turtle(string givenName, int givenStamina, int givenSpeed, int givenHunger, int givenXP, int givenLVL, int givenMaxStamina, int givenDistance) {
        name = givenName;
        stamina = givenStamina;
        speed = givenSpeed;
        hunger = 0;
        xp = 0;
        lvl = 0;
        maxStamina = 0;
        distance = givenDistance;
    }

    turtle() {
        name = "Francis";
        cout << "Enter the name for your racing turtle.\n";
        string input;
        getline(cin, input);
        name = input;
        stamina = 100;   //25 - 100
        speed = 25;     // 1-100
        hunger = 1;     // 1-10
        xp = 0;         // 1-100
        lvl = 1;
        maxStamina = 100;
        distance = 0;
    }

    string getName() {
        return name;
    }

    int getStamina() {
        return stamina;
    }

    int getSpeed() {
        return speed;
    }

    int getXP() {
        return xp;
    }

    int getLVL() {
        return lvl;
    }

    int getMaxStamina() {
        return maxStamina;
    }

    int getDistance() {
        return distance;
    }

    int getHunger() {
        return hunger;
    }

    void setName(string givenName)  {
        name = givenName;
    }

    void setStamina(int givenStamina, int givenMaxStamina)   {
        if (givenStamina < 0)
            stamina = 0;
        else if (stamina >= givenMaxStamina)
            stamina = givenMaxStamina;
        else
            stamina = givenStamina;
    }

    void setMaxStamina(int givenMaxStamina){
        maxStamina = givenMaxStamina;
    }

    void setSpeed(int givenSpeed)   {
        if (givenSpeed < 0)
            speed = 0;
        else
            speed = givenSpeed;
    }

    void setHunger(int givenHunger) {
        if (givenHunger < 1)
            hunger = 1;
        else if (givenHunger > 10)
            hunger = 10;
        else
            hunger = givenHunger;
    }

    void setXP(int givenXP) {
        if (givenXP < 0)
            xp = 0;
        else if (givenXP > 100)
            xp = 100;
        else   
            xp = givenXP;
    }

    void setLVL(int givenLVL) {
        if (givenLVL < 0)
            lvl = 0;
        else
            lvl = givenLVL;
    }

    void setDistance(int givenDistance) {
        if (givenDistance < 0)
            distance = 0;
        else
            distance = givenDistance;
    }

    void changeStaminaBy(int amount = 1, int givenMaxStamina = 100) {
        setStamina(stamina += amount, givenMaxStamina);
    }

    void changeMaxStaminaBy(int amount = 1) {
        setMaxStamina(maxStamina += amount);
    }

    void changeSpeedBy(int amount = 1) {
        setSpeed(speed += amount);
    }

    void changeHungerBy(int amount = 1) {
        setHunger(hunger += amount);
    }

    void changeXPBy (int amount = 1) {
        setXP(xp += amount);
    }

    void changeLVLBy (int amount = 1) {
        setLVL(lvl += amount);
    }

    void changeDistanceBy (int amount = 1) {
        setDistance(distance += amount);
    }

};
/*
void battle() {
    //  set random finish line (>50m?)
    //  give player the option to set pace
    //  gallop (d4, -1 Stamina), run (d6, -3 Stamina), sprint (d8, -5 stamina)
    //  Show remaining distance+stamina of player turtle
    //  Show current placings; Display each distance from finish
    //  finishLine -- turtleDistance
    //  if player runs out of stamina, they lose
        //  50% chance for a 'Second Wind'
        //  Roll 1d10; If finish line is crossed, race is finished
        //  Turtle gains Fame based on scoring
            //  Fame converts to XP; 100 per level
            //  4th-15, 3rd-30, 2nd-50, 1st-75
*/

int diceRoll(int sides = 6, int min = 1) {
    return rand() % sides + min;
}

string read(string path, int targetLine) {
    string line;
    int lineCount = 0;
    ifstream readFile(path);

    while(getline(readFile, line)) {
        if (lineCount == targetLine) {
            return line;
        }
        lineCount++;
    }
    return "";
    
    /*
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
    */
    // close file after finished reading
    readFile.close();
}

int main() {
    srand(time(0));
    bool alive = true;
    int points = 10;
    string input;
    int roll;
    int rest;
    bool loopCheck = true;
    int finishLine;
    bool raceFinished = false;
    int placings = 0;
    bool francisFinish = false;
    bool turtle1Finish = false;
    bool turtle2Finish = false;
    bool turtle3Finish = false;
    int turtle1Rank;
    int turtle2Rank;
    int turtle3Rank;
    int francisRank;
    bool cont = true;
    int raceCount = 1;
    string name1;
    string name2;
    string name3;


    while (cont == true) {
        alive = true;
        turtle francis;
        cout << "This is your new racing turtle: \n\n" << francis.getName() << "\n";

        while (alive == true) {
            raceFinished = false;
            placings = 0;
            turtle1Finish = false;
            turtle2Finish = false;
            turtle3Finish = false;
            francisFinish = false;
            loopCheck = true;
            raceCount += 1;
            francis.setDistance(-1);
            cout << "Stamina: " << francis.getStamina() << "/" << francis.getMaxStamina() << "\nSpeed: " << francis.getSpeed() << "\nLevel: " << francis.getLVL() << "\n";

            while (points > 2) {
                cout << "\nYou have " << points << " points left to prepare.\n\n";
                cout << "Train - increases max speed or stamina (4 points)\nRest - Recharges stamina (3 points)\n";
                getline(cin, input);
                if (input == "train" || input == "Train"){
                    if (points >= 4) {
                        if (diceRoll(2) == 1) {
                            roll = diceRoll(4);
                            cout << "\nIncreased " << francis.getName() << "'s speed by: " << roll + francis.getLVL() << "\n\n";
                            francis.changeSpeedBy(roll + francis.getLVL());
                        }
                        else {
                            roll = diceRoll(8);
                            cout << "\nIncreased " << francis.getName() << "'s stamina by: " << roll + francis.getLVL() << "\n\n";
                            francis.changeMaxStaminaBy(roll +  francis.getLVL());
                        }
                        points -= 4;
                    }
                    else
                        cout << "Error: You do not have enough points for this option.\n\n";
                }
                else if (input == "rest" || input == "Rest"){
                    if (points >= 2) {
                        rest = francis.getMaxStamina() / 2;
                        cout << "\nRecovered " << rest << " stamina\n";
                        francis.changeStaminaBy(rest, francis.getMaxStamina());
                        points -= 3;
                    }
                    else
                        cout << "Error: You do not have enough points for this option.\n\n";
                }
                else {
                    cout << "Error: This command was misunderstood.\n\n";
                }
                cout << "\n" << francis.getName() << "\nStamina: " << francis.getStamina() << "/" << francis.getMaxStamina() << "\nSpeed: " << francis.getSpeed() << "\nLevel: " << francis.getLVL() << "\n";
            }
            points = 10;

            // turtle kyle("Kyle", 70, 100, 0, 0, 0, 0);

            // cout << "This is your first foe: " << kyle.getName() << "\n";
            // cout << "Stamina: " << kyle.getStamina() << "\nSpeed: " << kyle.getSpeed() << "\n";
            
            //  Have player start the race(?)
            cout << "\nLet the races begin!\n";
            cout << "\nHere are your opponents for this match.\n";
                //  Generate 3(?) other turtles
            //  vector<string> names = {"Leonardo", "Donatello", "Michelangelo", "Raphael", "Franklin", "Francis", "Verne", "Sheldon", "Shelly", "Tank", "Scooter"};
            //  roll = diceRoll(names.size(), 0);
            name1 = read("turtleNames", diceRoll(10,0));
            while (loopCheck == true) {
                //  roll = diceRoll(names.size(), 0);
                name2 = read("turtlenames", diceRoll(10,0));
                if (name1 == name2)
                    loopCheck = true;
                else
                    loopCheck = false;
            }
            loopCheck = true;
            while (loopCheck == true) {
                //  roll = diceRoll(names.size(), 0);
                name3 = read("turtleNames", diceRoll(10,0));
                if (name1 == name3 && name2 == name3)
                    loopCheck = true;
                else
                    loopCheck = false;
            }
            loopCheck = false;
            
            turtle turtle1(name1, diceRoll(150, 75), diceRoll(75, 20), 0, 0, 0, 0, 0);
            turtle turtle2(name2, diceRoll(150, 75), diceRoll(75, 20), 0, 0, 0, 0, 0);
            turtle turtle3(name3, diceRoll(150, 75), diceRoll(75, 20), 0, 0, 0, 0, 0);

            cout << "Your opponents for this match are: " << turtle1.getName() << ", " << turtle2.getName() << ", and " << turtle3.getName() << "\n\n";
            cout << "Are you ready to start the race? (enter 'yes' when ready)\n";
            while(loopCheck == true) {
                getline(cin, input);
                if (input == "yes") {
                    loopCheck = false;
                }
                else
                    cout << "Error: This command was not recognized\n";
            }
            loopCheck = true;
            finishLine = diceRoll(raceCount * 100, 100);
            cout << "\nThis track's finish line is at " << finishLine << " meters!\n\nGO!\n\n";
            while (raceFinished == false) {
                if (francis.getDistance() < finishLine) {
                    //  Set speed
                    cout << "Enter speed:\n" << "'jog' - 1-4 + speed meters, -10 stamina\n" << "'run' - 3-8 + speed meters, -25 stamina\n" << "'sprint' - 6-12 + speed, -40 stamina\n\n";
                    cout << francis.getName() << "'s remaining stamina is: " << francis.getStamina() << ".\n\n";
                    while(loopCheck == true) {
                        getline(cin, input);
                        if(input == "jog") {
                            roll = diceRoll(4,1);
                            francis.setDistance(roll + francis.getSpeed() + francis.getDistance());
                            francis.changeStaminaBy(-10);
                            loopCheck = false;
                        }
                        else if(input == "run") {
                            roll = diceRoll(8,3);
                            francis.setDistance(roll + francis.getSpeed() + francis.getDistance());
                            francis.changeStaminaBy(-25);
                            loopCheck = false;
                        }
                        else if(input == "sprint") {
                            roll = diceRoll(12,6);
                            francis.setDistance(roll + francis.getSpeed() + francis.getDistance());
                            francis.changeStaminaBy(-40);
                            loopCheck = false;
                        }
                        else
                            cout << "Error: This command was not recognized\n";
                    }
                    cout << "\n" << francis.getName() << " moved " << roll + francis.getSpeed() << " meters!\n";
                    loopCheck = true;
                    
                    if (turtle1Finish == false) {
                        roll = diceRoll(3,1);
                        if (roll == 1) {
                            roll = diceRoll(4,1);
                            turtle1.setDistance(roll + turtle1.getSpeed() + turtle1.getDistance());
                            turtle1.changeStaminaBy(-15);
                        }
                        else if (roll == 2) {
                            roll = diceRoll(8,3);
                            turtle1.setDistance(roll + turtle1.getSpeed() + turtle1.getDistance());
                            turtle1.changeStaminaBy(-25);
                        }
                        else {
                            roll = diceRoll(12,6);
                            turtle1.setDistance(roll + turtle1.getSpeed() + turtle1.getDistance());
                            turtle1.changeStaminaBy(-40);
                        }
                        cout << turtle1.getName() << " moved " << roll + turtle1.getSpeed() << " meters!\n";
                    }

                    if (turtle2Finish == false) {
                        roll = diceRoll(3,1);

                        if (roll == 1) {
                            roll = diceRoll(4,1);
                            turtle2.setDistance(roll + turtle2.getSpeed() + turtle2.getDistance());
                            turtle2.changeStaminaBy(-15);
                        }
                        else if (roll == 2) {
                            roll = diceRoll(8,3);
                            turtle2.setDistance(roll + turtle2.getSpeed() + turtle2.getDistance());
                            turtle2.changeStaminaBy(-25);
                        }
                        else {
                            roll = diceRoll(12,6);
                            turtle2.setDistance(roll + turtle2.getSpeed() + turtle2.getDistance());
                            turtle2.changeStaminaBy(-40);
                        }
                        cout << turtle2.getName() << " moved " << roll + turtle2.getSpeed() << " meters!\n";
                    }

                    if (turtle3Finish == false) {
                        roll = diceRoll(3,1);

                        if (roll == 1) {
                            roll = diceRoll(4,1);
                            turtle3.setDistance(roll + turtle3.getSpeed() + turtle3.getDistance());
                            turtle3.changeStaminaBy(-15);
                        }
                        else if (roll == 2) {
                            roll = diceRoll(8,3);
                            turtle3.setDistance(roll + turtle3.getSpeed() + turtle3.getDistance());
                            turtle3.changeStaminaBy(-25);
                        }
                        else {
                            roll = diceRoll(12,6);
                            turtle3.setDistance(roll + turtle3.getSpeed() + turtle3.getDistance());
                            turtle3.changeStaminaBy(-40);
                        }
                        cout << turtle3.getName() << " moved " << roll + turtle3.getSpeed() << " meters!\n";
                    }
                }

                if (francis.getStamina() <= 0 && francis.getDistance() < finishLine) {
                    cout << "\n" << francis.getName() << " is on the brink of collapse!\nWith their final breath ";
                    if (diceRoll(3,1) == 1) {
                        roll = diceRoll(12,6);
                        francis.setDistance(roll + francis.getSpeed() + francis.getDistance());
                        cout << francis.getName() << " gains a burst of energy and...\n";
                        if (francis.getDistance() >= finishLine) {
                            francis.setStamina(1, francis.getMaxStamina());
                            cout << "Pushes past the finish line!\n\n";
                        }
                        else {
                            cout << "Collapses in exhaustion...\n\n";
                            cout << "New Game? 'yes'/'no'\n";
                            getline(cin, input);
                            if (input == "yes") 
                                cont = true;
                            else
                                break;
                            alive = false;
                            francisFinish = true;
                        }
                    }
                    else {
                        cout << francis.getName() << " collapses in exhaustion...\n\n";
                        cout << "New Game? 'yes'/'no'\n";
                        getline(cin, input);
                        if (input == "yes") 
                            cont = true;
                        else
                            cont = false;
                        alive = false;
                        francisFinish = true;
                    }
                }
                cout << "\nThe current rankings are:\n";
                if (francis.getDistance() >= finishLine) {
                    placings += 1;
                    francisRank = placings;
                    cout << francis.getName() << " has finished in " << "rank #" << placings << "!\n";
                    francisFinish = true;
                }
                else if (francis.getStamina() > 0) {
                    cout << francis.getName() << " - " << francis.getDistance() << " / " << finishLine << " meters\n";
                }
                
                if (turtle1.getStamina() <= 0) {
                    cout << turtle1.getName() << " - DNF\n";
                    turtle1Finish = true;
                }
                else if (turtle1Finish == true) {
                    cout << turtle1.getName() << " has finished in " << "rank #" << turtle1Rank << "!\n";

                }
                else if (turtle1.getDistance() >= finishLine && turtle1Finish != true) {
                    placings += 1;
                    turtle1Rank = placings;
                    cout << turtle1.getName() << " has finished in " << "rank #" << turtle1Rank << "!\n";
                    turtle1Finish = true;
                }
                else if (turtle1.getStamina() > 0) {
                    cout << turtle1.getName() << " - " << turtle1.getDistance() << " / " << finishLine << " meters\n";
                }
                if (turtle2.getStamina() <= 0) {
                    cout << turtle2.getName() << " - DNF\n";
                    turtle2Finish = true;
                }
                else if (turtle2Finish == true) {
                    cout << turtle2.getName() << " has finished in " << "rank #" << turtle2Rank << "!\n";

                }
                else if (turtle2.getDistance() >= finishLine && turtle2Finish != true) {
                    placings += 1;
                    turtle2Rank = placings;
                    cout << turtle2.getName() << " has finished in " << "rank #" << turtle2Rank << "!\n";
                    turtle2Finish = true;
                }
                else if (turtle2.getStamina() > 0) {
                    cout << turtle2.getName() << " - " << turtle2.getDistance() << " / " << finishLine << " meters\n";
                }
                if (turtle3.getStamina() <= 0) {
                    cout << turtle3.getName() << " - DNF\n\n";
                    turtle3Finish = true;
                }
                else if (turtle3Finish == true) {
                    cout << turtle3.getName() << " has finished in " << "rank #" << turtle3Rank << "!\n\n";

                }
                else if (turtle3.getDistance() >= finishLine && turtle3Finish != true) {
                    placings += 1;
                    turtle3Rank = placings;
                    cout << turtle3.getName() << " has finished in " << "rank #" << turtle3Rank << "!\n\n";
                    turtle3Finish = true;
                }
                else if (turtle3.getStamina() > 0) {
                    cout << turtle3.getName() << " - " << turtle3.getDistance() << " / " << finishLine << " meters\n\n";
                }

                if (francisFinish == true) {
                    raceFinished = true;
                }
                else if (francisFinish == true && turtle1Finish == true && turtle2Finish == true && turtle3Finish == true) {
                    raceFinished = true;
                }
                
            }
            if (francisRank == 1) {
                francis.changeXPBy(75);
            }
            else if (francisRank == 2) {
                francis.changeXPBy(50);
            }
            else if (francisRank == 3) {
                francis.changeXPBy(25);
            }
            else if (francisRank == 4) {
                francis.changeXPBy(10);
            }

            if (francis.getXP() >= 100) {
                francis.changeXPBy(-100);
                francis.changeLVLBy(1);
                cout << francis.getName() << " has leveled up to level " << francis.getLVL() << "!\n\n";
            }

        }

    }
    return 0;
}