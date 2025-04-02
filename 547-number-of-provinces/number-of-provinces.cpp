class Solution {
public:
    void dfs(int i, vector<vector<int>>& v, vector<int>& vis) {
        vis[i]=1;
        for(auto it:v[i]){
            if(!vis[it]){
                dfs(it,v,vis);
            }
        }
    }
                       
    int findCircleNum(vector<vector<int>>& m) {
        int n = m.size();
        vector<vector<int>>v(n);
        vector<int>vis(n,0);

        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(m[i][j]==1 && i!=j){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i =0;i<n;i++){
            if(vis[i]!=1){
                c++;
                dfs(i,v,vis);
            }
        }
        return c;
    }
};