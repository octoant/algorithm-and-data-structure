//
// Created by Bobur on 23.04.2021
//
#include <bits/stdc++.h>

const int size = 100;

int n, m, s;
double v;
int pnt[2*size][2];
double cur[2*size][2];
double d[size];

bool ford_bellman(int s, double v)
{
    d[s-1] = v;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < 2 * m; j++)
            if (d[pnt[j][1]] < (d[pnt[j][0]] - cur[j][1]) * cur[j][0] + 0.000001)
                d[pnt[j][1]] = (d[pnt[j][0]] - cur[j][1]) * cur[j][0];
        for (int j = 0; j < 2 * m; j++)
            if (d[pnt[j][1]] < (d[pnt[j][0]] - cur[j][1]) * cur[j][0] - 0.000001)
                return false;
        return true;
}

int main()
{
    std::cin >> n >> m >> s >> v;
    int a, b;
    double rab, cab, rba, cba;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        std::cin >> rab >> cab >> rba >> cba;
        int p = 2 * i;
        int q = 2 * i + 1;
        pnt[p][0] = a-1, pnt[p][1] = b-1;
        cur[p][0] = rab, cur[p][1] = cab;
        pnt[q][0] = b-1, pnt[q][1] = a-1;
        cur[q][0] = rba, cur[q][1] = cba;
    }
    std::cout << (ford_bellman(s, v) ? "NO" : "YES");
    return 0;
}
