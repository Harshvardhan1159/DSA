class Solution {
public:
    int dp[100001];
    int solve(int i,int n,vector<int>& costs){
        if(i==n) return 0;
        if(i>n) return 1e8;
        if(dp[i]!=-1) return dp[i];
        int one=1e9,two=1e9,three=1e9;
        if(i+1<=n){
            one = (costs[i] + 1) + solve(i+1,n,costs);
        }
       if(i+2 <= n){
         two = (costs[i+1] + 4) + solve(i+2,n,costs);
       }
       if(i+3 <= n){
            three = (costs[i+2]+9) + solve(i+3,n,costs);
       }

       return dp[i] = min(one,min(two,three));
    }
    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,costs);
    }
};