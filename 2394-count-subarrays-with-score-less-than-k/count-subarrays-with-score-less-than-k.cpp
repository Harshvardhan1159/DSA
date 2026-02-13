class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int n = nums.size();
        long long sum = 0;
        int l = 0;

        for(int r = 0; r < n; r++) {
            sum += nums[r];

            // shrink window until valid
            while(l <= r && sum * (r - l + 1) >= k) {
                sum -= nums[l];
                l++;
            }

            // all subarrays ending at r are valid
            ans += (r - l + 1);
        }

        return ans;
    }
};
