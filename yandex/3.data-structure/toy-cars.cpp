//
// Created by Bobur on 26.03.2021
//
#include <bits/stdc++.h>

#define parent(i) (i - 1) >> 1
#define left(i) (i << 1) + 1
#define right(i) (i << 1) + 2

int n, k, p;
int len = 0, heap[100000];
int idx[100000];
std::vector<int> prior[100000];
int seq[500000];

void swap(int i, int j)
{
    std::swap(heap[i], heap[j]);
    std::swap(idx[heap[i]], idx[heap[j]]);
}

bool greater(int i, int j)
{
    if (!prior[heap[i]].empty() && !prior[heap[j]].empty())
        return prior[heap[i]].front() > prior[heap[j]].front();
    else
        return prior[heap[i]].empty() && !prior[heap[j]].empty();
}

void siftup(int i)
{
    while (i && greater(i, parent(i))) {
        swap(i, parent(i));
        i = parent(i);
    }
}

void siftdown(int i)
{   while(1) {
        int j = i;
        if (left(j) < len && greater(left(j), i))
            i = left(j);
        if (right(j) < len && greater(right(j), i))
            i = right(j);
        if (i != j) swap(i, j);
        else break;
    }
}

void add(int item)
{
    idx[item] = len;
    heap[len] = item;
    siftup(len++);
}

void remove()
{
    swap(0, --len);
    idx[heap[len]] = -1;
    siftdown(0);
}

int main()
{
    std::cin >> n >> k >> p;
    memset(idx, -1, n * sizeof(int));
    for (int i = 0; i < p; i++)
    {
        std::cin >> seq[i];
        seq[i]--;
        prior[seq[i]].push_back(i);
    }
    int answer = 0;
    for (int i = 0; i < p; i++)
    {
        prior[seq[i]].erase(prior[seq[i]].begin());

        if (idx[seq[i]] != -1)
        {
            siftup(idx[seq[i]]);
            continue;
        }
        if (len < k)
        {
            add(seq[i]);
        }
        else
        {
            remove();
            add(seq[i]);
        }
        answer++;
    }
    std::cout << answer << std::endl;
    return 0;
}
