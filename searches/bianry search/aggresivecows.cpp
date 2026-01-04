#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ispossible(vector<int>& stalls, int k, int mid) {
    int cowcount = 1;
    int lastpos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastpos >= mid) {
            cowcount++;
            lastpos = stalls[i];

            if (cowcount == k)
                return true;
        }
    }
    return false;
}

int aggressivecow(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int s = 0;
    int e = stalls.back() - stalls.front();
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (ispossible(stalls, k, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v = {4, 3, 2, 1, 6};
    cout << aggressivecow(v, 2);
}
