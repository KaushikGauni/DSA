// Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Accepted 2025-08-13 | Runtime 5 ms | Memory 45 MB

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int max = Math.max(p.val,q.val);
        int min = Math.min(p.val,q.val);

        if(max<root.val && min<root.val){
            return lowestCommonAncestor(root.left,p,q);
        }
        if(max>root.val && min>root.val){
            return lowestCommonAncestor(root.right,p,q);
        }
        
        return root;
        
    }
}