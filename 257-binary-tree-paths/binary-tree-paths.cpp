class Solution {
public:
    void solve(TreeNode* root, string& path, vector<string>& result) {
        if (!root) return;

        string val = to_string(root->val);
        int len = val.length(); // length of current node's value

        if (!path.empty()) {
            path += "->";
            len += 2; // count "->" as well
        }

        path += val;

        // If it's a leaf node, add the path
        if (!root->left && !root->right) {
            result.push_back(path);
        } 
            // Recurse
            solve(root->left, path, result);
            solve(root->right, path, result);
    

        // Backtrack using pop_back
        while (len--) path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        solve(root, path, result);
        return result;
    }
};
