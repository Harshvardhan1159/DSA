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
void func(TreeNode* root,vector<string>&ans,string temp){
     temp += to_string(root->val);
   if(root->left==NULL && root->right==NULL){
    ans.push_back(temp);
    return;
   }
   
   if(root->left!=NULL){
    func(root->left,ans,temp+"->");
   }
   
   if(root->right!=NULL){
    func(root->right,ans,temp+"->");
   }

   temp.pop_back();


}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp="";
        func(root,ans,temp);
        return ans;
    }
};