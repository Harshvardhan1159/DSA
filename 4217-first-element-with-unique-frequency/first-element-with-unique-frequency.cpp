class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int> freq;

        // Step 1: Count frequency of each number
        for (auto i : nums) {
            freq[i]++;
        }

        map<int,int> freqCount;

        // Step 2: Count how many times each frequency appears
        for (auto i : freq) {
            freqCount[i.second]++;
        }

        // Step 3: Find first number whose frequency is unique
        for (auto i : nums) {
            if (freqCount[freq[i]] == 1) {
                return i;
            }
        }

        return -1; // if none found
    }
};
