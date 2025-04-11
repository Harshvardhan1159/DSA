class Solution {
public:
    TreeNode* find(TreeNode* root, int start) {
        if (root == NULL) return NULL;
        if (root->val == start) return root;

        TreeNode* left = find(root->left, start);
        if (left) return left;

        return find(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);

        // Step 1: Build parent map
        while (!q.empty()) {
            TreeNode* dem = q.front();
            q.pop();
            if (dem->left) {
                mp[dem->left] = dem;
                q.push(dem->left);
            }
            if (dem->right) {
                mp[dem->right] = dem;
                q.push(dem->right);
            }
        }

        // Step 2: Find the node with value = start
        TreeNode* x = find(root, start);

        // Step 3: BFS from x to simulate infection
        queue<pair<TreeNode*, int>> qe;
        map<TreeNode*, int> vis;
        qe.push({x, 0});
        vis[x] = 1;

        int ans = 0;
        while (!qe.empty()) {
            TreeNode* node = qe.front().first;
            int dis = qe.front().second;
            qe.pop();
            ans = max(ans, dis);

            if (mp[node] && !vis[mp[node]]) {
                vis[mp[node]] = 1;
                qe.push({mp[node], dis + 1});
            }
            if (node->left && !vis[node->left]) {
                vis[node->left] = 1;
                qe.push({node->left, dis + 1});
            }
            if (node->right && !vis[node->right]) {
                vis[node->right] = 1;
                qe.push({node->right, dis + 1});
            }
        }

        return ans;
    }
};
