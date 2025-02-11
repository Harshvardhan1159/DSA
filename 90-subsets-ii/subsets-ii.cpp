class Solution {
public:
void func(vector<int>&nums,vector<vector<int>>&ans,vector<int>& temp,int idx,int n, unordered_map<int,int>&mp){
    if(idx==n){
        ans.push_back(temp);
        return;
    }
    int x = mp[nums[idx]];
    func(nums,ans,temp,idx+1,n,mp);
    for(int i=0;i<x;i++){
     temp.push_back(nums[idx]);    //included
     func(nums,ans,temp,idx+1,n,mp);
    
    }
    for(int i=0;i<x;i++){
        temp.pop_back();
    }

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
       unordered_map<int,int>mp;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>dem;
        for(auto i:mp){
            dem.push_back(i.first);
        }
        func(dem,ans,temp,0,dem.size(),mp);
        return ans;

    }
};