class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans ="";
        string x = strs[0];
        int k = strs.size();
        string y = strs[k-1];
        int n = x.size();
        for(int i=0;i<n;i++){
            if(x[i]!=y[i]){
                break;
            }else{
                ans+=x[i];
            }
        }
        return ans;
    }
};