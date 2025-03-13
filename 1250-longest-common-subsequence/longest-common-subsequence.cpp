class Solution {
public:
   int func(int n,int m , string &s,string &t,vector<vector<int>>&dp){
    if(n==0 || m==0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];
    if(s[n-1]==t[m-1]){
        return dp[n][m]=1+func(n-1,m-1,s,t,dp);
    } else {
            return dp[n][m]= max(func(n - 1, m, s, t,dp), func(n, m - 1, s, t,dp)); // Take max of both choices
        }
   }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j =1;j<=m;j++){
                 if(text1[i-1]==text2[j-1]){
             dp[i][j]=1+dp[i-1][j-1];
                 } else {
             dp[i][j]= max(dp[i-1][j],dp[i][j-1]); // Take max of both choices
        }
            }
        }

        return dp[n][m];
    }
};