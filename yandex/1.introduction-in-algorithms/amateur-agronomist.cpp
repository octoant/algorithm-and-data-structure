//
// Created by Bobur on 2/23/21.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    int flower, iter = 1, prev = -1;
    int j = 1;
    int index, length = 0;

    for (int i = 1; i <= n; i++) {
        cin >> flower;
        if (flower == prev) {
            iter++;
            if (iter == 3 && length < i - j) {
                index = j;
                length = i - j;
            }
        } else {
            if (iter >= 3) j = i - 2;
            iter = 1;
            prev = flower;
        }
    }
    if (iter < 3 && length < n - j + 1) {
        index = j;
        length = n - j + 1;
    }
    cout << index << " " << index + length - 1 << "\n";
    return 0;
}
