#include <iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int top;
    int size;
    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<" stack overflow";
        }
    }
    int pop(){
        if(top>=0){
            int ans=arr[top];
            top--;
            return ans;
        }
        else{
            cout<<" stack underflow";
        }
    }
    int peek(){
        if(top>=0&&top<size){
            return arr[top];
        }
        else{
            cout<<" stack is empty";
            return -1;
        }
    }
};
int main(){
    string s;
    cin>>s;
    int size=s.size();
    stack st[size];
    int i=0;
    while(i<size){
        top++;
        st[top]=s[i++];
    }
    i=0;
    while(i<size){
        int val=st.pop();
        s[i]=val;
        i++;
    }
    return 0;
}