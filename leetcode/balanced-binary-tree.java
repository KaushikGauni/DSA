// Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
// Accepted 2025-08-15 | Runtime 0 ms | Memory 44.7 MB

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
    public boolean isBalanced(TreeNode root) {
        if(root==null){
            return true;
        }
        if(height(root)==-1){
            return false;
        }
        return true;
    }

    public int height(TreeNode root){
        if(root==null){
            return 0;
        }
        int left = height(root.left);
        int right = height(root.right);

        if(left==-1 || right==-1){
            return -1;
        }
        if(Math.abs(right-left)>1){
            return -1;
        }
        return Math.max(left,right)+1;
    }
}