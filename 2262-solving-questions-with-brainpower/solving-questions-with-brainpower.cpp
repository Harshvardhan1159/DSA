class Solution {
public:
   long long func(int i,int n ,vector<vector<int>>& questions,vector<long long>&dp){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    long long nt = func(i+1,n,questions,dp);
    long long take = questions[i][0]+func(i+questions[i][1]+1,n,questions,dp);
    return dp[i]=max(nt,take);
   }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); 

        for (int i = n - 1; i >= 0; i--) {
            long long not_take = dp[i + 1];
            long long take = questions[i][0] + (i + questions[i][1] + 1 < n ? dp[i + questions[i][1] + 1] : 0);
            dp[i] = max(not_take, take);
        }

        return dp[0];
    }
};