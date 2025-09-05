class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int x = f(n-1,dp);
        int y =0;
        
        if(n-2>=0){
            y= f(n-2,dp);
        }
        return dp[n]=x+y;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int x = dp[i-1];
        int y =0;
        
        if(i-2>=0){
            y= dp[i-2];
        }
         dp[i]=x+y;
        }
        return dp[n];
    }
};