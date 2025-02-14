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
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return lcs(s.size()-1,b.size()-1,s,b,dp);
    }
};