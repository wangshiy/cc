/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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

    vector<int> preorderTraversal(TreeNode *root) 
    {
        vector<int> result;
        
        preorderTraversal(root, result);
        
        return result;
    }
    
    void preorderTraversal(TreeNode *root, vector<int> &result) 
    {
        //result.push_back(root->val);
        
        if (root == NULL)
        {
            return;
        }
        
        result.push_back(root->val);
        
        preorderTraversal(root->left,result);
        preorderTraversal(root->right,result);
    }
};