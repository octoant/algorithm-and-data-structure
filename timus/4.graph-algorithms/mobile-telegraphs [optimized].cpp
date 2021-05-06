//
// Created by Bobur on 06.05.2021
//
#include <bits/stdc++.h>

# define parent(i) (i - 1) >> 1
# define left(i) (i << 1) + 1
# define right(i) (i << 1) + 2

using namespace std;

long long p[10]; /* ..., 1000, 100, 10, 1 */
int N;
int cost[10];
struct node { long long val; int idx; } number[50000];
int len = 0;
int heap[50000], weight[50000], idx[50000];
bool visited[50000], in[50000];

int get_idx(long long elem)
{
    int left = 0, mid, right = N-1;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (number[mid].val < elem)
            left = mid + 1;
        else
        if (number[mid].val > elem)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

void sift_up(int i)
{
    while (i && weight[heap[i]] < weight[heap[parent(i)]]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void sift_down(int i)
{
    while (true) {
        int j = i;
        if (left(j) < len && weight[heap[i]] > weight[heap[left(j)]]) {
            i = left(j);
        }
        if (right(j) < len && weight[heap[i]] > weight[heap[right(j)]]) {
            i = right(j);
        }
        if (i != j) swap(heap[i], heap[j]);
        else break;
    }
}

void add(long long elem)
{
    heap[len] = elem;
    sift_up(len++);
}

int get_min()
{
    swap(heap[0], heap[--len]);
    sift_down(0);
    return heap[len];
}

int get_digit(long long elem, int i)
{
    return elem / p[i] % 10;
}

long long set_digit(long long elem, int i, int j)
{
    return elem + (j - get_digit(elem, i)) * p[i];
}

long long swap_digits(long long elem, int i, int j)
{
    int dig_i = get_digit(elem, i);
    int dig_j = get_digit(elem, j);
    return set_digit(set_digit(elem, i, dig_j), j, dig_i);
}

void relax(long long elem, int id, int x)
{
    int i = get_idx(elem);
    int j = id;
    if (i != -1 && i != j)
        if (!visited[i] && weight[i] > weight[j] + cost[x]) {
            weight[i] = weight[j] + cost[x];
            idx[i] = j;
            if (!in[i]) in[i] = true, add(i);
        }
}

void dijkstra(int start)
{
    for (int i = 0; i < N; i++) {
        weight[i] = 1e9;
    }
    weight[start] = 0;
    add(start);
    while (len > 0) {
        int id = get_min(); visited[id] = true;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                relax(set_digit(number[id].val, i, j), id, i);
            }
            for (int j = i+1; j < 10; j++) {
                relax(swap_digits(number[id].val, i, j), id, i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long a, b, x = 1;
    for (int i = 0; i < 10; i++) {
        p[9-i] = x, x *= 10;
    }
    cin >> N;
    for (int i = 0; i < 10; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> x;
        number[i] = {x, i};
    }
    a = number[0].val, b = number[N-1].val;
    sort(number, number + N, [](node &a, node &b) {
        return a.val < b.val;
    });
    int p = get_idx(a), q = get_idx(b);
    dijkstra(p);
    if (visited[q])
        cout << weight[q] << endl;
    else
        return cout << "-1\n", 0;

    len = 0;
    for (int i = q; i != p; i = idx[i]) {
        heap[len++] = i;
    }
    heap[len++] = p;
    cout << len << endl;
    for (int i = len-1; i >= 0; i--) {
        cout << number[heap[i]].idx + 1 << " ";
    }
    return 0;
}
