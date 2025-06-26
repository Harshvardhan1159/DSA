class Solution {
public:
    // track row as well to enable proper sorting
    void solve(TreeNode* root, map<int, vector<pair<int, int>>>& mp, int col, int row) {
        if (root == NULL) return;
        mp[col].push_back({row, root->val});
        solve(root->left, mp, col - 1, row + 1);
        solve(root->right, mp, col + 1, row + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;  // column -> vector of (row, value)
        vector<vector<int>> ans;

        solve(root, mp, 0, 0);  // start at root: col=0, row=0

        for (auto& i : mp) {
            // Sort by row first, then value
            sort(i.second.begin(), i.second.end());
            vector<int> temp;
            for (auto& it : i.second) {
                temp.push_back(it.second);  // only push the value
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
