class Solution {
public:
    int f(int n, int m, string &s, string &x,vector<vector<int>>&dp) {
        if (n == 0 || m == 0) return 0;
        if(dp[n][m]!=-1)return dp[n][m];

        if (s[n-1] == x[m-1]) {
            return dp[n][m]=1 + f(n - 1, m - 1, s, x,dp);
        } else {
            return dp[n][m]=max(f(n - 1, m, s, x,dp), f(n, m - 1, s, x,dp));
        }
    }

    int minInsertions(string s) {
        string x = s;
        
        reverse(x.begin(), x.end());
     
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int lcs = f(n, n, s, x,dp);

        return n - lcs;
    }
};
