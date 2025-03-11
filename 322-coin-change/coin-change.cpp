class Solution {
public:
    int func(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
        if(i==0){
            if(amount%coins[i]==0){
                return amount/coins[i];
            }else{
                return 1e8;
            }
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
         int take = 1e8;
         if(amount>=coins[i]){
                     take = 1+func(coins,amount-coins[i],i,dp);
         }
        int nt = func(coins,amount,i-1,dp);
        return dp[i][amount]=min(take,nt);
    }
    int coinChange(vector<int>& coins, int amount) {
     int n = coins.size();
     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    
    int ans =func(coins,amount,n-1,dp); 
    if(ans == 1e8){
        return -1;
    }  
    return  ans;
    }
};