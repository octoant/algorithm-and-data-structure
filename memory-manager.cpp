//
// Created by Bobur on 20.03.2021
//
#include <bits/stdc++.h>

class Segment {
public:
    int start, end, index;

    Segment(int start, int end, int index) {
        this->start = start;
        this->end   = end;
        this->index = index;
    }
};

class Node {
public:
    Node *left, *right;
    Segment *data;

    Node(Node *left, Node *right, Segment *data) {
        this->left  = left;
        this->right = right;
        this->data  = data;

        this->collapse();
    }

    int length() {
        return data->end - data->start + 1;
    }
    void remove() {
        if (left)  left->right = right;
        if (right) right->left = left;
        delete data;
    }

private:
    void collapse() {
        if (left)  left->right = this;
        if (right) right->left = this;
    }
};


int main() {



    return 0;
}