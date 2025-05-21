class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int maxi =0;
        int c =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                c=c+1;
            }
            if(s[i]==')'){
                c=c-1;
            }
            maxi = max(maxi,c);
        }
        return maxi;
    }
};