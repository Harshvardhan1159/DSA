class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;

        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            ans.push_back(weights[i] + weights[i + 1]);
        }

        sort(ans.begin(), ans.end());

        long long mini = 0, msxi = 0;
        for (int i = 0; i < k - 1; i++) {
            mini += ans[i];
            msxi += ans[n - 2 - i];
        }

        return msxi - mini;
    }
};