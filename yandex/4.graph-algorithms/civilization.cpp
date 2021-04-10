//
// Created by Bobur on 2.25.2021
//
#include <bits/stdc++.h>

#define vec std::vector
#define pair std::pair
#define make std::make_pair
#define queue std::priority_queue

const int infty = INT_MAX;
const int size = 1000;

int n, m, a, b, c, d;
short int map[size][size];

vec<vec<int>> w(size, vec<int>(size, infty));
bool visited[size][size];
// dijkstra's algorithm
void dijkstra(int x, int y)
{
    queue<pair<int, pair<int, int>>> que;

    que.push(make((w[x][y] = 0), make(x, y)));

    while (!que.empty())
    {
        x = que.top().second.first;
        y = que.top().second.second;

        que.pop();

        if (visited[x][y]) continue;
        visited[x][y] = 1;

        if (x > 0 && !visited[x - 1][y] && map[x - 1][y]) {
            if (w[x][y] + map[x - 1][y] < w[x - 1][y]) {
                w[x - 1][y] = w[x][y] + map[x - 1][y];
            }
            que.push(make(-w[x - 1][y], make(x - 1, y)));
        }

        if (x < n - 1 && !visited[x + 1][y] && map[x + 1][y]) {
            if (w[x][y] + map[x + 1][y] < w[x + 1][y]) {
                w[x + 1][y] = w[x][y] + map[x + 1][y];
            }
            que.push(make(-w[x + 1][y], make(x + 1, y)));
        }

        if (y > 0 && !visited[x][y - 1] && map[x][y - 1]) {
            if (w[x][y] + map[x][y - 1] < w[x][y - 1]) {
                w[x][y - 1] = w[x][y] + map[x][y - 1];
            }
            que.push(make(-w[x][y - 1], make(x, y - 1)));
        }

        if (y < m - 1 && !visited[x][y + 1] && map[x][y + 1]) {
            if (w[x][y] + map[x][y + 1] < w[x][y + 1]) {
                w[x][y + 1] = w[x][y] + map[x][y + 1];
            }
            que.push(make(-w[x][y + 1], make(x, y + 1)));
        }
    }
}

int cost = 0;
void print_direction(int x, int y)
{
    if (w[x][y] == 0) return;
    else cost = w[x][y];

    char sign;
    if (x > 0 && cost > w[x - 1][y]) {
        sign = 'S';
        cost = w[x - 1][y];
    }
    if (x < n - 1 && cost > w[x + 1][y]) {
        sign = 'N';
        cost = w[x + 1][y];
    }
    if (y > 0 && cost > w[x][y - 1]) {
        sign = 'E';
        cost = w[x][y - 1];
    }
    if (y < m - 1 && cost > w[x][y + 1]) {
        sign = 'W';
        cost = w[x][y + 1];
    }
    switch (sign) {
        case 'S':
            print_direction(x - 1, y);
            break;
        case 'N':
            print_direction(x + 1, y);
            break;
        case 'E':
            print_direction(x, y - 1);
            break;
        case 'W':
            print_direction(x, y + 1);
            break;
    }
    putchar(sign);
}

int main()
{
    std::cin >> n >> m >> a >> b >> c >> d;
    std::string s;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            /* is field */
            if (s[j] == '.') map[i][j] = 1;
            /* is forest */
            if (s[j] == 'W') map[i][j] = 2;
        }
    }
    dijkstra(a - 1, b - 1);

    if (w[c - 1][d - 1] == infty) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << w[c - 1][d - 1] << std::endl;
        print_direction(c - 1, d - 1);
        std::cout << std::endl;
    }

    return 0;
}