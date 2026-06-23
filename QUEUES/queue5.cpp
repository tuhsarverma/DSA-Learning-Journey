#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <stack>
#include <string>
// vector<long long> prnitfirstnegativeinteger(long long int A,long long int N,long long int K){
//     deque<long long int> dq;
//     vector<long long > ans;
//     for(int i=0;i<K;i++){
//         if(A[i]<0){
//             dq.push_back(i);
//         }
//     }
//     if(dq.size()>0){
//         ans.push_back(A[dq.front()]);
//     }
//     else{
//         ans.push_back(0);
//     }
//     for(int i=K;i<N;i++){
//         if(!dq.empty()&&i-dq.front()>=K){
//             dq.pop_front();
//         }
//         if(A[i]<0){
//             dq.push_back(i);
//         }
//         if(dq.size()){
//             ans.push_back(A[dq.front()]);
//         }
//         else{
//             ans.push_back(0);
//         }
//     }
//     return 0;
// }
// //  
// queue<int> reverse(queue<int>q){
//     stack<int> p;
//     int s=0,size=q.size();
//     while(s<q.size()){
//         p.push(q.front());
//         q.pop();
//         s++;
//     }
//     s=0;
//     while(s<size){
//         q.push(p.top());
//         s.pop();
//         s++;
//     }
//     return q;
// }
//  REVERSE 1ST K ELEMENTS OF QUEUE
queue<int> reverseK(queue<int> q,int k){
    stack<int> s;
    queue<int> q1;
    int n=q.size();
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    for(int i=0;i<n-k;i++){
        q1.push(q.front());
        q.pop();
    }
    for(int i=0;i<n;i++){
        if(i<k){
            q.push(s.top());
            s.pop();
        }
        else{
            q.push(q1.front());
            q1.pop();
        }
    }
    return q;
}

    // 2 METHOD
    queue<int> reverseKth(queue<int> q,int k){
        stack<int> s;
        for(int i=0;i<k;i++){
            int val=q.front();
            q.pop();
            s.push(val);
        }
        while(!s.empty()){
            int val=s.top();
            s.pop();
            q.push(val);
        }
        int  t=q.size()-k;
        while(t--){
            int val=q.front();
            q.pop();
            q.push(val);
        }
    }
    //  Q-4   FIRST NON REPEATING CHARACTER IN A STREAM
    string firstnon_repeating(string s){
         unordered_map<char,int> count;
         queue<int> q;
         string ans="";
         for(int i=0;i<s.length();i++){
            char ch=A[i];
             //   increase count
        count[ch]++;
        //  push in queue
        q.push(ch);
        while(!q.empty()){
            if(count[q.front()]>1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
              if(q.empty()){
              ans.push_back('#');
              }
        } 
        return ans;
    }
//  Q-5 CIRCULAR TOUR PP
int tour(petrolpum p,int n){
    int deficit =0;
    int balance=0;
    int start=0;
    for(int i=0;i<n;i++){
        balance+=p[i].petrol-p[i].distance;
       if(balance<0){
        deficit+=balance;
        start=i+1;
        balance=0;
       }
    }
    if(deficit+ balance>=0){
        return start;

    }
    else{
        return -1 ;
    }
}

int main(){
    queue<int>q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    reverseK(q,3);
    q = reverseK(q,3);

while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
}
string str= firstnon_repeating("aaab");
cout<<str;
}
