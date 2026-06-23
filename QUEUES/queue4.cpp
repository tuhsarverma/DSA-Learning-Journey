#include <iostream>
#include <queue>
using namespace std;
class deque{
    public:
    int size,front,rear;
    int* arr;
    deque(int n){
        size=n;
        arr= new int[n];
        front=-1,rear=-1;
    }
    bool pushfront(int element){
        //  check full
        if((front==0&&rear==size-1)|| (rear==(front-1)%(size-1))){
           cout<<" queue is full";
           return false; 
        }
        else if( front==-1){
            front=rear=0;
        }
        else if( front==0&&rear!=size-1){
            front=n-1;
        }
        else{
            front--;
        }
        arr[front]=element;
        return true;
    }
    bool pushrear(int element){
        if((front==0&&rear==size-1)|| (rear==(front-1)%(size-1))){
           cout<<" queue is full";
           return false; 
        }
        else if(front==-1){
            front=rear=0;
        }
        else if((front!=0)&&(rear==size-1)){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=element;
        return true;
    }
    int popfront(){
        if(front==-1){
            return -1;
        }
        int ans=arr[front];
        ans[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if ( front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
    int poprear(){
        if(front==-1){
            return -1;
        }
        int ans=arr[rear];
        ans[rear]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if ( rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return ans;
    }
    int getfront(){
        if(isempty()){
            return -1;
        }
        return arr[front];
    }
    int getrear(){
        if(isempty()){
            return -1;
        }
        return arr[rear];
    }
    bool isempty(){
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(){
    deque<int>d;
    d.push_front(34);
    d.push_back(14);
    d.pop_front();
    cout<<d.front();
    
}