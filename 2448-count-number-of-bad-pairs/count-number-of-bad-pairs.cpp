class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans =0;
        for(int i=0;i<n;i++){
      nums[i]=nums[i]-i;
            
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                ans+=i-mp[nums[i]];
            }else{
                ans+=i;
            }

            mp[nums[i]]++;
        }
    return ans;
    }
};