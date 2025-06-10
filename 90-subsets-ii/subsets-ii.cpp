class Solution {
public:
void f(int idx,vector<vector<int>>&ans,vector<int>&dem,vector<int>& nums){
    
        ans.push_back(dem);
    
    for(int i = idx;i<nums.size();i++){
        if(i>idx && nums[i]==nums[i-1])continue;
        dem.push_back(nums[i]);
        f(i+1,ans,dem,nums);
        dem.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>dem;
        sort(nums.begin(),nums.end());
        f(0,ans,dem,nums);
        return ans;
    }
};