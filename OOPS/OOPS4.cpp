// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class student{
    private:
    string name;
    int age,height;
    public:
    void setname(string naam){
        this->name=naam;
    }
    string getname(){
        return this->name;
    }
    int marks;
    int getage(){
        return this->age;
    }
};
class tushar : public student{
    public:
 
    void setmarks(int m){
        this->marks=m;
    }
    int getmarks(){
        return this->marks;
    }
};
class varun: public tushar{
    public:
    void present(){
        cout<<"present sir"<<endl;
    }
};
class new1{
    public:
    void absent(){
        cout<<"absent sir"<<endl;
    }
};
class new2 :public varun, public new1{
    
};
int main() {
    int M1;
    cout<<"enter ur marks";
    cin>>M1;
    tushar object1;
    object1.setmarks(M1);
    cout<<" u set the marks   "<<object1.getmarks()<<endl;// protected but opened in private so it need a fncn to access it//
    object1.setname("IRONMAN");//private member inherited through fncn made inside the parent class..
    cout<<object1.getname()<<endl;
    student B1;
    B1.setname("CAPTAIN");
    cout<<B1.getname()<<endl;// private member inherited through fncn made inside the parent class..
    //MULTI INHERITANCE
    varun object2;
    object2.setmarks(90);
    cout<<object2.getmarks();
    //MULTIPLE INHERITANCE
    new2 NEWOBJ;
    NEWOBJ.absent();
    NEWOBJ.present();
    return 0;
}