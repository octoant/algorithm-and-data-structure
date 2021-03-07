//
// Created by Bobur on 2.25.2021
//
#include <bits/stdc++.h>

using namespace std;
    
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k; std::cin >> n >> k;
    std::vector<long long> a(n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = k - 1; i < n; i += k) {
        sum -= a[i];
    }
    return std::cout << sum << "\n", 0;
}
