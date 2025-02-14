class Solution {
public:

    const int mod = 1000000007;

    int helper(string &s, int n, int idx, vector<int> &dp) {
        if (idx == n) return 1;
        if (s[idx] == '0') return 0;
        if (dp[idx] != -1) return dp[idx];

        long long ways = 0;

        // Single-digit decoding
        if (s[idx] == '*') {
            ways = (9LL * helper(s, n, idx + 1, dp)) % mod;
        } else {
            ways = helper(s, n, idx + 1, dp) % mod;
        }

        // Two-digit decoding
        if (idx + 1 < n) {
            if (s[idx] == '*' && s[idx + 1] == '*') {
                ways = (ways + 15LL * helper(s, n, idx + 2, dp)) % mod;
            } else if (s[idx] == '*') {
                if (s[idx + 1] >= '0' && s[idx + 1] <= '6') {
                    ways = (ways + 2LL * helper(s, n, idx + 2, dp)) % mod;
                } else {
                    ways = (ways + helper(s, n, idx + 2, dp)) % mod;
                }
            } else if (s[idx + 1] == '*') {
                if (s[idx] == '1') {
                    ways = (ways + 9LL * helper(s, n, idx + 2, dp)) % mod;
                } else if (s[idx] == '2') {
                    ways = (ways + 6LL * helper(s, n, idx + 2, dp)) % mod;
                }
            } else {
                int num = stoi(s.substr(idx, 2));
                if (num >= 10 && num <= 26) {
                    ways = (ways + helper(s, n, idx + 2, dp)) % mod;
                }
            }
        }

        return dp[idx] = ways;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> dp(s.size(), -1);
        return helper(s, s.size(), 0, dp);
    }
};