// Same Tree
// https://leetcode.com/problems/same-tree/
// Accepted 2023-07-15 | Runtime 0 ms | Memory 40.3 MB

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null && q==null){
            return true;
        }
        else if(p==null || q==null){
            return false;
        }
        else if(p.val==q.val){
            return isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
        }

        return false;
    }
}