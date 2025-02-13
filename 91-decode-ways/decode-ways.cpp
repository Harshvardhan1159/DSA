class Solution {
public:
  int func(string s, int n, int idx,vector<int>&dp) {
        if (idx == n) return 1; 
        if (s[idx] == '0') return 0; 
        if(dp[idx]!=-1)return dp[idx];

        int ways = func(s, n, idx + 1,dp); 

        if (idx + 1 < n && stoi(s.substr(idx, 2)) <= 26) {
            ways += func(s, n, idx + 2,dp); 
        }

        return dp[idx]=ways;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int>dp(s.size()+1,-1);
        return func(s, s.size(), 0,dp);
    }
};