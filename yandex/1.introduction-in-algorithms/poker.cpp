//
// Created by Bobur on 25.06.2021
//
#include <bits/stdc++.h>

using namespace std;

const int x = 100000;

int n, m, s;
int t[x];
vector<int> a;

int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) cin >> t[i];

    sort(t, t + m);

    a.push_back(t[0]);
    for (int i = 0; i < m; i++) if (a.back() != t[i]) a.push_back(t[i]);

    int prev = 0, next = n - m + 1;
    int delta = m - s - 1;
    int result = 0;
    for (int i = 0; i + delta < a.size(); i++) {
        int x = prev + 1;
        int y = next;
        if (x < a[i + delta] - m + 1) x = a[i + delta] - m + 1;
        if (y > a[i]) y = a[i];
        if (x <= y) result += y - x + 1;
        prev = a[i];
    }
    cout << result << endl;
    return 0;
}
