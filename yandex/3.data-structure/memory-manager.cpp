//
// Created by Bobur on 25.03.2021
//
#include <bits/stdc++.h>

struct node
{
    int start, end, idx, used;
    struct node *left;
    struct node *right;

    node(struct node *left, struct node *right);

    node * set(int start, int end, int idx, int used);

    void remove();

    void collapse_borders();
};

node::node(struct node *left, struct node *right)
{
    this->left = left;
    this->right = right;
    this->collapse_borders();
}

node * node::set(int start, int end, int idx, int used)
{
    this->start = start;
    this->end = end;
    this->idx = idx;
    this->used = used;
    return this;
}

void node::remove()
{
    if (left) left->right = right;
    if (right) right->left = left;
}

void node::collapse_borders()
{
    if (left) left->right = this;
    if (right) right->left = this;
}

int parent(int i)
{
    return (i - 1) >> 1;
}

int left_child(int i)
{
    return (i << 1) + 1;
}

int right_child(int i)
{
    return (i << 1) + 2;
}

int n, m, len = 0;
node *heap[100000], *request[100000];

void swap(int i, int j)
{
    struct node *tmp;
    tmp = heap[i], heap[i] = heap[j], heap[j] = tmp;
    heap[i]->idx = i;
    heap[j]->idx = j;
}

int length(struct node *node)
{
    return node->end - node->start + 1;
}

bool greater(int i, int j)
{
    return length(heap[i]) > length(heap[j]);
}

void siftdown(int i)
{
    while (1) {
        int j = i;
        if (left_child(j) < len && greater(left_child(j), i)) {
            i = left_child(j);
        }
        if (right_child(j) < len && greater(right_child(j), i)) {
            i = right_child(j);
        }
        if (i != j) swap(i, j);
        else break;
    }
}

void siftup(int i)
{
    while (i && greater(i, parent(i))) {
        swap(i, parent(i));
        i = parent(i);
    }
}

void add(struct node *node)
{
    node->idx = len;
    heap[len] = node;
    siftup(len++);
}

void remove(int i)
{
    swap(i, --len);
    siftup(i);
    siftdown(i);
}

int main()
{
    std::cin >> n >> m;

    heap[0] = (new node(0, 0))->set(1, n, len++, 0);

    for (int i = 0 ; i < m ; i++) {
        int x;
        std::cin >> x;

        if (x > 0) {
            if (!len || length(heap[0]) < x) {
                {
                    std::cout << -1 << std::endl;
                }
            } else {
                struct node *tmp = heap[0];
                {
                    std::cout << tmp->start << std::endl;
                }
                request[i] = (new node(tmp->left, tmp))->set(tmp->start, tmp->start + x - 1, -1, 1);

                tmp->start += x;

                if (length(tmp)) {
                    siftdown(tmp->idx);
                } else {
                    tmp->remove();
                    swap(0, --len);
                    siftdown(0);
                    delete tmp;
                }
            }
        } else {

            x = -(x + 1);

            struct node *tmp = request[x];

            if (!tmp) continue;

            struct node *left = request[x]->left;
            struct node *right = request[x]->right;

            if (left && !left->used && right && !right->used)
            {
                left->end = right->end;
                siftup(left->idx);
                tmp->remove();
                delete tmp;
                remove(right->idx);
                right->remove();
                delete right;
            }
            else if (left && !left->used)
            {
                left->end = tmp->end;
                siftup(left->idx);
                tmp->remove();
                delete tmp;
            }
            else if (right && !right->used)
            {
                right->start = tmp->start;
                siftup(right->idx);
                tmp->remove();
                delete tmp;
            }
            else
            {
                tmp->used = false;
                add(tmp);
            }
        }
    }
    return 0;
}
