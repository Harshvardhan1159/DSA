class Solution {
public:
    // Step 1: Map each node to its parent using DFS
    void markParents(TreeNode* root, map<TreeNode*, TreeNode*>& parent) {
        if (!root) return;
        if (root->left) {
            parent[root->left] = root;
            markParents(root->left, parent);
        }
        if (root->right) {
            parent[root->right] = root;
            markParents(root->right, parent);
        }
    }

    // Step 2: BFS to find all nodes at distance K
    vector<int> bfs(TreeNode* target, map<TreeNode*, TreeNode*>& parent, int k) {
        map<TreeNode*, bool> visited;
        queue<pair<TreeNode*, int>> q;
        vector<int> result;

        q.push({target, 0});
        visited[target] = true;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist == k) {
                result.push_back(node->val);
            }

            if (node->left && !visited[node->left]) {
                visited[node->left] = true;
                q.push({node->left, dist + 1});
            }
            if (node->right && !visited[node->right]) {
                visited[node->right] = true;
                q.push({node->right, dist + 1});
            }
            if (parent[node] && !visited[parent[node]]) {
                visited[parent[node]] = true;
                q.push({parent[node], dist + 1});
            }
        }

        return result;
    }

    // Main function
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);
        return bfs(target, parent, k);
    }
};
