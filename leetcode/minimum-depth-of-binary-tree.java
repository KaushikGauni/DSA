// Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Accepted 2023-07-15 | Runtime 15 ms | Memory 62.9 MB

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
    public int minDepth(TreeNode root) {
        if(root==null){
            return 0;
        }
        int a = minDepth(root.right);
        int b = minDepth(root.left);
        if(Math.min(a,b)==0){
            return Math.max(a,b)+1;
        }
        return Math.min(a,b)+1;
    }
}