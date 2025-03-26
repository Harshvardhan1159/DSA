class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>ans;
        int n = grid.size();
        int m = grid[0].size();
        int min_val = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(grid[i][j]);
                 if ((grid[i][j] - min_val) % x != 0) return -1;
            }
        }
        sort(ans.begin(),ans.end());
        int y = (n*m)/2;
        int a =0;
        for(int i=0;i<n*m;i++){
           
            a+=abs(ans[y]-ans[i])/x;
        }
        return a;
    }
};