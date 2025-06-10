class Solution {
public:
    int maxDifference(string s) {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        int maxi = 0;
        int mini = INT_MAX; 

        for (auto i : mp) {
           if(i.second%2==0){
            mini = min(mini,i.second);
           }else{
            maxi=max(maxi,i.second);
           }
        }

        return maxi - mini;
    }
};
