class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans; // ✅ handle empty tree case

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> x;
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                x.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            ans.push_back(x);
        }

        return ans;
    }
};
