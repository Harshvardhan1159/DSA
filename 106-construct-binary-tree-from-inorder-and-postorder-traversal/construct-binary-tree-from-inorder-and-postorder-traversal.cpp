class Solution {
public:
    TreeNode* func(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int>& mp) {
        if (is > ie || ps > pe) return nullptr;

        // The last element of postorder is always the root
        TreeNode* root = new TreeNode(postorder[pe]);

        // Find root in inorder
        int x = mp[postorder[pe]];
        int toright = x - is; // Number of nodes in the left subtree

        // Recursive calls to construct left and right subtrees
        root->left = func(inorder, is, x - 1, postorder, ps, ps + toright - 1, mp);
        root->right = func(inorder, x + 1, ie, postorder, ps + toright, pe - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size(); // Fix missing `n`

        // Store indices of inorder elements for O(1) lookup
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return func(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }
};
