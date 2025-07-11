class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> price(n, INT_MAX);
        price[src] = 0;

        // Queue format: {node, {stops, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, 0}});

        while (!q.empty()) {
            int node = q.front().first;
            int stops = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if (stops > k) continue;

            for (auto& [next, wt] : adj[node]) {
                int newCost = cost + wt;

                // Only push if we found a cheaper path
                if (newCost < price[next]) {
                    price[next] = newCost;
                    q.push({next, {stops + 1, newCost}});
                }
            }
        }

        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};
