#include <iostream>
#include <string>
using namespace std;

bool checkequal(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool checkinclusion(string s1, string s2) {
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++) {
        count1[s1[i] - 'a']++;
    }

    int windowsize = s1.length();
    int count2[26] = {0};
    int i = 0;

    // initial window
    while (i < windowsize && i < s2.length()) {
        count2[s2[i] - 'a']++;
        i++;
    }

    if (checkequal(count1, count2)) {
        return true;
    }

    // slide the window
    while (i < s2.length()) {
        count2[s2[i] - 'a']++;

        char oldchar = s2[i - windowsize];
        count2[oldchar - 'a']--;   // 🔥 important fix

        i++;

        if (checkequal(count1, count2)) {
            return true;
        }
    }

    return false;  // 🔥 important fix
}

int main() {
    checkinclusion("ba", "eidbaooo") ? cout << "YES\n" : cout << "NO\n";
    return 0;
}
