class Solution {
public:
 int func(int i, int n,int buy,vector<int>& prices){

    if(i==n)return 0;
    int profit = 0;
    if(buy){
        profit=max(-prices[i]+func(i+1,n,0,prices),func(i+1,n,1,prices));
    }else{
        profit = max(prices[i]+func(i+1,n,1,prices),func(i+1,n,0,prices));

    }
    return profit;
 }
     int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[i][buy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                } else {
                    dp[i][buy] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][1];  // Start from day 0 with the ability to buy
    }
};