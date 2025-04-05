class Solution {
public:
     long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int maxdiff =0;
        int maxi =0;
        long long result =0;
        for(int i=0;i<n;i++){
            result = max(result,(long long)maxdiff*nums[i]);
            maxdiff=max(maxdiff,maxi-nums[i]);
            maxi=max(maxi,nums[i]);

        }
            return result;
    }
};