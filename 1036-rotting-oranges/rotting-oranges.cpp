class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,+1,0,-1};
        int step =0;
        while(!q.empty()){
        pair<pair<int,int>,int>p= q.front();
        q.pop();
        int i = p.first.first;
        int j = p.first.second;
         step = p.second;
       
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int ni = i+drow[k];
            int nj = j+dcol[k];
            if(ni<n && ni>=0  && nj>=0 && nj<m && grid[ni][nj]==1 && !vis[ni][nj]){
                q.push({{ni,nj},step+1});
                vis[ni][nj]=true;
                 grid[ni][nj]=2;
            }
        }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return step;

    }
};