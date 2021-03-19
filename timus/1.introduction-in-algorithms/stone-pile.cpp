//
// Created by bobur on 2/25/21.
//
#include <bits/stdc++.h>

using namespace std;

int n, sum, pile;
int weight[22];

int deep_max(int s, int i) {
    if (!i) return s;

    if (s + weight[i] > pile) return deep_max(s, i - 1);
    return max(deep_max(s, i - 1), deep_max(s + weight[i], i - 1));
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        sum += weight[i];
    }
    pile = sum / 2;

    int r = sum - 2 * deep_max(0, n);
    return cout << r << "\n", 0;
}
