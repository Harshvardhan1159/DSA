class Solution {
public:
   int func(int n,int m , string &s,string &t,vector<vector<int>>&dp){
    if(n<0 || m<0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];
    if(s[n]==t[m]){
        return dp[n][m]=1+func(n-1,m-1,s,t,dp);
    } else {
            return dp[n][m]= max(func(n - 1, m, s, t,dp), func(n, m - 1, s, t,dp)); // Take max of both choices
        }
   }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,text1,text2,dp);
    }
};