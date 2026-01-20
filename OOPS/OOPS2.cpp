#include <iostream>
using namespace std;

#pragma pack(1)   // TO TURN OFF PADDING
class hero {
public:
    int health;
    char name;
    //PARAMETERISED CONSTRUCTOR
    hero(int health){
        this-> health=health;
        cout<<"this->  "<<this<<endl;
    }
    int gethealth(){
        return health;
    }
    void sethealth(int  a){
        health=a;
    }
    char getname(){
        return name;
    }
    void sethealth(char a){
        health=a;
    
    }
    void print(){
        cout<<health;
    }
};
class zero {
public:
    int health;
    char name;
    //PARAMETERISED CONSTRUCTOR
    zero(int health,char name){
        this-> health=health;
        this-> name=name;
        cout<<"this->  "<<this<<endl;
    }
    int gethealth(){
        return health;
    }
    void sethealth(int  a){
        health=a;
    }
    char getname(){
        return name;
    }
    void setname(char a){
        name=a;
    }
    void print(){
        cout<<name;
    }
};

int main() {
    //STATICALLY
    hero ramesh(10);
    cout<<"adress of ramesh is : "<< &ramesh<<endl;
    ramesh.gethealth();
    //DYANMICALLY
    hero *h=new hero(11);
    zero A1(22,'a');
    ramesh.print();
    cout<<"   ";
    (*h).print();
    cout<<"   ";
    A1.print();
    return 0;
}
