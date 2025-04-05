class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        queue<pair<int,int>>q;
        vector<vector<int>>v(n,vector<int>(m,0));
        q.push({sr,sc});
        v[sr][sc]=1;
        int cl = image[sr][sc];
        while(!q.empty()){
           pair<int,int>p=q.front();
           q.pop();
           int r = p.first;
           int c = p.second;
           image[r][c]=color;
           for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int ny = c+dy[i];
            if(nr>=0 && nr<n && ny>=0 && ny<m && image[nr][ny]==cl && v[nr][ny]!=1){
                image[nr][ny]=color;
                q.push({nr,ny});
                v[nr][ny]=1;
            }
           } 
        }
        return image;
    }
};