/*
Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3

LINK: https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/
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
 
TreeNode* build(int si, int ei, vector<int> &In, int sp, int ep, vector<int> &Post)
{
    if(si>ei || sp>ep)
        return NULL;
 
    int ind = -1;
    for(int i=si;i<=ei;i++)
    {
        if(In[i]==Post[ep])
        {
            ind = i;
            break;
        }
    }
 
    TreeNode* node = new TreeNode(In[ind]);
    int len = ei-ind;
    node->left = build(si,ind-1,In,sp,ep-len-1,Post);
    node->right = build(ind+1,ei,In,ep-len,ep-1,Post);
    return node;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B)
{
    if(A.empty() || B.empty())
        return NULL;
 
    return build(0,A.size()-1,A,0,B.size()-1,B);
}