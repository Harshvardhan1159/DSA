class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int s = 0, e = n - 1, ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int h = n - mid; // Number of papers with at least citations[mid] citations

            if (citations[mid] >= h) {
                ans = h;  // Update answer
                e = mid - 1;  // Search left to find the maximum valid H-index
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
