class Solution {
public:

    void f(int idx,vector<int>& c, int t, vector<int>&dem,vector<vector<int>>&ans){
        if(t==0){
            ans.push_back(dem);
            return ;
        }
        for(int i=idx;i<c.size();i++){
            if(i>idx && c[i]==c[i-1])continue;
            if(c[i]>t)break;
            dem.push_back(c[i]);
            
            f(i+1,c,t-c[i],dem,ans);
            dem.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>>ans;
        vector<int>dem;
        f(0,c,t,dem,ans);
        return ans;
    }
};