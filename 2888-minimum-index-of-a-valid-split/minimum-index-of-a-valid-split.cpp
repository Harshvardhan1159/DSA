class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int count = 0, x = -1, n = nums.size();

        // Step 1: Find the dominant element candidate using Boyer-Moore Voting Algorithm
        for (int num : nums) {
            if (count == 0) {
                x = num;
                count = 1;
            } else if (num == x) {
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify if x is actually the dominant element
        count = 0;
        for (int num : nums) {
            if (num == x) count++;
        }
        if (count * 2 <= n) return -1; // Ensure x is truly dominant in full array

        // Step 3: Find the minimum index where the split condition holds
        int left_count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) left_count++;

            int right_count = count - left_count;
            int left_size = i + 1;
            int right_size = n - left_size;

            // Ensure x is dominant in both partitions
            if (left_count * 2 > left_size && right_count * 2 > right_size) {
                return i;
            }
        }
        return -1;
    }
};
