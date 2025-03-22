class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> mp;
        
        for (auto i : nums1) {
            int x = i[0], y = i[1];
            mp[x] += y;
        }
        for (auto i : nums2) {
            int x = i[0], y = i[1];
            mp[x] += y;
        }

        vector<vector<int>> ans;
        for (auto i : mp) {
            int x = i.first, y = i.second;
            ans.push_back({x, y});
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
