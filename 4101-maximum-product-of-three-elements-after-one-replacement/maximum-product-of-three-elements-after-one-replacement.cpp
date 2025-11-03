class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long ans = 1LL * nums[n-1] * nums[n-2] * 100000;

        return ans;
    }
};