/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>>ans;
      if(root==NULL)return ans;
      queue<TreeNode*>q;
      q.push(root);
      int r =0;
      
      while(!q.empty()){
        int n = q.size();
        vector<int>temp;
        
        for(int i=0;i<n;i++){
           TreeNode* x = q.front();
           q.pop();
            temp.push_back(x->val);
            if(x->left)q.push(x->left);
            if(x->right)q.push(x->right);
        }

        if(r==1){
            reverse(temp.begin(),temp.end());
            
        }
        ans.push_back(temp);
        r=1-r;
      }
    
     return ans;  
    }
};