#include <iostream>
using namespace std;
void BUBBLESORT(int arr[],int size){
    cout<<"PRINTING ROUND WISE"<<endl;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        cout<<i+1<<"ROUND:"<<endl;
        for(int k=0;k<size;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cout<<"enter the size";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BUBBLESORT(arr,n);
    
    cout<<"PRINTING IN MAINS";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
