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
    int f(TreeNode* root,int &ans){
        if(root==NULL)return 0;
        int left = max(0, f(root->left, ans));   // ignore negative paths
        int right = max(0, f(root->right, ans));
        ans=max(ans,left+right+root->val);
        return root->val+max(left,right);

    }
    int maxPathSum(TreeNode* root) {
    int ans =INT_MIN;
       int x= f(root,ans);
       return ans;
    }
};