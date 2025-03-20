class Disjoint{
private:
    vector<int> parent, size;

public:
    Disjoint(int n){
        size.resize(n+1, 1);       
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }

    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v){
        int upu = find(u);
        int upv = find(v);
        if(upu==upv) return;      

        if(size[upu] < size[upv]){
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else{
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // int n = edges.size();
        // vector<vector<int>> adj(n);
        // for(auto it: edges){
        //     int u = it[0];
        //     int v = it[1];
        //     int w = it[2];
        //     adj[u].push_back({v, w});
        // }

        vector<int> cost(n, -1);
        Disjoint ds(n);   //use disjoint set to group components.        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u, v);
        }

        for(auto it: edges){  //find minimum cost of each component
            int root = ds.find(it[0]);
            cost[root] &= it[2];
        }

        vector<int> ans;
        for(auto q: query){
            int st = q[0];
            int end = q[1];

            if(ds.find(st) != ds.find(end)){
                //if both nodes are not from same component
                ans.push_back(-1);
            }
            else{
                int root = ds.find(st);  //use find to get minimum cost of that query.
                ans.push_back(cost[root]);
            }
        }

        return ans;
    }
};