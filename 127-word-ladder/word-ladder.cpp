#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        unordered_set<string> s(word.begin(), word.end());
        
        if (s.find(end) == s.end()) return 0; 

        queue<pair<string, int>> q;
        q.push({begin, 1}); 

        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();

            string src = p.first;
            int step = p.second;

            if (src == end) {
                return step;
            }

            for (int i = 0; i < src.size(); i++) {
                string temp = src; 
                for (char it = 'a'; it <= 'z'; it++) {
                    temp[i] = it;

                    if (s.count(temp)) {
                        s.erase(temp);
                        q.push({temp, step + 1});
                    }
                }
            }
        }

        return 0;
    }
};
