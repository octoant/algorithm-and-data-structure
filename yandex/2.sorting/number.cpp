//
// Created by Bobur on 2.24.2021
//
#include <bits/stdc++.h>

typedef unsigned int uint;

bool compare(std::string s1, std::string s2) {
    for (int i = 0; i < s1.size() && i < s2.size(); i++) {
        if (s1[i] > s2[i]) return 1;
        if (s1[i] < s2[i]) return 0;
    }
    if (s1.size() < s2.size())
        return compare(s1, s2.substr(s1.size()));
    else
    if (s1.size() > s2.size())
        return compare(s1.substr(s2.size()), s2);
    else
    return 1;
}

std::vector<std::string> merge_sort(std::vector<std::string> v, uint begin, uint end) {
    if (begin == end) return { v[begin] };

    uint middle = (begin + end) / 2;

    std::vector<std::string> left = merge_sort(v, begin, middle);
    std::vector<std::string> right = merge_sort(v, middle + 1, end);
    std::vector<std::string> merged;

    uint l = 0, r = 0;
    while (l < left.size() && r < right.size()) {
        if (compare(left[l], right[r])) merged.push_back(left[l++]);
        else merged.push_back(right[r++]);
    }
    while (l < left.size()) {
        merged.push_back(left[l++]);
    }
    while (r < right.size()) {
        merged.push_back(right[r++]);
    }
    return merged;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<std::string> numbers;
    std::string str;
    while (std::cin >> str) {
        numbers.push_back(str);
    }
    std::vector<std::string> sorted = merge_sort(numbers, 0, numbers.size() - 1);
    for (auto it = sorted.begin(); it < sorted.end(); it++) {
        std::cout << *it;
    }
    return std::cout << std::endl, 0;
}
