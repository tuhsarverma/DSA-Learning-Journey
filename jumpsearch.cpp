#include  <iostream>
#include <cmath>
using namespace std;
int jumpsearch(int arr[],int size,int key){
    int n=size,m=sqrt(n);
    int i=0;
    while(arr[min(m,n)-1]<key){
        i=m;
        m+=sqrt(n);
        if(i>=n){
            return -1;
        }
    }
    while(arr[i]<key){
        i++;
        if(i==min(m,n)){
            return -1;
        }
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}
int main(){
    int arr[]={3,5,7,9,11,13,15,17,19,21,23,25};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key;
    cout<<"ENTER THE ELEMENT TO BE SEARCHED:"<<endl;
    cin>>key;
    int result=jumpsearch(arr,size,key);
    if(result==-1){
        cout<<"ELEMENT NOT FOUND"<<endl;
    }
    else{
        cout<<"ELEMENT FOUND AT INDEX:"<<result<<endl;
    }
}