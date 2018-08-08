/*
Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3

LINK: https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
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
 
TreeNode* build(int si, int ei, vector<int> &In, int sp, int ep, vector<int> &Pre)
{
    if(si>ei || sp>ep)
        return NULL;
 
    int ind = -1;
    for(int i=si;i<=ei;i++)
    {
        if(In[i]==Pre[sp])
        {
            ind = i;
            break;
        }
    }
 
    TreeNode* node = new TreeNode(In[ind]);
    int len = ind-si;
    node->left = build(si,ind-1,In,sp+1,sp+len,Pre);
    node->right = build(ind+1,ei,In,sp+len+1,ep,Pre);
    return node;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B)
{
    if(A.empty() || B.empty())
        return NULL;
 
    return build(0,B.size()-1,B,0,A.size()-1,A);
}