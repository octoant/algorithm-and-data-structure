//
// Created by Bobur on 08.04.2021
//
#include <bits/stdc++.h>

#define parent(i) (i - 1) >> 1
#define left(i) (i << 1) + 1
#define right(i) (i << 1) + 2

const int size = 1e6;

int tree[size]; // segment tree
int soldier[size];
int n, k;

/*
 * Build a segment tree.
 */
int node = 1;
void build_tree(int n, int i)
{
    if (n == 1) {
        soldier[i] = node++;
    }
    else {
        /* Build a tree's child. */
        build_tree((n + 1) >> 1, left(i));
        build_tree((n) >> 1, right(i));
    }
    tree[i] = n;
}

/*
 * Return an index of next killed soldier.
 */
int sum = 0;
int kill_next(const int& k)
{
    sum = sum + k;
    while (sum > tree[0]) {
        sum -= tree[0];
    }
    int i = 0, next = sum--;

    while (tree[i]) {
        tree[i]--;
        if (next <= tree[left(i)]) {
            i = left(i);
        }
        else {
            next -= tree[left(i)];
            i = right(i);
        }
        if (i >= size) break;
    }
    return soldier[parent(i)];
}

int main()
{
    std::cin >> n >> k;

    build_tree(n, 0);
    for (int i = 0; i < n; i++) {
        std::cout << kill_next(k) << " ";
    }
    return 0;
}
