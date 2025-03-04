class Solution {
public:
   int func(int r,int c, vector<vector<int>>&dp){
    if(r<0 || c<0)return 0;
    if(r==0 && c==0) return 1;
    if(dp[r][c]!=-1)return dp[r][c];
    int x = func(r-1,c,dp);
    int y = func(r,c-1,dp);
    return dp[r][c]=x+y;

   }
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,dp);
    }
};