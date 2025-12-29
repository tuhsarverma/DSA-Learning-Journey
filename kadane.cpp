#include <iostream>
using namespace std;
#include <vector>
int kadane(const vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum =max(nums[i],currentSum+nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
int main(){
    vector<int> vec={0,-4,9,8,7};
    cout<<kadane(vec);
}