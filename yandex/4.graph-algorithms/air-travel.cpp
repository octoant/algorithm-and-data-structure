//
// Created by bobur on 2/25/21.
//
#include <bits/stdc++.h>

#define mid(x, y) (x + y) / 2

int n, weight[1000][1000];
bool node[1000][1000], visited[1000];

void node_depth_search(int from, int t)
{
    visited[from] = true;
    for (int to = 0; to < n; to++) {
        if ((t ? node[to][from] : node[from][to]) && !visited[to])
            node_depth_search(to, t);
    }
}

bool was_in_all_nodes()
{
    for (int in = 0; in < n; in++)
        if (!visited[in]) return false;
    return true;
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        std::cin >> weight[i][j];
    }}
    if (n == 1) {
        return std::cout << 0 << "\n", 0;
    }
    // Binary search
    int mid, l = 0, r = INT_MAX;
    while (l < r) {
        mid = mid(l, r);

        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            node[i][j] = (mid >= weight[i][j]);
        }}
        bool all_done = false;
        memset(visited, false, sizeof(visited));
        node_depth_search(0, false);
        if (!was_in_all_nodes()) {
            all_done = true;
        } else {
            memset(visited, false, sizeof(visited));
            node_depth_search(0, true);
            if (!was_in_all_nodes()) {
                all_done = true;
            }
        }
        if (all_done) l = mid + 1;
        else r = mid;
    }
    return std::cout << mid(l, r) << "\n", 0;
}
