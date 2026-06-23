#include <iostream>
using namespace std;
#include <queue>
int main(){
    queue<int> q;
    cout<<" size = "<<q.size();
    q.push(33);
    cout<<" back "<<q.back()<<endl;
    q.push(12);
    q.push(87);
    q.push(55);
    cout<<" front "<<q.front()<<endl;
    cout<<" back "<<q.back()<<endl;
    q.pop();
    cout<<"front "<<q.front()<<endl;
    cout<<q.empty();
}