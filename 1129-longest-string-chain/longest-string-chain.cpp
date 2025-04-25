class Solution {
public:
   
    static bool comp(const string &a, const string &b) {
        return a.size() < b.size();
    }

   
    bool check(const string &longer, const string &shorter) {
        if (longer.size() != shorter.size() + 1) return false;

        int i = 0, j = 0;
        while (i < longer.size()) {
            if (j < shorter.size() && longer[i] == shorter[j]) {
                i++; j++;
            } else {
                i++;
            }
        }
        return (i == longer.size() && j == shorter.size());
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
