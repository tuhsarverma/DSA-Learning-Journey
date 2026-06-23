#include <iostream>
using namespace std;

class queue{
    public:
    int* arr;
    int size;
    int qfront;
    int rear;
    queue(){
        size=10001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }
    bool isempty(){
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int element){
        if(rear==size){
            cout<<" queue overflow";
        }
        else{
            arr[rear]=element;
            rear++;
        }
    }
    int dequeue(){
        if(rear==qfront){
            cout<<" queue underflow";
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0,rear=0;
            }
            return ans;
        }
    }
    int front(){
        if(qfront==0&&rear==0){
            cout<<" queue is empty";
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};