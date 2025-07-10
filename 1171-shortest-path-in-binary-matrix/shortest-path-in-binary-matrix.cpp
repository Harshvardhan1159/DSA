class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        vis[0][0] = 1;

        int drow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dcol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            int steps = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            if (r == n - 1 && c == n - 1)
                return steps;

            for (int i = 0; i < 8; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    grid[nr][nc] == 0 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({steps + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};
