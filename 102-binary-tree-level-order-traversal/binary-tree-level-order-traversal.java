class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> dfs = new ArrayList<>();
        if(root == null) return dfs;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while(q.size()>0) {
            int n = q.size();
            List<Integer> sub = new ArrayList<>();
            while(n>0) {
                TreeNode node = q.remove();
                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
                sub.add(node.val);
                n--;
            }
            dfs.add(sub);
        }
        return dfs;
    }
}