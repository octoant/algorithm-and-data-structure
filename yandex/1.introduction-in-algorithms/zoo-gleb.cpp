//
// Created by Bobur on 2/24/21.
//
#include <bits/stdc++.h>

using namespace std;

bool is_uppercase(char ch) {
    return 'A' <= ch && ch <= 'Z'; // A <= ch <= Z
}

bool are_same(char ch1, char ch2) {
    if (is_uppercase(ch1)) return ch1 + 32 == ch2;
    else return ch1 - 32 == ch2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    int indices[s.length() / 2];

    vector<pair<char, int>> stack(0);
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!stack.empty() && are_same(stack.back().first, s[i])) {
            if (is_uppercase(s[i])) indices[a++] = stack.back().second;
            else indices[stack.back().second] = b++;
            stack.pop_back();
        } else {
            if (is_uppercase(s[i])) stack.push_back(make_pair(s[i], a++));
            else stack.push_back(make_pair(s[i], b++));
        }
    }

    if (stack.empty()) {
        cout << "Possible\n";
        for (int i = 0; i < s.length() / 2; i++) {
            cout << indices[i] + 1 << " ";
        }
    } else {
        cout << "Impossible";
    }
    return cout << "\n", 0;
}
