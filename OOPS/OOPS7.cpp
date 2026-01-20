// RUNTIME OR DYNAMIC POLYMORPHISM
#include <iostream>
using namespace std;
class schoolname{
    public:
    void name(){
        cout<<" NAME IS : TUSHAR VERMA"<<endl;
    }
    void zone(){
        cout<<" disclipined"<<endl;
    }
};
class homename : public schoolname{
    public:
    void name(){
        cout<<" NAME IS : CHOTU"<<endl;
    }
};
int main(){
    homename obj1;
    obj1.name();
    obj1.zone();





    return 0;
}