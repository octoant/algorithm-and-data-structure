//
// Created by Bobur on 17.04.2021
//
#include <bits/stdc++.h>

const int infinity = 1 << 30;
const int size = 50000;
const int w = 200;
const int digit = 10;

int n;
int cost[digit];
std::string number[size];
std::unordered_map<std::string, int> map;
int idx[size], edge[size][w];
int weight[size], indices[size];
bool visited[size];

void add(std::string number, int id)
{
    auto iter = map.find(number);
    if (iter != map.end()) {
        int i = iter->second;
        int j = id;
        edge[i][idx[i]++] = j;
        edge[j][idx[j]++] = i;
    }
}

void add_next(int id)
{
    std::string s;
    for (int i = 0; i < digit; i++) {
        for (int j = 0; j < digit; j++) {
            s = number[id];
            /* setting a digit */
            s[i] = j + '0';
            add(s, id);
        }
        for (int j = i + 1; j < digit; j++) {
            s = number[id];
            /* swapping digits */
            std::swap(s[i], s[j]);
            add(s, id);
        }
    }
    map[number[id]] = id;
}

int get_cost(const int &a, const int &b)
{
    for (int i = 0; i < digit; i++) {
        if (number[a][i] != number[b][i])
            return cost[i];
    }
    return -1;
}

void dijkstra(int start)
{
    auto compare = [](const int &a, const int &b) {
        return weight[a] > weight[b];
    };
    std::priority_queue<int, std::vector<int>, decltype(compare)> queue(compare);
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        weight[i] = infinity;
    }
    weight[start] = 0;
    queue.push(start);
    while (!queue.empty()) {
        int i = queue.top();
        queue.pop();
        if (visited[i]) continue;
        visited[i] = true;
        for (int k = 0; k < idx[i]; k++) {
            int j = edge[i][k];
            int cost = get_cost(i, j);
            if (not visited[j] && weight[j] > cost + weight[i]) {
                weight[j] = cost + weight[i];
                indices[j] = i;
                queue.push(j);
            }
        }
    }
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < digit; i++) {
        std::cin >> cost[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> number[i];
        add_next(i);
    }
    dijkstra(0);
    if (!visited[n-1]) {
        return std::cout << -1 << "\n", 0;
    } else {
        std::cout << weight[n - 1] << "\n";
    }
    std::vector<int> result;
    for (int i = n - 1; i != 0; i = indices[i]) {
        result.push_back(i);
    }
    result.push_back(0);
    int size = result.size();
    std::cout << size << "\n";
    for (int i = size - 1; i >= 0; i--) {
        std::cout << result[i] + 1 << " ";
    }
    return 0;
}
