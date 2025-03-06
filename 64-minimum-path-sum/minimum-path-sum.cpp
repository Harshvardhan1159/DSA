class Solution {
public:
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return 1e9; 
        if (dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + func(i - 1, j, grid, dp);
        int left = grid[i][j] + func(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
             int x = (i > 0) ? grid[i][j]+dp[i-1][j] : 1e9; 
                int y = (j > 0) ?grid[i][j]+ dp[i][j-1] : 1e9;
                 dp[i][j]=min(x,y);
   
            }
        }
       return dp[n-1][m-1];
    }
       
};
