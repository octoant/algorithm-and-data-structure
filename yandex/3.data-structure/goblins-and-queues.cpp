//
// Created by bobur on 2/28/21.
//
#include <bits/stdc++.h>

int x, n;
std::deque<int> left, right;

int main() {

    std::cin >> n;

    char sign;
    while (n--)
    {
        std::cin >> sign;
        if (sign == '+')
        {
            std::cin >> x;
            right.push_back(x);
        }
        else if (sign == '*')
        {
            std::cin >> x;
            right.push_front(x);
        }
        else
        {
            std::cout << left.front() << "\n";
            left.pop_front();
        }
        if (left.size() < right.size())
        {
            left.push_back(right.front());
            right.pop_front();
        }
    }
    return 0;
}
