class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
       for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        mat[u][v]=w;
        mat[v][u]=w;
       
       }
       for(int i=0;i<n;i++){
       mat[i][i]=0;
       }

       for(int k =0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][k]==INT_MAX || mat[k][j]==INT_MAX)continue;
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
       }
       
       int ans =INT_MAX;
       int x =0;
       for(int i=0;i<n;i++){
        int c =0;
        for(int j =0;j<n;j++){
           if(mat[i][j]<=t){
            c++;
           }
        }
        if(c<=ans){
         ans=c;
         x=i;
         
        }
       }

    return x;
    }
};