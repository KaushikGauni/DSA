// Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Accepted 2023-07-15 | Runtime 0 ms | Memory 41.2 MB

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        postorder(root,res);
        return res;
    }

    public void postorder(TreeNode root, List<Integer> res){
        if(root==null){
            return;
        }
        else{
            postorder(root.left,res);
            postorder(root.right,res);
            res.add(root.val);
        }
    }
}