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
        vector<vector<int>>dp(n,vector<int>(m));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
             int x = (i > 0) ? dp[i-1][j] : 0; 
                int y = (j > 0) ? dp[i][j-1] : 0;
                 dp[i][j]=x+y;
   
            }
        }
       return dp[n-1][m-1];
    }
};