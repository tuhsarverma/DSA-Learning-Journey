#include <iostream>
using namespace std;
//  CIRCULAR QUEUE
class Circularqueue{
    int* arr;
    int* next;
    int front,rear;
    int size;

    Circularqueue(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }
    bool enqueue(int value){
        if((front==0&&rear==size-1)|| (rear==(front-1)%(size-1))){
           cout<<" queue is full";
           return false; 
        }
        else if( front==-1){ // first element to push
            front=rear=0;
    
        }
        else if((rear==size-1)&&front!=0){ // to maintain cyclic nature
            rear=0;    
        }
        else{
            rear++;// normal flow
    
        }
        arr[rear]=value;
        return true;
    }
    int dequeue()
{
    if(front==-1){  // to check queue is empty
        cout<<" queue is empty"<<endl;
        return -1;
    }
    int ans=arr[front];
    arr[front]=-1;
    if(front==rear){
        front=rear=-1;
    }
    else if( front=size-1){// to maintain cyclic nature
        front=0;
    }
    else{
        front++; // normal flow
    }
    return ans;
}
};