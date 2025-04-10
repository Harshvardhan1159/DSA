/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return root;
        if(root==p || root==q)return root;
        TreeNode* leftn =  lowestCommonAncestor(root->left,p,q);
        TreeNode* rightn =  lowestCommonAncestor(root->right,p,q);

        if(leftn && rightn){
            return root;
        }
        if(leftn)return leftn;
        return rightn;
    }
};