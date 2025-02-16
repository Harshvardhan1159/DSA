class Solution {
public:
    int func(string s , int idx,vector<vector<bool>>&isp,int n,vector<int>&dp){

        if(idx==n)return -1;
        if(dp[idx]!=-1)return dp[idx];

        int ans = INT_MAX;
    
        for(int i = idx;i<n;i++){
        
       if(isp[idx][i]){
        ans = min(func(s,i+1,isp,n,dp)+1,ans);
       }
        }
        return dp[idx]=ans;
    }
    int minCut(string s) {
        int n =s.size();
        vector<int>dp(n,-1);
        vector<vector<bool>>isp(n+1,vector<bool>(n+1,false));
        for(int i =0;i<n;i++){
            isp[i][i]=true;
        }
        for(int l =2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j = i+l-1;
                if(s[i]==s[j]){
                    if(l==2){
                       isp[i][j] = true;
            } else {
                isp[i][j] = isp[i + 1][j - 1];  
            }
                }
            }
        }
        return func(s,0,isp,n,dp);
        
        
    }
};