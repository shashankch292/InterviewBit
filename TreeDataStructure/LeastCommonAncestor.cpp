/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

LINK: https://www.interviewbit.com/problems/least-common-ancestor/
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
 
bool b1,b2;
 
bool find(TreeNode* root, int x)
{
    if(root==NULL)
        return false;
 
    if(root->val==x || find(root->left,x) || find(root->right,x))
        return true;
    return false;
}
 
TreeNode* findLCA(TreeNode* root, int v1, int v2)
{
    if(root==NULL)
        return NULL;
 
    if(root->val==v1)
    {
        b1 = true;
        return root;
    }
    if(root->val==v2)
    {
        b2 = true;
        return root;
    }
 
    TreeNode* left = findLCA(root->left,v1,v2);
    TreeNode* right = findLCA(root->right,v1,v2);
 
    if(left && right)
        return root;
 
    if(left)
        return left;
    return right;
}
 
int Solution::lca(TreeNode* A, int B, int C)
{
    b1 = b2 = false;
    TreeNode* lca_node = findLCA(A, B, C);
 
    if(b1 && b2 || b1 && find(lca_node,C) || b2 && find(lca_node,B))
        return lca_node->val;
    return -1;
}