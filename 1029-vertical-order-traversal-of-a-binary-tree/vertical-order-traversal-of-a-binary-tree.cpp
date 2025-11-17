class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;   // line -> level -> values
        queue<pair<TreeNode*, pair<int,int>>> q; 
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int line = it.second.first;
            int level = it.second.second;

            mp[line][level].push_back(node->val);

            if (node->left)  q.push({node->left, {line - 1, level + 1}});
            if (node->right) q.push({node->right, {line + 1, level + 1}});
        }

        vector<vector<int>> ans;

        for (auto &col : mp) {
            vector<int> temp;

            for (auto &lev : col.second) {
                auto &vec = lev.second;
                sort(vec.begin(), vec.end());  // ensure sorted order

                for (int x : vec) 
                    temp.push_back(x);         // easy push
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
