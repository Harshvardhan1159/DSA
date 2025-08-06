class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>&v) {
        sort(v.begin(),v.end(),cmp);
        int n = v.size();
        int last =INT_MIN;
        int cnt =0;
        for(auto i:v){
            int s = i[0];
            int e = i[1];
            if(s>=last){
                last = e;
                cnt++;
            }

        }
        return n-cnt;
    }
};