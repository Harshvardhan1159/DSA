class Solution {
public:
bool dfs(int i,vector<vector<int>>& graph,int currcolor, vector<int>&color){
  color[i]=currcolor;
  for(auto it:graph[i]){
    if(currcolor == color[it]){
        return false;
    }
    if(color[it]==-1){
        color[it]=1-currcolor;
       if(!dfs(it,graph,1-currcolor,color)){
        return false;
       }
    }
  }
  return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        int currcolor = 1;
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
            if(!dfs(i,graph,currcolor,color)){
                return false;
            }
            }
        }
        return true;
    }
};