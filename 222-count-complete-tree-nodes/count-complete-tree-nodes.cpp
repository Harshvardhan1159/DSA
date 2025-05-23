class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr)
      return 0;
    TreeNode* left = root;
    TreeNode* right = root;
    int heightL = 0;
    int heightR = 0;
    while (left != nullptr) {
      ++heightL;
      left = left->left;
    }
    while (right != nullptr) {
      ++heightR;
      right = right->right;
    }
    if (heightL == heightR)  
      return pow(2, heightL) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);    //humesha complete tree do parts me divide hota h full and incomplete 
    // agar full wala part h to 2^x-1 nodes hogi  // left hight == right height se checkl hoga
    //varna 1+ leftnode and right nodes 
    //log n soln
  }
};