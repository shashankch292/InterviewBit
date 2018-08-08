/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True

LINK: https://www.interviewbit.com/problems/identical-binary-trees/
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
 
int isSame(TreeNode* root1, TreeNode* root2)
{
    if(!root1 && !root2)
        return 1;
    if(!root1 || !root2)
        return 0;
    if(root1->val!=root2->val)
        return 0;
 
    return (isSame(root1->left, root2->left) && isSame(root1->right,root2->right));
}
 
int Solution::isSameTree(TreeNode* A, TreeNode* B)
{
    return isSame(A,B);
}