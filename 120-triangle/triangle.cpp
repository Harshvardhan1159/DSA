class Solution {
public:
    int func(int r, int c, int n, vector<vector<int>>& arr,vector<vector<int>>&dp) {
        if (r == n - 1) return arr[r][c];  
        if(dp[r][c]!=-1)return dp[r][c];
        int x = arr[r][c] + func(r + 1, c, n, arr,dp);
        int y = arr[r][c] + func(r + 1, c + 1, n, arr,dp);
        
        return dp[r][c]=min(x, y);
    }

    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=arr[n-1][i];
        }
        for(int r=n-2;r>=0;r--){
            for(int c =0;c<=r;c++){
                  int x = arr[r][c] + dp[r+1][c];
                  int y = arr[r][c] + dp[r+1][c+1];
        
                   dp[r][c]=min(x, y);
            }
        }
        return dp[0][0];

        // return func(0, 0, n, triangle,dp);
    }
};
