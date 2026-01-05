class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.size();
        string ans;
        
        for(int i=0;i<n;i++){
            string x ="";
            while(i<n && s[i]!=' '){
                x+=s[i];
                i++;
            }
           reverse(x.begin(),x.end());
           if(x.length()>0){
            ans+=" "+x;
           }
        }
        return ans.substr(1);
    }
};