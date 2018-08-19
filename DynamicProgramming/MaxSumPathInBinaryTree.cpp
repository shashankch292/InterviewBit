/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Example :

Given the below binary tree,

       1
      / \
     2   3
Return 6.

LINK: https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
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
 
int ans  INT_MIN;
 
int findMaxPathSum(TreeNode* root)
{
    if(!root)
        return 0;
 
    int leftSum = findMaxPathSum(root->left);
    int rightSum = findMaxPathSum(root->right);
 
    int maxRoot = max(root->val, root->val + max(leftSum, rightSum));
 
    ans = max(ans, max(maxRoot, leftSum + root->val + rightSum));
 
    return maxRoot;
}
 
int Solution::maxPathSum(TreeNode* A)
{
    ans = INT_MIN;
    findMaxPathSum(A);
    return ans;
}