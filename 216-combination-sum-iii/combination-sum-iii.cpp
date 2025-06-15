class Solution {
public:
void f(int i,int k,int n,vector<int>&nums,vector<int>&dem,vector<vector<int>>&ans){
     if(n==0 &&k==0){
        ans.push_back(dem);
        return;
    }

    if(i>=nums.size() || k<0)return;
    
   
    dem.push_back(nums[i]);
    f(i+1,k-1,n-nums[i],nums,dem,ans);
    dem.pop_back();
    f(i+1,k,n,nums,dem,ans);
}
    vector<vector<int>> combinationSum3(int k, int n) {
     vector<int>nums={1,2,3,4,5,6,7,8,9};
         vector<vector<int>> ans;
         vector<int>dem;
         f(0,k,n,nums,dem,ans);
         return ans;
    }
};