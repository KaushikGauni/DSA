// Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        preorder(root,res);
        return res;
    }

    public void preorder(TreeNode root, List<Integer> res){
        if(root==null){
            return;
        }
        else{
            res.add(root.val);
            preorder(root.left,res);
            preorder(root.right,res);
        }
    }
}