/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]

LINK: https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
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
 
vector<vector<int> > res;
 
int maxDepth(TreeNode* A)
{
    if(A==NULL)
        return 0;
    return 1+max(maxDepth(A->left), maxDepth(A->right));
}
 
void zigzag(TreeNode* root, int d)
{
    if(root==NULL)
        return;
    res[d].push_back(root->val);
    zigzag(root->left,d+1);
    zigzag(root->right,d+1);
}
 
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A)
{
    int n = maxDepth(A);
    res.clear();
    res.resize(n);
 
    zigzag(A,0);
 
    for(int i=1;i<n;i+=2)
        reverse(res[i].begin(), res[i].end());
    return res;
}