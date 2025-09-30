
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;

        for (int x : nums) {
            maxi = max(maxi, (long long)x);
            mini = min(mini, (long long)x);
        }

        return (maxi - mini) * k;
    }
};
