class Solution {
public:
    // int func(string s,int n , int i , int j){
    //     if(i>j)return 0;
    //     if(i==j)return 1;
    //     int count =0;

    //     if(s[i]==s[j]){
    //         count+= 2+func(s,n,i+1,j-1);
    //     }else{ 
    //     count+= max(func(s,n,i+1,j),func(s,n,i,j-1));
    //     }
    //     return count;
    // }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
      
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int l = 2;l<=n;l++){
            for(int i =0;i<n-l+1;i++){
                int j = i+l-1;
                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
   
    }
};