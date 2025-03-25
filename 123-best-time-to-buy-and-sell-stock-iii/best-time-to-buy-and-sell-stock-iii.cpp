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
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,n,1,0,prices,dp);
    }
};