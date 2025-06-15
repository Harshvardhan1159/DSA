class Solution {
public:
void f(int idx,vector<int>& nums,vector<int>& dem, vector<vector<int>>&ans,vector<int>&x){
    if(dem.size()==nums.size()){
        ans.push_back(dem);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(x[i]==0){
        dem.push_back(nums[i]);
        x[i]=1;
        f(0,nums,dem,ans,x);
        x[i]=0;
        dem.pop_back();
        }

    }
}
    vector<vector<int>> permute(vector<int>& nums) {
       int n = nums.size();
       vector<int>dem; 
       vector<vector<int>>ans;
       vector<int>x(n,0);
        f(0,nums,dem,ans,x);
       return ans;
    }
};