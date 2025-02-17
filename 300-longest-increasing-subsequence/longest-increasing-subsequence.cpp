class Solution {
public:
   int func(vector<int>& nums,int i,int j,int n,vector<vector<int>>&dp){
    if(i==n)return 0;
    if(dp[i][j+1]!=-1)return dp[i][j+1];
    int x =0;
    if(j==-1 || nums[i]>nums[j]){
        x = 1+func(nums,i+1,i,n,dp);
    }
    int y = func(nums,i+1,j,n,dp);
    return dp[i][j+1]=max(x,y);
    
   }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(nums,0,-1,n,dp);
    }
};