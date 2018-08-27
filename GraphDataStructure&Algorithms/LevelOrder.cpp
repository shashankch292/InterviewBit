/*
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.

LINK: https://www.interviewbit.com/problems/level-order/
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
 
map<int, vector<int> > mp;
 
void traverse(TreeNode* root, int d)
{
    if(!root)
        return;
 
    mp[d].push_back(root->val);
 
    traverse(root->left, d+1);
    traverse(root->right, d+1);
}
 
vector<vector<int> > Solution::levelOrder(TreeNode* A)
{
    mp.clear();
 
    traverse(A, 0);
 
    vector<vector<int> > res;
 
    for(auto x : mp)
        res.push_back(x.second);
 
    return res;
}