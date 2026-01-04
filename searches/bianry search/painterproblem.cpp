#include <iostream>
#include <vector>
using namespace std;
bool ispossible(vector <int> arra,int na,int ma,int mida){
    int paintercount=1,pgsum=0;
    for(int i=0;i<na;i++){
        if(pgsum+arra[i]<=mida){
            pgsum+=arra[i];
        }
        else{
            
            paintercount++;
            if(paintercount>ma||arra[i]>mida){
                return false;
            }
            pgsum=0;
            pgsum+=arra[i];
        }
    }
    return true;
}
int painterproblem(vector<int> arr,int n,int m){
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
    vector<int> v={5,5,5,5};
    int m,n=v.size();
    cout<<"enter the number of students";
    cin>>m;
    int finalresult=painterproblem(v,n,m);
    finalresult==-1?cout<<"ERROR!!!  reset the m":cout<<" min of maximum time is"<<finalresult;
} 