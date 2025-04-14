class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int ls=0;
        for(int i=0;i<k;i++){
            ls+=c[i];
        }
        int n = c.size();
        int r =n-1;
        int rs =0;
        int l = k-1;
        int maxi = INT_MIN;
        maxi = max(maxi,ls+rs);
        while(k--){
            ls-=c[l--];
            rs+=c[r--];
             maxi = max(maxi,ls+rs);
        }
        return maxi;
    }
};