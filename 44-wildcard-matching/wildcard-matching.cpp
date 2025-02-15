class Solution {
public:
bool allstar(string p, int j){
    bool ans = true;
    for(int i = j;i<p.length();i++){
     if(p[i]!='*'){
        ans= false;
        break;
     }
     
    }
    return ans;
}
   bool func(string s, string p, int i,int j,  vector<vector<int>>&dp){
     
     if(i==s.size()&& j==p.size())return true;
     if(i ==s.size() ){
        if(allstar(p,j))return true;
        return false;
     }
     if(j==p.size())return false;
     if(dp[i][j]!=-1)return dp[i][j];
     bool ans = false;
     bool x = false;
     bool y = false;
     if(p[j]=='*'){
         ans = func(s,p,i,j+1,dp)||func(s,p,i+1,j,dp);
         return dp[i][j]=ans;
     }
     else if(p[j]=='?'){
         x = func(s,p,i+1,j+1,dp);
          return dp[i][j]= x;
     }else{

        
        if(s[i]==p[j]){
            y = func(s,p,i+1,j+1,dp);
        }
        return dp[i][j]= y;
     }


      return dp[i][j]=false;


   }
    bool isMatch(string s, string p) {
     vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));

     return func(s,p,0,0,dp);
    }
};