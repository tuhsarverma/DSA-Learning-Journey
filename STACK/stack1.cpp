#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(3);
    s.push(5);

    cout<<" the top element is  "<<s.top();
    s.pop();
    cout<<endl<<"THE TOP ELEMENT IS  "<<s.top()<<endl;
    if(s.empty()){
        cout<<" Stack is empty"<<endl;
    }
    else {
        cout<<" stack is not empty"<<endl;
    }
    cout<<" the size of stack is "<<s.size();
    return 0;
}