//
// Created by Bobur on 12.03.2021
//
#include <bits/stdc++.h>

int n, k, x, half;
std::vector<std::pair<int, int>> all;
std::deque<std::pair<int, int>> left, right;

int main() {
    std::cin >> k;
    for (int i = 1; i <= k; i++) {
        std::cin >> x;
        n += x;
        all.push_back(std::make_pair(x, i));
    }
    std::sort(all.rbegin(), all.rend());
    half = (++n)>>1;

    for (int i = 0; i < k; i++) {
        if (half - all[i].first >= 0 || i == 0) {
            left.push_back(all[i]);
            half -= std::min(half, all[i].first);
        } else {
            all[i].first -= half;
            if (half) left.push_back(std::make_pair(half, all[i].second));
            half = 0;
            right.push_back(all[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!left.empty()) {
            std::cout << left.front().second << " ";
            left.front().first--;
            if (!left.front().first) left.pop_front();
        }
        if (!right.empty()) {
            std::cout << right.front().second << " ";
            right.front().first--;
            if (!right.front().first) right.pop_front();
        }
    }
    return 0;
}
