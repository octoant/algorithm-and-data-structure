#include <bits/stdc++.h>

struct segment {

    int begin, end, len;
    bool used;

    segment(int begin, int end, bool used);
};

segment::segment(int begin, int end, bool used) {

    this->begin = begin;
    this->end   = end;
    this->len   = std::abs(begin - end) + 1;
    this->used  = used;
}

struct node {

    node *left, *right;
    segment *data;

    node(node *left, node *right, segment *data);

    void remove() {
        if (left)  left->right = right;
        if (right) right->left = left;
    }
};

node::node(node *left, node *right, segment *data) {

    this->left  = left;
    this->data  = data;
    this->right = right;

    if (left)  left->right = this;
    if (right) right->left = this;
}
