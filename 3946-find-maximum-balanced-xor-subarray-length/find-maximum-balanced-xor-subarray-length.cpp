class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>,int>mp;
        mp[{0,0}]=-1;
        int n = nums.size();
        int even =0;
        int odd =0;
        int sum=0;
        int ans =0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even++;
            }else{
                odd++;
            }
            sum^=nums[i];
            if(mp.find({sum,even-odd})!=mp.end()){
                ans=max(ans,i-mp[{sum,even-odd}]);
            }
            if(mp.find({sum,even-odd})==mp.end()){
                mp[{sum,even-odd}]=i;
            }
            
        }
        return ans;
    }
};