// Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Accepted 2025-09-06 | Runtime 0 ms | Memory 42.6 MB

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
    public int maxDepth(TreeNode root) {
        if(root==null){
            return 0;
        }
        return Math.max(1+maxDepth(root.left),1+maxDepth(root.right));
    }
}