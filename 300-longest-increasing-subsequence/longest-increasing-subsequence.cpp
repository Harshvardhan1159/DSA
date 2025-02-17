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
        int maxi = 1;                                           
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     dp[n][i]=0;
        // }
        // for(int i=0;i<)
       return maxi;
        
    }
};