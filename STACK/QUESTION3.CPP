#include <iostream>
using namespace std;
class stack{
    int *arr;
    int top;
    int size;
    stack(int size){
        this->size=size;
        top=-1;
        arr=new int[size];
    }
     void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
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
            cout<<" stack is empyt"<<endl;
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
// Q-1
int celebrity(vector<vector<int>> &M,int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(n);
    }
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(M[a][b]==1){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int candidate=s.top();
    int rowcheck=false;
    int zerocount=0;
    for(int i=0;i<n;i++){
        if(M[candidate][i]==0){
            zerocount++;
        }
    }
    if(zerocount==n){
        rowcheck=true;
    }
    bool colcheck=falsel
    zerocount=0;
    for(int i=0;i<n;i++){
        if(M[i][candidate]==1){
            zerocount++;
        }
    }
    if(zerocount==n-1){
        rowcheck=true;
    }
    if(rowcheck==true&&colcheck==true){
        return candidate;
    }
    else{
        return -1;
    }
}
// f
// Q-2  LARGEST RECTANGLE AREA
vector<int> nextsmallerelement(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1&&arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevsmallerelement(int* arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1&&arr[s.top()]>=curr){
            s.pop();
        }
        // ans is stack ka top
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
int largestrectanglearea(int* heights,int n){
    vector<int> next(n);
    next=nextsmallerelement(heights,n);
    vector<int> prev(n);
    prev=prevsmallerlelement(heights,n);
    int area=INT_MIN;
    for(int i=0;i<n;i++){
        int l=heights[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int b=next[i]-prev[i]-1;
        int newarea=l*b;
        area=max(area,newarea);
    }
    return area;
}
int maxarea(int M[MAX][MAX],int n,int m){
    // compute the area for first row
    int area=largestrectanglearea(M[0],m);
    //  for remaining row
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]!=0){
                M[i][j]=M[i][j]+M[i-1][j];
            }
            else{
                M[i][j]=0;
            }
            
        }
        // entire row is updated now
        int newarea=largestrectanglearea(M[i],m);
            area=max(area,newarea);
    }
    return area;
}
int main(){
}