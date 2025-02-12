class Solution {
public:
   void func(vector<int>& nums,vector<vector<int>>&ans,vector<int>&temp,int idx, int n){
    if(idx==n){
        ans.push_back(nums);
        return;
    }

    for(int i=idx;i<n;i++){
        swap(nums[idx],nums[i]);
        func(nums,ans,temp,idx+1,n);
        swap(nums[idx],nums[i]);
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>temp;
         func(nums,ans,temp,0,nums.size());
         return ans;
    }
};