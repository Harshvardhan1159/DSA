class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>v(n,-1);
        for(int j=0;j<n;j++){
        if(v[j]!=-1)continue;
        queue<pair<int,int>>q;
        q.push({j,0});
       
        while(!q.empty()){
           pair<int,int>p= q.front();
           int node = p.first;
           int currclr = p.second;
           v[node]=currclr;
            q.pop();
            for(auto i:graph[node]){
                if(v[i]==currclr)return false;
                if(v[i]==-1){ 
                    q.push({i,1-currclr});
                      v[i] = 1 - currclr;
                }
            }
        }
        }
        return true;
    }
};