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
            arr[++top]=element;
        }
        else{
            cout<<" stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<" stack underflow"<<endl;
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
    bool isempty(){
        if(top<0){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    stack st(5);
    st.push(4);
    st.push(4);
    st.push(2); 
    st.push(2);
    st.push(8);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    return 0;
}





