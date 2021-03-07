//
// Created by Bobur on 2/26/21.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::unordered_map<std::string, std::vector<std::string>> mp;
    std::vector<std::vector<std::string>>                     tmp {{}};
    std::pair<std::string, std::string>                       p;

    std::string s;
    while (std::cin >> s) {
        if (s == "{") tmp.push_back({});
        else if (s == "}") {
            for (int i = 0; i < tmp.back().size(); i++)
                mp.at(tmp.back()[i]).pop_back();
            tmp.pop_back();
        } else {
            int i = s.find('=');
            p = std::make_pair(s.substr(0, i), s.substr(i + 1));
            if ('0' <= *(p.second.end()-1) && *(p.second.end()-1) <= '9') {
                if (mp.find(p.first) == mp.end()) {
                    mp.insert({p.first, {p.second}});
                    tmp.back().push_back(p.first);
                } else {
                    mp.at(p.first).push_back(p.second);
                    tmp.back().push_back(p.first);
                }
            } else {
                if (mp.find(p.second) == mp.end()) {
                    mp.insert({p.second, {"0"}});
                    tmp.back().push_back(p.second);
                } else if (mp.at(p.second).empty()) {
                    mp.at(p.second).push_back("0");
                    tmp.back().push_back(p.second);
                }
                if (mp.find(p.first) == mp.end()) {
                    mp.insert({p.first, {mp.at(p.second).back()}});
                    tmp.back().push_back(p.first);
                } else {
                    mp.at(p.first).push_back(mp.at(p.second).back());
                    tmp.back().push_back(p.first);
                }
                std::cout << mp.at(p.first).back() << "\n";
            }
        }
    }
    return 0;
}
