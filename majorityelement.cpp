#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1,2,1,2,1};

    int candidate = 0;
    int count = 0;

    // Phase 1: Find candidate
    for (int x : nums) {
        if (count == 0) {
            candidate = x;
        }
        count += (x == candidate) ? 1 : -1;
    }

    // Phase 2: Verify candidate (important!)
    count = 0;
    for (int x : nums) {
        if (x == candidate)
            count++;
    }

    if (count > nums.size() / 2)
        cout << "Majority element is: " << candidate;
    else
        cout << "No majority element";

    return 0;
}
