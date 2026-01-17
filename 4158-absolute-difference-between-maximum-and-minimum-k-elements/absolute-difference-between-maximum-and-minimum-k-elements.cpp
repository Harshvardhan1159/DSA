class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int x =0;
        int y =0;
        for(int i=n-k;i<n;i++){
            x+=nums[i];
        }
        for(int i=0;i<k;i++){
            y+=nums[i];
        }
        return abs(y-x);
    }
};