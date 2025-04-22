class Solution {
public:
int func(int n,int m , string s,string t){
    if(n==0 && m==0)return 0;
    if(n==0)return m+1;
    if(m==0)return n+1;


    if(s[n-1]==t[m-1]){
        return func(n-1,m-1,s,t);
    }else{
        int insert = 1+func(n,m-1,s,t);
        int del = 1+func(n-1,m,s,t);
        int replace = 1+func(n-1,m-1,s,t);
        return min(insert,min(del,replace));
    }
}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
      
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 ){
                    dp[0][j]=j;
                }
                if(j==0){
                    dp[i][0]=i;
                }
            }
        }
          dp[0][0]=0;
          for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                     int insert = 1+dp[i][j-1];
        int del = 1+dp[i-1][j];
        int replace = 1+dp[i-1][j-1];
        dp[i][j]=min(insert,min(del,replace));
                }
            }
          }

        return dp[n][m];
    }
};