#include <iostream>
int binarysearch(int arr[],int size,int key){
    int start=0,end=size-1;
    while(start<=end){
        int mid=start +(end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
using namespace std;
int main(){
    int arr[]={2,4,6,8,10,12,14,16,18,20};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    int result=binarysearch(arr,size,key);
    if(result!=-1){
        cout<<"Element found at index: "<<result<<endl;
    }
    else{
        cout<<"Element not found in the array."<<endl;
    }
    return 0;
} 















