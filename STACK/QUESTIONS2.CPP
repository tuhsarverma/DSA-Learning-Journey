#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <cmath>
#include <climits>
// class stack{
//     int* arr;
//     int size;
//     int top;
//     stack (int size){
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
//             cout<<" stack overflow"<<endl;
//         }
//     }
//     void pop(){
//         if(top>=0){
//             top--;
//         }
//         else{
//             cout<<" stack underflow"<<endl;
//         }
//     }
//     int peek(){
//         if(top>=0&&top<size){
//             return arr[top];
//         }
//         else{
//             cout<<" stack is empyt"<<endl;
//             return -1;
//        }
//     }
//     bool isempty(){
//         if(top<0){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };
//  NEXT SMALLER ELEMENT
vector<int> nextsmallerELEMENT(vector<int> &arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(arr[s.top()]>=curr&&s.top()!=-1){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> previoussmallerELEMENT(vector<int> &arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(arr[s.top()]>=curr&&s.top()!=-1){
            s.pop();
        }
         ans[i]=s.top();
        s.push(i);
       
    }
    return ans;
}
//  LARGEST RECTANGULAR AREA IN HISTOGRAM

int LargestRectangularElement(vector<int>& height){
    int n=height.size();
    vector<int> next(n);
    next=nextsmallerELEMENT(height,n);
    vector<int> prev(n);
    prev=previoussmallerELEMENT(height,n);
    int area=INT_MIN;
    for(int i=0;i<n;i++){
         if(next[i]==-1){
            next[i]=n;
        }
        int l=height[i];
        int b=next[i]-prev[i]-1;
        int  recarea=l*b;
        area=max(area,recarea);
    }
    return area;
}

int main(){
    vector<int>arr={2,1,5,6,2,3};
    cout<<LargestRectangularElement(arr);
    return 0;
}

 
