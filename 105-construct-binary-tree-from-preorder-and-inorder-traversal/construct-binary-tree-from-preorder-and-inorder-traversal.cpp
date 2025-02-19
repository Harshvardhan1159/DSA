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
  TreeNode* func(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&mp,int i1,int j1,int i2, int j2){
    if(i1>j1)return NULL;
        TreeNode* root = new TreeNode(preorder[i1]);
        int x = mp[preorder[i1]];

        root->left = func(preorder,inorder,mp,i1+1,i1+x-i2,i2,x-1);
        root->right = func(preorder,inorder,mp,i1+x-i2+1,j1,x+1,j2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int,int>mp;
       for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
       }

       return func(preorder,inorder,mp,0,preorder.size()-1,0,inorder.size()-1);

        
    }
};