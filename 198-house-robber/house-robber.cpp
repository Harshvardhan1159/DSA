class Solution {
public:
  int func(vector<int>& nums,int idx,vector<int>&dp){
    if(idx==0)return nums[0];
    if(idx<0)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int nottake = func(nums,idx-1,dp);
    int take = nums[idx];
    if(idx-2>=0){
        take+=func(nums,idx-2,dp);
    }
    return dp[idx]=max(take,nottake);
  }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int nottake = dp[i-1];
    int take = nums[i];
    if(i-2>=0){
        take+=dp[i-2];
    }
    dp[i]=max(take,nottake);
        }
       return dp[n-1];
    }
};