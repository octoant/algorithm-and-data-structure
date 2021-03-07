//
// Created by Bobur on 2.23.2021
//
#include <bits/stdc++.h>

int N;
int iters = 1, prev = -1;
int flower, length;

int main() {
    std::cin >> N;

    int j = 1, index;
    for (int i = 1; i <= N; i++) {
        std::cin >> flower;
        if (flower == prev) {
            iters++;
            if (iters == 3 && length < i - j) {
                index = j;
                length = i - j;
            }
        } else {
            if (iters >= 3) j = i - 2;
            prev = flower;
            iters = 1;
        }
    }
    if (iters < 3 && length < N - j + 1) {
        index = j;
        length = N - j + 1;
    }
    std::cout << index << " " << index + length - 1;
    return std::cout << "\n", 0;
}
