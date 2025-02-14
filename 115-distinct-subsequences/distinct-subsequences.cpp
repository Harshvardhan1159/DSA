class Solution {
public:
    int func(string &s, string &t,int n ,int m,int i,int j, vector<vector<int>>&dp){
      if(j<0)return 1;
      if(i<0)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      if(s[i]!=t[j]) return dp[i][j]= func(s,t,n,m,i-1,j,dp);
      return dp[i][j]=func(s,t,n,m,i-1,j-1,dp)+func(s,t,n,m,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(s,t,n,m,n-1,m-1,dp);
    }
};