class Solution {
public:
    int f(vector<int>& nums, int target,int sum,int id){
        if(id==nums.size() && sum==target)return 1;
        if(id==nums.size())return 0;
        int pos= f(nums,target,sum+nums[id],id+1);
        int neg = f(nums,target,sum-nums[id],id+1);
        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums,target,0,0);
    }
};