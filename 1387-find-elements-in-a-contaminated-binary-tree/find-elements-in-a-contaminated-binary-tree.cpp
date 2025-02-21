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
class FindElements {
public:
    TreeNode* root;
    std::unordered_set<int> values; // Store values for O(1) find

    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        recoverTree(root);
    }
    
    bool find(int target) {
        return values.count(target) > 0;
    }

private:
    void recoverTree(TreeNode* root) {
        if (!root) return;
        values.insert(root->val);
        
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            recoverTree(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            recoverTree(root->right);
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */