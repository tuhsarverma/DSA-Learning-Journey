#include <iostream>
#include <string>
using namespace std;
class stack1{
    int *arr;
    int top;
    int size;
    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void  push(int element){
        if(top<size-1){
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
            return -1;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<" stack is underflow";
            return -1;
        }
    }
    bool isempty(){
        if(top>=0){
            return true;
        }
        else{
            return false;
        }
    }
};
class Stack{
public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(top < size - 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "stack overflow";
        }
    }
    
    int pop(){
        if(top >= 0){
            int ans = arr[top];
            top--;
            return ans;
        }
        else{
            cout << "stack underflow";
            return -1;
        }
    
    }
    int peek(){
        if(top >= 0)
        }
        else{
            cout << "stack is empty";
            return -1;
        }
    }

    bool empty(){
        return top < 0;
    }
};

// void solve(Stack& inputstack,int count,int size){
//     if(count==size/2){
//         inputstack.pop();
//         return;
//     }
//     int num=inputstack.peek();
//     inputstack.pop();
//
//     solve(inputstack,count+1,size);
//
//     inputstack.push(num);
// }
//
// void deletemiddle(Stack& inputstack,int N){
//     int count=0;
//     solve(inputstack,count,N);
// }

// 3RD QUESTION (VALID PARENTHESIS)

bool matches(char top,char ch){
    if((ch==')' && top=='(') ||
       (ch==']' && top=='[') ||
       (ch=='}' && top=='{')){
        return true;
    }
    else{
        return false;
    }
}

bool isvalidparenthesis(string expression){
    Stack s(expression.length());

    for(int i=0;i<expression.length();i++){
        char ch=expression[i];

        if(ch=='{' || ch=='(' || ch=='['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top=s.peek();

                if(matches(top,ch)){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

// 4TH
// INSERET AN ELEMENT AT ITS BOTTOM IN A GIVEN STACK

void insertatbottom(Stack& mystack,int x){
    int size = mystack.top + 1;
    int n = 0;

    Stack s(mystack.size);

    while(n < size){
        s.push(mystack.peek());
        mystack.pop();
        n++;
    }

    n = 0;
    mystack.push(x);

    while(n < size){
        mystack.push(s.peek());
        s.pop();
        n++;
    }
}

// OR 2 METHODS HAI
// 4TH QUESTION

void insertAtBottom(Stack& st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }

    int temp = st.peek();
    st.pop();

    insertAtBottom(st,x);

    st.push(temp);
}

int main(){

}