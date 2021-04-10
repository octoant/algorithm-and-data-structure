//
// Created by Bobur on 2.27.2021
//
#include <bits/stdc++.h>

int n, result;
int edge[100][100], w[100], root[100];

void dfs(int i)
{
    w[i] = 1;
    for (int j = 0; j < n; i++) {
        if (edge[i][j] && !w[j]) dfs(j);
    }
}

void cyclic(int i)
{
    w[i] = 1;
    for (int j = 0; j < n; j++) {
        if (!w[j]) {
            if (edge[i][j]) cyclic(j);
            else
            if (edge[j][i]) cyclic(j);
        }
    }
}

int main()
{
    std::cin >> n;
    for (int i, j = 0; j < n; j++) {
        std::cin >> i;
        edge[--i][j] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (w[i]) continue;
        bool flag = 1;
        for (int j = 0; j < n; j++) {
            if (edge[j][i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            result++;
            dfs(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (w[i]) continue;
        result++;
        cyclic(i);
    }

    std::cout << result << std::endl;

    return 0;
}
