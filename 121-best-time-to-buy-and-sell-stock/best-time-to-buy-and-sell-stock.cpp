class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi =INT_MIN;
        int ans =0;
        int x =0;
        for(int i = n-1;i>=0;i--){
            if(maxi<prices[i]){
                maxi = prices[i];
            }
            ans = maxi-prices[i];
            x=max(x,ans);
        }
        return x;
    }
};