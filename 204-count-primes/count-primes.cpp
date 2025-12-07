class Solution {
public:
    int countPrimes(int n) {
        vector<int>p(n+1,1);
        if(n<3)return 0;
        for(int i=2;i<=n-1;i++){
            if(p[i]==1){
                for(int j=i*2;j<=n;j+=i){
                    p[j]=0;
                }
            }
        }
        int ans =0;
        for(int i=2;i<n;i++){
            if(p[i]==1)ans++;
        }
        return ans;
    }
};