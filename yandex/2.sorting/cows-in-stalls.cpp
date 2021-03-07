//
// Created by Bobur on 2.26.2021
//
#include <bits/stdc++.h>

#define mid(a, b) (a + b) / 2

const int SIZE = 100001;

int N, K;
int stall[SIZE];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N >> K;

    for (int _i = 0; _i < N; _i++) { std::cin >> stall[_i]; }
    // binary search
    int middle, left = 0, right = INT_MAX;
    while (left + 1 < right) {
        middle = mid(left, right);

        int counter = 1;
        for (int i = 0, j = 0; i < N; i++) {
            if (stall[i] - stall[j] >= middle) { counter++; j = i; }
        }
        if (counter >= K) left = middle;
        else right = middle;
    }
    return std::cout << left << "\n", 0;
}
