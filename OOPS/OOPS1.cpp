.cpp#include <iostream>
using namespace std;

#pragma pack(1)   // TO TURN OFF PADDING
class hero {
public:
    int health;
    char name;
    hero(){
        cout<<"constructor called"<<endl;
    }
};

#pragma pack()    // TO TURN ON PADDING
class K {
public:
    int health;
private:
    char name;
    void print() {
        cout << "YE" << name;
    }
};

class A {   // Empty class
};

int main() {
    hero h1;

    cout << sizeof(h1) << endl;
    cout << sizeof(hero) << endl;

    cout << sizeof(char) << endl;

    cout << "SEE DIFF IN SIZE" << endl;

    cout << sizeof(K) << endl;

    cout << "size of empty class " << sizeof(A) << endl;

    cout << endl << h1.health <<endl<< h1.name<<endl;
    hero *b =new hero;
    //DYNAMICALLY
    cout<<endl<<(*b).health<<endl;
    cout<<(*b).name<<endl;
    //OR WE CAN DO BY ->
    cout<<endl<<b->health<<endl;
    cout<<b->name<<endl; 
    cout<<"HII"<<endl;
    hero ramesh;//STAT
    cout<<endl <<"HELLO";
    return 0;
}
