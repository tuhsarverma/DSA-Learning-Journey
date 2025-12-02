#include <iostream>
using namespace std;
int BS(int arr[],int n,int tar){
    int s=0,e=n-1,mid=0;
    while(s<=e){
        mid=s+(e-s)/2;  // UPDATING THE MID
        if(arr[mid]==tar){
            return mid;
        }
        else if(arr[mid]>tar){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}
int main() {
    int arr[8]={1,5,6,8,9,10,13};
    int tar,size;
    cout<<"enter the target";
    cin>>tar;// INPUT THE TARGET
    if(BS(arr,8,tar)!=-1){
        cout<<"the index of target is "<<BS(arr,8,tar);
    }
    else if( BS(arr,8,tar)==-1){
        cout<<"Target not found";
    }
    return 0;
}
