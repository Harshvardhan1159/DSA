class Solution {
public:
    int f(int i,int n,int buy,int c,vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(i==n)return 0;
        if(c>=2)return 0;
        if(dp[i][buy][c]!=-1)return dp[i][buy][c];
        int profit=0;
        if(buy){
            profit =max(-prices[i]+f(i+1,n,0,c,prices,dp),f(i+1,n,1,c,prices,dp));
        }else{
            profit=max(prices[i]+f(i+1,n,1,c+1,prices,dp),f(i+1,n,0,c,prices,dp));

        }
        return dp[i][buy][c]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy =0;buy<=1;buy++){
                for(int c=0;c<2;c++){
                    int profit =0;
                    if(buy){
            profit =max(-prices[i]+dp[i+1][0][c],dp[i+1][1][c]);
        }else{
            profit=max(prices[i]+dp[i+1][1][c+1],dp[i+1][0][c]);

        }
        dp[i][buy][c] = profit;
                }
                
            }
        }
        return dp[0][1][0];
    }
};