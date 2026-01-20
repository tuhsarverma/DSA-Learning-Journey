#include <iostream>
using namespace std;
//HIERACHICAL INHERITANCE 
class one{
    public:
    void  answer1(){
        cout<<" first one"<<endl;
    }
    
};
class nine{
    public:
    void answer1(){
        cout<<" nine hai ye"<<endl;
    }
};
class two:public one{
    public:
    void answer2(){
        cout<<"second one"<<endl;
    }
};
class three : public one{
    public:
    void answer3(){
        cout<<" third one"<<endl;
    }
};
class four:public one,public nine{

};
int main(){
    one object1;
    two object2;
    three object3;
    object1.answer1();
    object2.answer1();
    object2.answer2();
    four obj;
    obj.one::answer1();/* INHERITANCE AMBIGUITY*/ 
    obj.nine::answer1();
    
    return 0;
}