class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for (int num : st) { // loop through unique elements only
            if (st.find(num - 1) != st.end()) continue; // only start from sequence beginning

            int currentNum = num;
            int count = 1;

            while (st.find(currentNum + 1) != st.end()) {
                currentNum++;
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};
