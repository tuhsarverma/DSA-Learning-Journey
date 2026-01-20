#include <iostream>
using namespace std;
//function overloading 
class A{
    public:
    void sayhello(){
        cout<<" hello ";
    }
    void sayhello(string name){
        cout<<"HELLO"<<name;
    }
    int sayhello(string name,int n){
        cout<<"HELLO"<<name;
        cout<< n;
    }
};
//operator overloading
class B{
    public:
    int a,b;
    void operator+ (B &obj){
        int value1=this->a;
        int value2=obj.b;
        cout<<" the output will be  "<< value2-value1<<endl;
    }
    void operator() (){  // hurray brakcet() overloaded
        cout<<" Here the bracket function is called and the value is  "<<  this->a;
    }
};
int main(){
    B obj1,obj2;
    A obj;
    obj.sayhello("tushar",9);
    obj1.a=4,obj1.b=6,obj2.a=9,obj2.b=10;
    obj1+obj2;
    obj1();
    
    return 0;
}