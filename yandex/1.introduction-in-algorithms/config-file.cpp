//
// Created by Bobur on 2/26/21.
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    unordered_map<string, vector<string>> mp;
    vector<vector<string>>                tmp {{}};
    pair<string, string>                  p;

    string s;
    while (cin >> s) {
        if (s == "{") tmp.push_back({});
        else if (s == "}") {
            for (int i = 0; i < tmp.back().size(); i++)
                mp[tmp.back()[i]].pop_back();
            tmp.pop_back();
        } else {
            int i = s.find('=');
            p = make_pair(s.substr(0, i), s.substr(i + 1));
            if ('0' <= *(p.second.end()-1) && *(p.second.end()-1) <= '9') {
                if (mp.find(p.first) == mp.end()) {
                    mp.insert({p.first, {p.second}});
                    tmp.back().push_back(p.first);
                } else {
                    mp[p.first].push_back(p.second);
                    tmp.back().push_back(p.first);
                }
            } else {
                if (mp.find(p.second) == mp.end()) {
                    mp.insert({p.second, {"0"}});
                    tmp.back().push_back(p.second);
                } else if (mp[p.second].empty()) {
                    mp[p.second].push_back("0");
                    tmp.back().push_back(p.second);
                }
                if (mp.find(p.first) == mp.end()) {
                    mp.insert({p.first, {mp[p.second].back()}});
                    tmp.back().push_back(p.first);
                } else {
                    mp[p.first].push_back(mp[p.second].back());
                    tmp.back().push_back(p.first);
                }
                cout << mp[p.first].back() << "\n";
            }
        }
    }
    return 0;
}
