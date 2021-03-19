//
// Created by bobur on 2/25/21.
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int _N; cin >> _N;

    long long x, sum = 0, max = 0;
    for (int i = 0; i < _N; i++) {
        cin >> x;
        sum = sum + x < 0 ? 0 : sum + x;
        if (sum > max) max = sum;
    }
    return cout << max << "\n", 0;
}
