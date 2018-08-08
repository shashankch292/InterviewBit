/*
Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 

LINK: https://www.interviewbit.com/problems/balanced-binary-tree/
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
 
int check_bal(TreeNode* root)
{
    if(root==NULL)
        return 0;
 
    int lefth = check_bal(root->left);
    int righth = check_bal(root->right);
 
    if(lefth==-1 || righth==-1)
        return -1;
 
    if(abs(lefth-righth)>1)
        return -1;
 
    return 1+max(lefth,righth);
}
 
int Solution::isBalanced(TreeNode* A)
{
    if(check_bal(A)==-1)
        return 0;
    else
        return 1;
}