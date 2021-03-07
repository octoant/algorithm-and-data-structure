//
// Created by Bobur on 2.23.2021
//
#include <bits/stdc++.h>

long long a, b, c, d, k;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> a >> b >> c >> d >> k;

    if (a * b <= c) return std::cout << 0 << "\n", 0;
    if (a * b - c == a) return std::cout << a << "\n", 0;
    if (a * b - c >= d) return std::cout << d << "\n", 0;

    long long result = a * b - c;
    for (int i = 1; i < k && 0 < result && result < d; i++) {
        result = result * b - c;
    }
    if (result < 0) return std::cout << 0 << "\n", 0;
    if (result > d) return std::cout << d << "\n", 0;
    return std::cout << result << "\n", 0;
}
