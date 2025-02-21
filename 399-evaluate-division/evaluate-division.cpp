#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dst, unordered_set<string>& visited, double product, double &ans) {
        if (visited.find(src) != visited.end()) return;
        
        visited.insert(src);
        if (src == dst) {
            ans = product;
            return;
        }
        
        for (auto p : adj[src]) {
            string v = p.first;
            double val = p.second;
            dfs(adj, v, dst, visited, product * val, ans);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = equations.size();

        for (int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }

        vector<double> results;
        for (auto &i : queries) {
            string src = i[0];
            string des = i[1];
            double ans = -1.0;
            double product = 1.0;

            if (adj.find(src) != adj.end() && adj.find(des) != adj.end()) {
                unordered_set<string> visited;
                dfs(adj, src, des, visited, product, ans);
            }

            results.push_back(ans);
        }

        return results;
    }
};
