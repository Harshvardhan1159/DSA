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
     vector<vector<int>>dp(n,vector<int>(amount+1));
     for(int i=0;i<=amount;i++){
         if(i%coins[0]==0){
            dp[0][i]=i/coins[0];
         }else{
            dp[0][i]=1e8;
         }
     }

     for(int i=1;i<n;i++){
        for(int a=0;a<=amount;a++){
              int take = 1e8;
         if(a>=coins[i]){
                     take = 1+dp[i][a-coins[i]];
         }
        int nt = dp[i-1][a];
         dp[i][a]=min(take,nt);
        }
     }
    
    int ans =dp[n-1][amount]; 
    if(ans == 1e8){
        return -1;
    }  
    return  ans;
    }
};