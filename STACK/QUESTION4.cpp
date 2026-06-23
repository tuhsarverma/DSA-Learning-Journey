#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <cmath>
#include <climits>

//   N STACKS IN AN ARRAY
// approach
//  find index, update freespot, insert in array, update next[index], update top
//  TC-O(1)     SC-O(s+n)
class NStack{
    int* arr;
    int* top;
    int* next;
    int n,s,freespot;
    public:
    NStack(int N,int S){
        n=N,s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];
        //  top initialize
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        // next initialize
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }
        //update last index value to -1
        next[s-1]=-1;
        // initialie freespot
        freespot=0;
    }
   
};
 // Pushes 'x' into the Mth srtack. returns true if it gets pushed into the stack and false otherwise
    bool push(int x,int m){
        int index=freespot;
        freespot= next[index];
        arr[index]=x;
        next[index]=top[m-1];
        top[m-1]=index;
    }
    int pop(int m){
        //  check underflow
        if(top==-1){
            return -1;
        }
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }


int main(){
    return 0;
}