class Solution {
public:
int lcs(int i,int j,string &s , string &b,vector<vector<int>>&dp){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==b[j])return dp[i][j]= 1+lcs(i-1,j-1,s,b,dp);
    return dp[i][j]=max(lcs(i,j-1,s,b,dp),lcs(i-1,j,s,b,dp));
}
    int longestCommonSubsequence(string s, string b) {
        int n = s.size();
        int m = b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};