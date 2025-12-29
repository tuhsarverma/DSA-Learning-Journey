#include <iostream>
#include <vector>
using namespace std;
bool ispossible(vector <int> arra,int na,int ma,int mida){
    int studentcount=1,pgsum=0;
    for(int i=0;i<na;i++){
        if(pgsum+arra[i]<=mida){
            pgsum+=arra[i];
        }
        else{
            
            studentcount++;
            if(studentcount>ma||arra[i]>mida){
                return false;
            }
            pgsum=0;
            pgsum+=arra[i];
        }
    }
    return true;
}
int bookallocation(vector<int> arr,int n,int m){
    int s=0,sum=0;
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e,mid;
    int ans=-1;
    e=sum,mid=e+(s-e)/2;
    while(s<=e){
        mid=e+(s-e)/2;
        if(ispossible(arr, n, m, mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> v={10,20,30,40};
    int m,n=v.size();
    cout<<"enter the number of students";
    cin>>m;
    cout<<bookallocation(v,n,m);
}