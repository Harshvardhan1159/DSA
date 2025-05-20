class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string x = strs[0];
        string y = strs[n-1];
       int j = x.size();
       string ans ="";
       for(int i=0;i<j;i++){
        if(x[i]==y[i]){
            ans+=x[i];
        }else{
            break;
        }
       }
        return ans;
    }
};