#include <iostream>
using namespace std;
int triple(int n){
    int original=n;
    int newnumber=0;
    while(n>0){
        int a=n%10;
        int triplesum=a*a*a;
        newnumber+=triplesum;
        n/=10;
    }
    if(newnumber==original){
        return original;
    }
}
int main(){
    int number;
    cout<<"enter the number"<<endl;
    cin>>number;
    cout<<"the special numbers are as follows :"<<endl;
    for(int i=0;i<=number;i++){
        cout<<triple(i)<<" ";
    }
    return 0;
}