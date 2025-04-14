class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp; 
        int n = s.size();
        int left = 0, count = 0;
        int ans =0;
        int right =0;

        while(right < n){
            mp[s[right]]++;

            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
           
                ans +=n-right;
                mp[s[left]]--;
                left++;

            }
            right++;

        }
        return ans;
    }
};