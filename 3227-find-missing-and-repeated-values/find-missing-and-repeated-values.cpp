class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               mp[grid[i][j]]++;
            }
        }
        vector<int>ans;
        int k = n*n;
        int sum = k*(k+1)/2;
        int r,m;
        int dem =0;
        for(auto i:mp){
            if(i.second>1){
                r=i.first;
            }
            dem+=i.first;

        }
        ans.push_back(r);
        ans.push_back(sum-dem);
        return ans;
    }
};