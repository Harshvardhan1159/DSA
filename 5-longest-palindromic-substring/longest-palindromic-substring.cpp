class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return ""; 
        
        int len = 1;
        int idx = 0;  // Fix: Start from a valid index
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Base case: Single-character substrings are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Fill DP table
        for (int l = 2; l <= n; l++) {  // Length of substring
            for (int i = 0; i < n - l + 1; i++) {  
                int j = i + l - 1;  // Fix: Correct index calculation

                if (s[i] == s[j]) {
                    if (l == 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }

                    if (dp[i][j] && j - i + 1 > len) {  // Fix: Condition check
                        len = j - i + 1;
                        idx = i;
                    }
                }
            }
        }

        return s.substr(idx, len);  // Extract substring
    }
};
