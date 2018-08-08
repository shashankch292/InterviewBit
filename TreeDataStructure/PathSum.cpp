/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/path-sum/
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
 
int check(TreeNode* root, int sum, int d)
{
    if(root==NULL)
        return 0;
 
    d+=root->val;
 
    if(sum==d && root->left==NULL && root->right==NULL)
        return 1;
 
    if(check(root->left, sum, d))
        return 1;
    if(check(root->right, sum, d))
        return 1;
    return 0;
}
 
int Solution::hasPathSum(TreeNode* A, int B)
{
    return check(A,B,0);
}