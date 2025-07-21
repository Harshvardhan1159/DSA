class Solution {
public:
    bool possible(vector<int>& nums, int k, int mid) {
        int cnt = 1, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                cnt++;
                if(cnt > k) return false;
                sum = nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int e = *max_element(nums.begin(), nums.end());  // fix lower bound
        int h = 0;
        for(int x : nums) h += x;
        int ans = -1;

        while(e <= h) {
            int mid = e + (h - e) / 2;
            if(possible(nums, k, mid)) {
                ans = mid;
                h = mid - 1;  // try smaller largest sum
            } else {
                e = mid + 1;
            }
        }
        return ans;
    }
};
