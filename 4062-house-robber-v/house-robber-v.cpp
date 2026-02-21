class Solution {
public:
    long long dp[100005][2];

    long long help(int ind, int n, vector<int>& nums, vector<int>& colors, int pretaken) {
        
        if (ind >= n) return 0;

        if (dp[ind][pretaken] != -1) 
            return dp[ind][pretaken];

        // Not Pick
        long long nt = help(ind + 1, n, nums, colors, 0);

        // Pick
        long long pick = 0;

        if (pretaken == 0) {
            pick = nums[ind] + help(ind + 1, n, nums, colors, 1);
        } 
        else {
            if (colors[ind] != colors[ind - 1]) {
                pick = nums[ind] + help(ind + 1, n, nums, colors, 1);
            }
        }

        return dp[ind][pretaken] = max(pick, nt);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        memset(dp, -1, sizeof(dp));
        return help(0, nums.size(), nums, colors, 0);
    }
};