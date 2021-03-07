//
// Created by Bobur on 2.24.2021
//
#include <bits/stdc++.h>

bool is_uppercase(char ch) {
    return 'A' <= ch && ch <= 'Z'; // A <= ch <= Z
}

bool are_same(char ch1, char ch2) {
    if (is_uppercase(ch1)) return ch1 + 32 == ch2;
    else return ch1 - 32 == ch2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s; std::cin >> s;
    std::vector<std::pair<char, int>> stack(0);

    int indices[s.length() / 2];

    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!stack.empty() && are_same(stack.back().first, s[i])) {
            if (is_uppercase(s[i])) indices[a++] = stack.back().second;
            else indices[stack.back().second] = b++;
            stack.pop_back();
        } else {
            if (is_uppercase(s[i])) stack.push_back(std::make_pair(s[i], a++));
            else stack.push_back(std::make_pair(s[i], b++));
        }
    }

    if (stack.empty()) {
        std::cout << "Possible\n";
        for (int i = 0; i < s.length() / 2; i++) {
            std::cout << indices[i] + 1 << " ";
        }
    } else {
        std::cout << "Impossible";
    }
    return std::cout << "\n", 0;
}
