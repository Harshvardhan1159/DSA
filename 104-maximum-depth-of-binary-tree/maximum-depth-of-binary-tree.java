    class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
    
        int leftDist = maxDepth(root.left);
        int rightDist = maxDepth(root.right);
        
        int max = Math.max(leftDist, rightDist);
        return 1+max;
    }
}