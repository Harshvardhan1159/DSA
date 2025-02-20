class Solution {
public:
   void dfs(vector<vector<char>>& grid,int i,int j,int n , int m){

    
      if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 'O') return;

     grid[i][j]='Y';
     if(i+1<n){
        dfs(grid,i+1,j,n,m);
     }
     if(i-1>=0){
        dfs(grid,i-1,j,n,m);
     } 
     if(j+1<m){
        dfs(grid,i,j+1,n,m);
     }
     if(j-1>=0){
        dfs(grid,i,j-1,n,m);
     }

   }
    void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    for(int i =0;i<m;i++){
        if(board[0][i]=='O'){
            dfs(board,0,i,n,m);
        }
    }
    for(int i =0;i<m;i++){
        if(board[n-1][i]=='O'){
             dfs(board,n-1,i,n,m);
        }
    }
    for(int i =0;i<n;i++){
        if(board[i][0]=='O'){
             dfs(board,i,0,n,m);
        }
    }
    for(int i =0;i<n;i++){
        if(board[i][m-1]=='O'){
             dfs(board,i,m-1,n,m);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='Y'){
                board[i][j]='O';
            }else{
                board[i][j]='X';
            }
        }
    }

    }
};