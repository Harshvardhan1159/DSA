class Solution {
public:
    string removeOuterParentheses(string s) {
       int n = s.size();
       int cnt =0;
       string ans ="";
       for(int i=0;i<n;i++){
         if(s[i]==')')cnt-=1;
        if(cnt!=0)ans+=s[i];
        if(s[i]=='(')cnt+=1;
       
       } 
       return ans;
    }
};