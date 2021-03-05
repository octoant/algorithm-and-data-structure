//
// Created by Bobur on 2/23/21.
//
#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d, k;

int main() {
    cin >> a >> b >> c >> d >> k;

    if (a * b <= c) return cout << 0 << "\n", 0;
    if (a * b - c == a) return cout << a << "\n", 0;
    if (a * b - c >= d) return cout << d << "\n", 0;

    long long result = a * b - c;
    for (int i = 1; i < k && 0 < result && result < d; i++) {
        result = result * b - c;
    }
    if (result < 0) return cout << 0 << "\n", 0;
    if (result > d) return cout << d << "\n", 0;
    return cout << result << "\n", 0;
}
