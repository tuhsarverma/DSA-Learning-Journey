#include <iostream>
#include <string>
using namespace std;
// class stack{
//     public:
//     int* arr;
//     int top;
//     int size;
//     stack(int size){
//         this->size=size;
//         arr=new int[size];
//         top=-1;
//     }
//     void push(int element){
//         if(size-top>1){
//             top++;
//             arr[top]=element;
//         }
//         else{
//             cout<<" stack overflow";
//         }
//     }
//     int pop(){
//         if(top>=0){
//             int ans=arr[top];
//             top--;
//             return ans;
//         }
//         else{
//             cout<<" stack undereflow";
//             return -1;
//         }
//     }
//     int peek(){
//         if(top >= 0){
//             return arr[top];
//         }
//         else{
//             cout << "stack is empty";
//             return -1;
//         }
//     }
//     bool isempty(){
//         if(top<0){
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
// };


// // 5TH QUESTION
// //  REVERSE STACK USING RECUSION
// void insertatbottom(stack &mystack,int x){
//      int size = mystack.top + 1;
//     int n = 0;

//     stack s(mystack.size);

//     while(n < size){
//         s.push(mystack.peek());
//         mystack.pop();
//         n++;
//     }

//     n = 0;
//     mystack.push(x);

//     while(n < size){
//         mystack.push(s.peek());
//         s.pop();
//         n++;
//     }
// }
// void reversestack(stack &mystack){
//     if(mystack.isempty()){
//         return;
//     }
//     int num=mystack.peek();
//     mystack.pop();
//     //  recursive call
//     reversestack(mystack);
//     insertatbottom(mystack,num);

// }


// // Q-5   SORT  THE STACK WITHOUT LOOP

// void sortstack(stack<int> &stack){


// if(stack.empty()){
//     return;
// }
// int num=stack.top();
// stack.pop();
// sortstack(stack);
// insertatbottom(num);
// }
// // SORT THE STACK WITH LOOP
// void sortedinsert(stack<int> &s,int num){
//     if(s.empty()||(!s.empty()&&s.top()<num)){
//         s.push(num);
//         return;

//     }
//     int n=stack.top();
//     stack.pop();
//     sortedstack(s,num);
//     s.push(n);

// }
// void sortstack1(stack<int> &stack){
//     if(stack.empty()){
//         return ;
//     }
//     int num=stack.top();
//     stack.pop();
//     sortstack1(stack);
//     sortedinsert(stack,num);
// }
// // Q7 the viscosity during the watethe oi ej a a ans as well as the ritesh pandeu the falling  the way for the human psychology of futuring 
// bool redundantbracket(string &s){
//     stack<char> st;
//     for(int i=0;i<s.length();i++){
//         char ch=s[i];
//         if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'){
//             st.push(ch);
//         }
//         // I will do my best. I will do my best linene
//         else{
//             if(ch==')'){
//                 bool isredundant=true;
//                 while(st.top()!='('){
//                     char top=st.top();
//                     if(top=='+'||top=='-'||top=='*'||top=='/'){
//                         isredundant=false;
//                     }
//                     st.pop();
//                 }
//                 if(isredundant==true){
//                     return true;
//                     st.pop();
//                 }
//             }
//         }
//     }
    
// }
// Q8 FINDMINCOST
thekko999
int findmincost(string str){
    if(str.length()%2!=0){
        return -1;
    }         
    int cnt=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='{') cnt++;
        else cnt--;
    }
    if(cnt<0){
    // the final physical  things is that to get very appreciatons in  your college with lots of congratulations in the fredddom of nature along with tha hjan h
        cnt*=-1;
    }
    int m=cnt/2;
    return m;
}
int main(){
    cout<<findmincost("{{{}");
    return 0;
}