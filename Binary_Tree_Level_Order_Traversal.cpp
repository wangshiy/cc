/*
Problem:
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int> > levelOrder(TreeNode *root) 
    {
        vector<vector<int>> result;
        vector<TreeNode*> sta;
        
        if (root == NULL)
        {
            return result;
        }
        
        int index = 0;
        int curlevelcount = 0;
        int nextlevelcount = 1;
        sta.push_back(root);
        
        while (index < sta.size())
        {
            curlevelcount = nextlevelcount;
            nextlevelcount = 0;
            vector<int> level;
            for (int i = index; i < index + curlevelcount; i++)
            {
                root = sta[i];
                level.push_back(root->val);
                if (root->left != NULL)
                {
                    sta.push_back(root->left);
                    nextlevelcount++;
                }
                if (root->right != NULL)
                {
                    sta.push_back(root->right);
                    nextlevelcount++;
                }
            }
            result.push_back(level);
            index = index + curlevelcount;
        }
        
        return result;
    }
};