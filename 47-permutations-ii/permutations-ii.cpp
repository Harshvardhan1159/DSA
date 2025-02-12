class Solution {
public:
   void func(vector<int>& nums,vector<vector<int>>&ans,unordered_map<int,int>&mp,int idx, int n){
    if(idx==n){
        ans.push_back(nums);
        return;
    }
  

     unordered_set<int> used;
    
    for(int i=idx;i<n;i++){
         if (used.find(nums[i]) != used.end()) continue;
         used.insert(nums[i]);
        swap(nums[idx],nums[i]);
        func(nums,ans,mp,idx+1,n);
        swap(nums[idx],nums[i]);

        
    }
   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>>ans;
         unordered_map<int,int>mp;
         func(nums,ans,mp,0,nums.size());
         return ans;
    }
};