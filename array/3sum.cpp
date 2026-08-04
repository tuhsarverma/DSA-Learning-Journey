#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int>> threesum(vecto<int&nums){
  int n=nums.size();
  set<vector<int>> uniquetriplet;
  for(int i=0;i<n;i++){
    int tar=-nums[i];
    set<int> s;
    for(int j=i+1;j<n;j++){
      int third=tar-nums[j];
      if(s.find(third)!=s.end()){
        vector<int> trip={nums[i],nums[j],third};
        sort(trip.begin(),trip.end());
        uniquetriplet.insert(trip);
    }
      s.insert(nums[j]);
  }
    vector<vector<int>> ans(uniquetriplet.begin(),uniquetriplet.end());
}
int main(){
  
}
