//  self documaneting code means the code can only do ONE thing, or be used ONE way.

#include <iostream>
#include <string>
using namespace std;

//  classes are custom variable types
//  variables 
//  functions

//  constructors
//  getters + setters (privacy)

class robot {
private:
    string name;
    int charge;
    int boredom;

public:
    //  constructor sets up the class with input variables
    //  doesn't have a return type
    //  must be named same as class
    robot(string givenName, int givenCharge, int givenBoredom) {
        name = givenName;
        charge = givenCharge;
        boredom = givenBoredom;
        status();
    }

    robot() {
        name = "Robot";
        charge = 10;
        boredom = 10;
        status();
    }

    void status() {
        cout << "Hello, my name is " << name;
        cout << " and my charge is " << charge << ".\n";
        cout << "I am ";

        if (boredom < 5) cout << "happy";
        else if (boredom < 10) cout << "bored";
        else if (boredom < 15) cout << "frustrated";
        else cout << "ENRAGED";

        cout << ".\n";
    }

    //  Getters
    string getName() {
        return name;
    }

    int getCharge() {
        return charge;
    }

    int getBoredom() {
        return boredom;
    }

    void setName(string givenName) {
        if (givenName.size() <= 5) 
            name = givenName;
        else 
            cout << "error: " << givenName << " Name is too long.\n";
    }

    void setCharge(int givenCharge) {
        //  clamp charge to between 0 and 100
        if (givenCharge < 0) 
            charge = 0;
        else if (givenCharge > 100) 
            charge = 100;
        else 
            charge = givenCharge;
    }

    void setBoredom(int givenBoredom) {
        if(givenBoredom > 20)
            boredom = 20;
        boredom = givenBoredom;
    }

    void changeChargeBy(int amount = 1) {
        setCharge(charge += amount);
    }

};  //  end of robot class

int main()  {
    cout << "classes\n";

    //  create first instance of a robot
    robot artoo("R2-D2", 45, 3);
    //  artoo.name = "R2-D2";   //  dot syntax from large to small
    //  artoo.charge = 45;      //  like an address
    //  artoo.boredom = 3;
    cout << "Artoo has '" << artoo.getName() << "' characters in their name\n";

    robot threepio;
    threepio.setName("C-3PO");  //  Using the setter
    threepio.setCharge(2);
    threepio.setBoredom(12);

    artoo.status();
    threepio.status();

    cout << "Threeopio has low battery, let's have artoo charge him up!\n";

    while(threepio.getCharge() < 60 && artoo.getCharge() >0) {
        artoo.changeChargeBy(-1);
        threepio.changeChargeBy();
        if (artoo.getCharge() == 0)
            cout << "Artoo is out of energy.\n";
    }

    artoo.status();
    threepio.status();

    return 0;
}