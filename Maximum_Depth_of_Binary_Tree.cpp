/*
Problem:
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) 
    {
        if (root == NULL)
        {
            return 0;
        }
        int lmax = maxDepth(root->left);
        int rmax = maxDepth(root->right);
        
        return max(lmax,rmax)+1;
    }
};