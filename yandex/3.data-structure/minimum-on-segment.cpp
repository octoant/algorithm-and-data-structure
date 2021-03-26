//
// Created by bobur on 2/24/21.
//
#include <bits/stdc++.h>

int main() {

    int n, k; std::cin >> n >> k;

    std::vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    k--;
    if (k == 0) {
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        return std::cout << "\n", 0;
    }

    for (int i = 0; i < n; i++) {
        if (i % k) b[i] = std::min(a[i], b[i - 1]);
        else b[i] = a[i];
    }

    c.back() = a.back();

    for (int i = n - 2; i >= 0; i--) {
        if ((i + 1) % k) c[i] = std::min(a[i], c[i + 1]);
        else c[i] = a[i];
    }

    for (int i = k; i < n; i++) {
        std::cout << std::min(b[i], c[i - k]) << " ";
    }
    return std::cout << "\n", 0;
}
