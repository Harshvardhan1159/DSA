class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int>mp;
        int ans =0;
        for(auto x:words){
            if(x.length()<k)continue;
            string a = x.substr(0,k);
            mp[a]++;
        }
        for(auto it:mp){
            if(it.second>=2)ans++;
        }
        return ans;
    }
};