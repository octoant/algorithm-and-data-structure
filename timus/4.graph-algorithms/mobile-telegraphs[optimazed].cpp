//
// Created by Bobur on 04.05.2021
//
#include <stdio.h>
#include <algorithm>

#define parent(i) (i - 1) >> 1
#define left(i) (i << 1) + 1
#define right(i) (i << 1) + 2

using namespace std;

const int infinity = 1 << 30;

const int maxn = 50000;
const int w = 135;
const int digit = 10;

long long p[digit];
int N;
int cost[digit];
pair<long long, int> number[maxn];

int idx[maxn], adj[maxn][w];

int len = 0, heap[maxn];
int weight[maxn], indices[maxn];
bool visited[maxn], in[maxn];

int get_idx(long long elem)
{
    int left = 0, mid, right = N-1;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (number[mid].first < elem)
            left = mid + 1;
        else
            if (number[mid].first > elem)
                right = mid - 1;
            else
                return mid;
    }
    return -1;
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
    int ti = get_digit(elem, i);
    int tj = get_digit(elem, j);
    return set_digit(set_digit(elem, i, tj), j, ti);
}


int get_cost(int i, int j)
{
    for (int k = 0; k < digit; k++) {
        if (get_digit(number[i].first, k) != get_digit(number[j].first, k))
            return cost[k];
    }
    return -1;
}


void add(long long elem, int id)
{
    int i = get_idx(elem);
    int j = id;
    if (i != -1 && number[i].second < number[j].second) {
        adj[i][idx[i]++] = j;
        adj[j][idx[j]++] = i;
    }
}

void add_next(int id)
{
    for (int i = 0; i < digit; i++) {
        for (int j = 0; j < digit; j++) {
            add(set_digit(number[id].first, i, j), id);
        }
        for (int j = i+1; j < digit; j++) {
            add(swap_digits(number[id].first, i, j), id);
        }
    }
}


bool lower(int i, int j)
{
    return weight[heap[i]] < weight[heap[j]];
}

void sift_up(int i)
{
    while (i && lower(i, parent(i))) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void sift_down(int i)
{
    while (true) {
        int j = i;
        if (left(j) < len && lower(left(j), i)) {
            i = left(j);
        }
        if (right(j) < len && lower(right(j), i)) {
            i = right(j);
        }
        if (i != j) swap(heap[i], heap[j]);
        else break;
    }
}

void heap_add(int item)
{
    heap[len] = item;
    sift_up(len++);
}

int get_min()
{
    swap(heap[0], heap[--len]);
    sift_down(0);
    return heap[len];
}


void dijkstra(int start)
{
    for (int i = 0; i < N; i++) {
        weight[i] = infinity;
    }
    weight[start] = 0;

    heap_add(start);
    while (len > 0) {
        int i = get_min();
        visited[i] = true;
        for (int k = 0; k < idx[i]; k++) {
            int j = adj[i][k];
            int cost = get_cost(i, j);
            if (!visited[j] && weight[j] > weight[i] + cost) {
                weight[j] = weight[i] + cost;
                indices[j] = i;
                if (!in[j])
                    in[j] = true, heap_add(j);
            }
        }
    }
}


int main()
{
    long long a, b, oo = 1;
    for (int i = 0; i < digit; i++) {
        p[digit-i-1] = oo, oo *= 10;
    }

    scanf("%d", &N);
    for (int i = 0; i < digit; i++) {
        scanf("%d", &cost[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%lld", &oo);
        number[i] = {oo, i};
    }

    a = number[0].first;
    b = number[N-1].first;

    sort(number, number + N);
    for (int i = 0; i < N; i++) {
        add_next(i);
    }
    int x = get_idx(a), y = get_idx(b);

    dijkstra(x);
    if (!visited[y])
        return printf("%d\n", -1), 0;
    else
        printf("%d\n", weight[y]);

    int l = 0;
    for (int i = y; i != x; i = indices[i]) {
        idx[l++] = i;
    }
    idx[l++] = x;
    printf("%d\n", l);
    len = l;
    for (int i = 0; i < len; i++) {
        printf("%d ", number[idx[--l]].second + 1);
    }
    return 0;
}
