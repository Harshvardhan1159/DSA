class Solution {
public:
   int func(vector<int>& nums,int n , vector<int>&dp,int idx){
    if(idx>n-1)return 0;
    if(dp[idx]!=-1)return dp[idx];
    return dp[idx]=max(nums[idx]+func(nums,n,dp,idx+2),func(nums,n,dp,idx+1));
   }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,-1);
        return func(nums,n,dp,0);
       
    }
};