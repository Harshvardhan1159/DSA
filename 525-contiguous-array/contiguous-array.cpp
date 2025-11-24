class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
       
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                nums[i] = -1;
            }
        }
        
       
        unordered_map<int, int> map;
        int sum = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];

            if(sum == 0) {
                ans = i + 1;
            }

            if(map.find(sum) != map.end()) {
                int len = i - map[sum];
                ans = max(len, ans);
            } 
            if(map.find(sum)==map.end()){
                map[sum] = i;
            }
        }
        
        return ans;
    }
};
