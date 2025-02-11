class Solution {
public:
void func(vector<int>& nums,vector<int>temp,int idx,int n,vector<vector<int>>&ans){
    if(idx==n){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[idx]);
    func(nums,temp,idx+1,n,ans);
    temp.pop_back();
    func(nums,temp,idx+1,n,ans);
}

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        func(nums,temp,0,n,ans);
        return ans;
    }
};