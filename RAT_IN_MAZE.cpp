#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool issafe(int x, int y, int n, vector<vector<int>> &m, vector<vector<int>> &visited) {
    // boundary + open cell + not visited
    if (x >= 0 && x < n && y >= 0 && y < n && m[x][y] == 1 && visited[x][y] == 0)
        return true;
    return false;
}

void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y,
           vector<vector<int>> &visited, string path) {

    if (x == n - 1 && y == n - 1) {   // reached destination
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    int newx, newy;

    // D
    newx = x + 1; newy = y;
    if (issafe(newx, newy, n, m, visited)) {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // L
    newx = x; newy = y - 1;
    if (issafe(newx, newy, n, m, visited)) {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // U
    newx = x - 1; newy = y;
    if (issafe(newx, newy, n, m, visited)) {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // R
    newx = x; newy = y + 1;
    if (issafe(newx, newy, n, m, visited)) {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;   // backtrack
}

vector<string> findpath(vector<vector<int>> &m, int n) {

    vector<string> ans;
    if (m[0][0] == 0)
        return ans;

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";

    solve(m, n, ans, 0, 0, visited, path);

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {

    vector<vector<int>> arr = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> refresh = findpath(arr, 4);

    for (string i : refresh)
        cout << i << " ";

    return 0;
}
