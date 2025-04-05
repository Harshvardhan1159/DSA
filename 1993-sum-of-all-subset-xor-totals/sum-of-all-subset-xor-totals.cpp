class Solution {
public:
int solve(vector<int>& nums,int idx,int ans){
 if(idx==nums.size()){
  return ans;
 }
  int include = solve(nums, idx + 1, ans^nums[idx]);
  int exclude = solve(nums, idx + 1, ans);

    return include + exclude;



}
    int subsetXORSum(vector<int>& nums) {
       int ans =0;
       return solve(nums,0,ans); 
    }
};