/*
Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.

LINK: https://www.interviewbit.com/problems/postorder-traversal/
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
vector<int> Solution::postorderTraversal(TreeNode* A)
{
    vector<int> res;
 
    if(A==NULL)
        return res;
 
    deque<TreeNode*> dq;
    dq.push_back(A);
 
    while(!dq.empty())
    {
        TreeNode* curr = dq.back();
        if(curr->left || curr->right)
        {
            if(curr->right)
            {
                dq.push_back(curr->right);
                curr->right = NULL;
            }
            if(curr->left)
            {
                dq.push_back(curr->left);
                curr->left = NULL;
            }
        }
        else
        {
            res.push_back(curr->val);
            dq.pop_back();
        }
    }
    return res;
}