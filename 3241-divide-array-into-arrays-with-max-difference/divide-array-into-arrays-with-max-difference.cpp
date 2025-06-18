class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(nums[i]);

            // Once we have 3 elements in temp
            if (temp.size() == 3) {
                int minVal = temp[0];
                int maxVal = temp[2];

                if (maxVal - minVal <= k) {
                    ans.push_back(temp);
                } else {
                    return {}; // Cannot form valid groups
                }

                temp.clear(); // clear for the next group
            }
        }

        // If at the end, temp is not empty, return empty (invalid)
        if (!temp.empty()) return {};

        return ans;
    }
};
