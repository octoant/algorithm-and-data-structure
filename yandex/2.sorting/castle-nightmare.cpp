//
// Created by Bobur on 2.28.2021
//
#include <bits/stdc++.h>

int letter[123];
long long weight[123];
bool used[123];

std::vector<char> letters;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s; std::cin >> s;
    for (char _ = 'a'; _ <= 'z'; _++) {
        std::cin >> weight[_];
    }
    for (int i = 0; i < s.size(); i++) {
        letter[s[i]]++;
    }
    for (char _ = 'a'; _ <= 'z'; _++) {
        char ch = ' ';
        for (int i = 'a'; i <= 'z'; i++) {
            if (letter[i] > 1 && !used[i] && weight[ch] < weight[i]) ch = i;
        }
        if (ch != ' ') {
            used[ch] = 1;
            letters.push_back(ch);
            letter[ch] -= 2;
        }
    }
    for (int i = 0; i < letters.size(); i++) {
        std::cout << letters[i];
    }
    for (char i = 'a'; i <= 'z'; i++) {
        while (letter[i]--) std::cout << i;
    }
    for (int i = letters.size()-1; i >= 0; i--) {
        std::cout << letters[i];
    }
    return std::cout << std::endl, 0;
}
