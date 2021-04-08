//
// Created by Bobur on 08.04.2021
//
#include <bits/stdc++.h>

#define pair std::pair<int, int>
#define set std::set<pair>
#define mk_pair std::make_pair

int n, m, k;
pair p[180000];
set dots;

bool compare_vert(pair a, pair b)
{
    if (a.first != b.first) return a.first > b.first;
    else return a.second > b.second;
}

bool compare_horz(pair a, pair b)
{
    if (a.second != b.second) return a.second > b.second;
    else return a.first > b.first;
}

int answer = 0;
int main()
{
    std::cin >> n >> m >> k;

    int x, y;
    for (int i = 0; i < k; i++) {
        std::cin >> x >> y;
        p[i] = mk_pair(x, y);
    }

    for (int i = 1; i <= n; i++) {
        p[k++] = mk_pair(i, 0);
        p[k++] = mk_pair(i, m+1);
    }
    for (int i = 1; i <= m; i++) {
        p[k++] = mk_pair(0, i);
        p[k++] = mk_pair(n+1, i);
    }

    std::sort(p, p+k, compare_vert);
    for (int i = 0; i < k; i++) {
        int d = p[i].second - p[i+1].second;
        if (d > 1 && p[i].first == p[i+1].first) {
            if (d == 2) {
                dots.insert(mk_pair(p[i+1].first, p[i+1].second + 1));
            }
            else {
                answer = answer + 1;
            }
        }
    }

    std::sort(p, p+k, compare_horz);
    for (int i = 0; i < k; i++) {
        int d = p[i].first - p[i+1].first;
        if (d > 1 && p[i].second == p[i+1].second) {
            if (d == 2) {
                if (dots.find(mk_pair(p[i+1].first + 1, p[i+1].second)) != dots.end())
                    answer = answer + 1;
            }
            else {
                answer = answer + 1;
            }
        }
    }

    std::cout << answer << std::endl;

    return 0;
}
