//
// Created by Bobur on 01.04.2021
//
#include <bits/stdc++.h>

int n, m, ans = 0;
int x[1001][1001];

int t[1000001], f[4];
int need(int i, int j)
{
    f[0] = x[i][j];
    f[1] = x[i][m-1-j];
    f[2] = x[n-1-i][j];
    f[3] = x[n-1-i][m-1-j];

    for (int i = 0; i < 4; i++)
        t[f[i]]++;

    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (res < t[f[i]]) {
            res = t[f[i]];
        }
        t[f[i]] = 0;
    }
    return (4-res);
}

int main()
{
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        std::cin >> x[i][j];

    if (n % 2)
    for (int j = 0; j < m>>1; j++)
        if (x[n>>1][j] != x[n>>1][m - 1 - j])
            ans++;

    if (m % 2)
    for (int i = 0; i < n>>1; i++)
        if (x[i][m>>1] != x[n - 1 - i][m>>1])
            ans++;

    for (int i = 0; i < n>>1; i++)
        for (int j = 0; j < m>>1; j++)
            ans += need(i, j);

    std::cout << ans << std::endl;

    return 0;
}
