class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        // Push all initially rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        int lvl = 0;
        while(!q.empty()) {
            auto [time, cell] = q.front();
            int r = cell.first;
            int c = cell.second;
            q.pop();
            lvl = max(lvl, time);

            for(int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == -1) {
                    q.push({time + 1, {nr, nc}});
                    vis[nr][nc] = 1;
                    grid[nr][nc] = 2;
                }
            }
        }

        // Check for any fresh orange left
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return lvl;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        return bfs(grid, vis);
    }
};
