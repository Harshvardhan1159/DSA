class Solution {
public:
    bool func(int i,int j , vector<vector<char>>& board, string word, vector<vector<int>>&vis,int n , int m,string& h,int idx){
        if(idx==word.size())return true;
      if(i>=n || j>=m || i<0 || j<0 || vis[i][j]==1 || word[idx]!=board[i][j])return false;
      
     
      vis[i][j]=1;
       
     
       
       bool  ans= func(i+1,j,board,word,vis,n,m,h,idx+1)||
        func(i-1,j,board,word,vis,n,m,h,idx+1)||
        func(i,j-1,board,word,vis,n,m,h,idx+1)||
        func(i,j+1,board,word,vis,n,m,h,idx+1);
    
      vis[i][j]=0;
      return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bool ans = false;
        string h;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]==word[0]){
                    if (func(i,j,board,word,vis,n,m,h,0)){
                        return true;
                    }
                }
            }
           
         }
         return ans;


    }
};