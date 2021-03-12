//
// Created by Bobur on 11.03.2021
//
#include <bits/stdc++.h>

#define lexical sorted

int x, c, sorted[100001];
std::string str;
std::vector<int> indices[127];

int main() {
    std::cin >> x >> str; --x;
    for (char i : str) indices[i].push_back(c++);
    for (int i = c = 0; i < 127; i++) {
        for (int j : indices[i]) lexical[c++] = j;
    }
    for (int i = 0; i < str.size(); i++) {
        putchar(str[x = lexical[x]]);
    }
    return 0;
}
