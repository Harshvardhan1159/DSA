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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
        TreeNode* dem = q.front();
        q.pop();
        if(dem->left){
            mp[dem->left]=dem;
            q.push(dem->left);
        }
        if(dem->right){
          mp[dem->right]=dem;
          q.push(dem->right);
        }
        }
        vector<int>ans;
        queue<pair<TreeNode*,int>>qe;
        qe.push({target,0});
        map<TreeNode*,int>vis;
        vis[target]=1;
        while(!qe.empty()){
            pair<TreeNode*,int>t=qe.front();
            TreeNode* node = t.first;
            int dis = t.second;
            vis[node]=1;
            if(dis==k){
                ans.push_back(node->val);
            }
            qe.pop();
            if(mp[node] && vis[mp[node]]!=1){
                qe.push({mp[node],dis+1});
            }
            if(node->left && vis[node->left]!=1){
                qe.push({node->left,dis+1});
            }
            if(node->right && vis[node->right]!=1){
                qe.push({node->right,dis+1});
            }
        }
    return ans;

    }
};