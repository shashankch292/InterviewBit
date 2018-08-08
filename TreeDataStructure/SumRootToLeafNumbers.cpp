/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

LINK: https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
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
 
#define MOD 1003
 
int calc(TreeNode* root, int sum)
{
    if(root==NULL)
        return sum;
 
    sum+=root->val;
 
    if(root->left==NULL && root->right==NULL)
        return sum;
 
    sum = (sum*10)%MOD;
 
    int left_sum = 0;
    if(root->left)
        left_sum = calc(root->left,sum);
    int right_sum = 0;
    if(root->right)
        right_sum = calc(root->right,sum);
 
    return (left_sum + right_sum)%MOD;
}
 
int Solution::sumNumbers(TreeNode* A)
{
    return calc(A,0);
}