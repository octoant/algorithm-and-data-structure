//
// Created by Bobur on 19.03.2021
//
#include <bits/stdc++.h>

struct sum {
    long long left, right, all, max = 0ll;

    void set_max(long long val) {
        max = std::max(max, val);
    }
};

sum make_sum(long long left, long long right, long long all) {
    sum sum;
    sum.left = std::max(left, 0ll);
    sum.right = std::max(right, 0ll);
    sum.all = all;
    return sum;
}

sum make_sum(long long val) {
    sum sum = make_sum(val, val, val);
    sum.set_max(val);
    return sum;
}

sum divide_and_rule(long long * sequence, int a, int b) {
    if (a == b) return make_sum(sequence[a]);

    int mid = (a + b) / 2;

    sum sum_a = divide_and_rule(sequence, a, mid);
    sum sum_b = divide_and_rule(sequence, mid + 1, b);

    sum sum = make_sum(std::max(sum_a.left, sum_a.all + sum_b.left),
                       std::max(sum_a.right + sum_b.all, sum_b.right),
                       sum_a.all + sum_b.all);

    sum.set_max(sum_a.right + sum_b.left);
    sum.set_max(std::max(sum_a.max, sum_b.max));

    return sum;
}

const int size = 60000;

int n;
long long sequence[size];

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }
    if (n) {
        sum ans = divide_and_rule(sequence, 0, n - 1);
        std::cout << ans.max << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}
