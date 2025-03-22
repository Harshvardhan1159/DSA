class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&mp, vector<int>&vis,set<int>&contains){
        if(vis[node]==0)return ;
        contains.insert(node);
        vis[node]=0;
        for(auto i:mp[node]){
            if(vis[i]==-1){
                dfs(i,mp,vis,contains);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
          vector<int>in(n);
        vector<int>ou(n);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
            in[u]++;
            in[v]++;
            ou[u]++;
            ou[v]++;

        }
      
    
       vector<int>vis(n,-1);
       int c =0;
       for(int i=0;i<n;i++){
        set<int>contains;
       if(vis[i]==-1){
       dfs(i,mp,vis,contains);
       int size = contains.size();
       bool complete = true;
       for(auto it:contains){
        if(in[it]!= size-1 && ou[it]!=size-1){
            complete=false;
        }

       }
       if(complete)c++;
       
       }
       }
       return c;
    }
};