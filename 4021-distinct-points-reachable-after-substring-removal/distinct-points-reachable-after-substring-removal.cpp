class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<pair<int,int>> pref(n+1,{0,0});
        
        // Build prefix sums of coordinates
        for(int i =0;i<n;i++){
            pref[i+1]=pref[i];
            char ch = s[i];
            if(ch=='U') pref[i+1].second++;
            if(ch=='D') pref[i+1].second--;
            if(ch=='L') pref[i+1].first--;
            if(ch=='R') pref[i+1].first++;
        }
        
        set<pair<int,int>> uniq;
        auto total = pref[n];
        
        // Try removing substring of length k starting at index i
        for(int i =0;i<=n-k;i++){
            auto disp = pref[i]; // position before removed substring
            int dispx = total.first - pref[i+k].first;
            int dispy = total.second - pref[i+k].second;
            
            int finalx = disp.first + dispx;
            int finaly = disp.second + dispy;
            
            uniq.insert({finalx,finaly});
        }
        return uniq.size();
    }
};