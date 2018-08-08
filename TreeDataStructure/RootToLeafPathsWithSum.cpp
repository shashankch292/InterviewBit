/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

LINK: https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
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
 
void check(TreeNode* root, int sum, int d, vector<int> &temp)
{
    if(root==NULL)
        return;
 
    d+=root->val;
    temp.push_back(root->val);
 
    if(sum==d && root->left==NULL && root->right==NULL)
    {
        res.push_back(temp);
        temp.pop_back();
        return;
    }
 
    check(root->left, sum, d, temp);
    check(root->right, sum, d, temp);
    temp.pop_back();
}
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B)
{
    res.clear();
    vector<int> temp;
    check(A,B,0,temp);
    return res;
}