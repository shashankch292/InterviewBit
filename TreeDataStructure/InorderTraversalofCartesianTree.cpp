/*
Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1

LINK: https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
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
 
int findMax(int s, int e, vector<int> &A)
{
    int mxi = s;
    for(int i=s+1;i<=e;i++)
        if(A[i]>A[mxi])
            mxi = i;
    return mxi;
}
 
TreeNode* build(int s, int e, vector<int> &A)
{
    if(s>e)
        return NULL;
 
    int i = findMax(s,e,A);
    TreeNode* node = new TreeNode(A[i]);
    node->left = build(s,i-1,A);
    node->right = build(i+1,e,A);
    return node;
}
 
TreeNode* Solution::buildTree(vector<int> &A)
{
    if(A.empty())
        return NULL;
 
    return build(0,A.size()-1,A);
}