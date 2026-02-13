class Solution {
public:
    int dominantIndices(vector<int>& nums) {
       
        int n = nums.size();
         vector<int>dem(n);
        int sum =0;
        int cnt =1;
        for(int i=n-1;i>=0;i--){
          sum+=nums[i];
          dem[i]=(sum/cnt);
          cnt++;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>dem[i])ans++;
        }
        return ans;
    }
};