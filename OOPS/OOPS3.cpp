#include <iostream>

using namespace std;
#include <cstring>

#pragma pack(1) // TO TURN OFF PADDING
class hero {
    private: int health;
    public: char * name;
    hero() {
        cout << "deafault constructor";
        name = new char[100];
    }

    char name1;

    //PARAMETERISED CONSTRUCTOR
    hero(int health) {
        this -> health = health;
        cout << "this->  " << this << endl;
        name = new char[100];
    }

    hero(int health, char name) {
        this -> health = health;

        this -> name1 = name;

        this -> name = new char[100]; // FIXED
        this -> name[0] = name;
        this -> name[1] = '\0';
    }

    hero(hero & temp) { // COPY CONSTRUCTOR
        cout << "COPY CONSTRUCTOR CALLED " << endl;
        this -> health = temp.health;

        this -> name = new char[100];
        strcpy(this -> name, temp.name);
    }

    int gethealth() {
        return health;
    }

    void sethealth(int a) {
        health = a;
    }

    char getname1() {
        return name1;
    }

    void sethealth(char a) {
        health = a;
    }

    void print() {
        cout << "health  " << health << "  name " << name << endl;
    }

    void setname(char name1[100]) {
        strcpy(this -> name, name1);
    }
};

int main() {
    hero suresh(90, 'T');
    hero ritesh(suresh); //COPYING SURESH IN RITESH
    suresh.print();
    cout << endl;
    char newname[7] = "tushar";
    suresh.setname(newname);
    ritesh.print();

    hero TUSHAR(suresh);
    cout << "PRINTING THE TUSHAR" << endl;
    suresh.name[0] = 'B';
    TUSHAR.print();
    suresh.print();

    return 0;
}