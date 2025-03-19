class Solution {
public:
    int func(string &s, string &t, int i, int j,  vector<vector<int>>&dp) {
        if (i == s.size() && j == t.size()) return 0;
        if (i == s.size()) return t.size() - j; // Insert remaining characters of t
        if (j == t.size()) return s.size() - i; // Delete remaining characters of s
        if(dp[i][j]!=-1)return dp[i][j];
        if (s[i] == t[j]) {
            return func(s, t, i + 1, j + 1,dp); // No operation needed
        } else {
            int insertOp = 1 + func(s, t, i, j + 1,dp);  // Insert t[j] into s
            int deleteOp = 1 + func(s, t, i + 1, j,dp);  // Delete s[i]
            int replaceOp = 1 + func(s, t, i + 1, j + 1,dp); // Replace s[i] with t[j]

            return min(insertOp, min(deleteOp, replaceOp));
        }
    }

    int minDistance(string s, string t) {
         int n = s.size();
        int m = t.size();
        
        // DP table initialization
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i; // Deleting remaining characters of s
        }
        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j; // Inserting remaining characters of t
        }

        // Bottom-up DP computation
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1]; // No operation needed
                } else {
                    dp[i][j] = 1 + min({
                        dp[i][j + 1],   // Insert t[j] into s
                        dp[i + 1][j],   // Delete s[i]
                        dp[i + 1][j + 1] // Replace s[i] with t[j]
                    });
                }
            }
        }

        return dp[0][0]; // The minimum edit distance from s[0..n] to t[0..m]
    }
};