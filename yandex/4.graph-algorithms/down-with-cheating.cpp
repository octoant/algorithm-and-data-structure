//
// Created by Bobur on 2.26.2021
//
#include <bits/stdc++.h>

int n, m;
short insanis[100], edge[100][100];

int main()
{
    std::cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;
        x--; y--;
        edge[x][y] = edge[y][x] = 1;
    }
    memset(insanis, -1, sizeof(insanis));
    for (int l = 0; l < n; l++) {
        if (insanis[l] == -1) insanis[l] = 1;

    for (int i = l; i < n; i++) {
        if (insanis[i] != -1) {

        for (int j = l; j < n; j++) {
            if (edge[i][j]) {
                if (insanis[j] == -1)
                    insanis[j] = not insanis[i];
                else
                if (insanis[j] == insanis[i])
                    return std::cout << "NO\n", 0;
            }
        }}
    }}
    return std::cout << "YES\n", 0;
}
