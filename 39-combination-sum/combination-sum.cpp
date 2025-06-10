class Solution {
public:
void f(int i,vector<int>& c, int t,int sum, vector<vector<int>>&ans,vector<int>&dem){
    if(sum>t|| i>=c.size())return;
    if(sum==t){
        ans.push_back(dem);
        return;
    }
    dem.push_back(c[i]);
    sum+=c[i];
    f(i,c,t,sum,ans,dem);
    dem.pop_back();
    sum-=c[i];
    f(i+1,c,t,sum,ans,dem);
}
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
         vector<vector<int>>ans;
         vector<int>dem;
         f(0,c,t,0,ans,dem);
         return ans;
    }
};