class Solution {
public:
    string largestEven(string s) {
        string ans;
        int n = s.size();
        bool find = false;
        for(int i=n-1;i>=0;i--){
           int x = s[i]-'0';
           if(x%2==0)return s.substr(0,i+1);
        //    if(x%2==1 && find==false){
        //     find = true;
        //     continue;
        //    }
        //    if(find){
        //     ans+=s[i];
        //    }
           
        }
        return ans;
    }
};