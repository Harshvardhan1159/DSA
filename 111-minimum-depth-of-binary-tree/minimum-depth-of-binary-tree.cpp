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
    int func(TreeNode* root){
    if(root==NULL)return 0 ;
    if(root->left==NULL && root->right==NULL)return 1;
    int x = INT_MAX;
    int y = INT_MAX;
    if(root->left!=NULL){
     x = func(root->left);
    }
    if(root->right!=NULL){
     y = func(root->right);
    }
    return min(x,y)+1;

    }
    int minDepth(TreeNode* root) {
      return func(root);    
    }
};