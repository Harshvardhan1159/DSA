class Solution {
public:
    int f(int i,int n,int buy,vector<int>& prices){
     if(i>=n)return 0;
   int profit =0;
  
   if(buy){
    profit=max(-prices[i]+f(i+1,n,0,prices),f(i+1,n,1,prices));
   }else{
    profit= max(prices[i]+f(i+2,n,1,prices),f(i+1,n,0,prices));
   }
   return profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,-1));
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n+1][0]=0;
        dp[n+1][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit =0;
                if(buy){
           profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
           }else{
           profit= max(prices[i]+dp[i+2][1],dp[i+1][0]);
            }
            dp[i][buy]= profit;

            }
        }
        return dp[0][1];
    }
};