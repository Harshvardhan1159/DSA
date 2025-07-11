class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& i : f) {
            int u = i[0], v = i[1], w = i[2];
            adj[u].push_back({v, w});
        }

        int ans = INT_MAX;
        queue<pair<int, pair<int, int>>> q; // {node, {stops, cost}}
        q.push({src, {-1, 0}});

        // visited[node][stops] = minimum cost to reach node using stops
        vector<vector<int>> visited(n, vector<int>(k + 2, INT_MAX));
        visited[src][0] = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int stops = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if (node == dst && stops <= k) {
                ans = min(ans, cost);
                continue;
            }

            if (stops == k) continue;

            for (auto i : adj[node]) {
                int adjnode = i.first;
                int wt = i.second;

                if (cost + wt < visited[adjnode][stops + 1]) {
                    visited[adjnode][stops + 1] = cost + wt;
                    q.push({adjnode, {stops + 1, cost + wt}});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
