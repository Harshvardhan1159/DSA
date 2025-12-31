class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long)m * k > n) return -1; // Impossible to make enough bouquets

        int s = 1, e = 0;
        for (int i = 0; i < n; i++) {
            e = max(e, bloomDay[i]); // Find the maximum bloom day
        }

        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int c = 0, nums = 0;

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) { // If flower is bloomed
                    c++;
                    if (c == k) { // If we can make a bouquet
                        nums++;
                        c = 0; // Reset count for next bouquet
                    }
                } else {
                    c = 0; // Reset count if a flower is not bloomed
                }
            }

            if (nums >= m) { // If we can make enough bouquets
                ans = mid;
                e = mid - 1; // Try smaller days
            } else {
                s = mid + 1; // Increase days
            }
        }
        return ans;
    }

};