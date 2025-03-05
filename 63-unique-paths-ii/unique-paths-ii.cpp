class Solution {
public:
    int func(vector<vector<int>>& v,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        if(v[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int x = (i-1>=0)?func(v,i-1,j,dp):0;
        int y = (y-1>=0)?func(v,i,j-1,dp):0;
        return dp[i][j]= x+y;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n= v.size();
        int m = v[0].size();
        if(v[0][0]==1)return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(v,n-1,m-1,dp);
    }
};