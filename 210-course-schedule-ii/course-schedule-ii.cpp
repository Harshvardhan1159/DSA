class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> indegree(num, 0);
        vector<int> topo;
        vector<vector<int>> adj(num);

        for (auto i : pre) {
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);  // v -> u
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < num; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto i : adj[node]) {
                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }
        }

        if (topo.size() != num) return {}; // Cycle detected
        return topo;
    }
};
