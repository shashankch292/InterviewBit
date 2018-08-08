/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 

LINK: https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
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
 
vector<int> inorderTraversal(TreeNode* A)
{
    vector<int> res;
    stack<TreeNode*> st;
 
    TreeNode* curr = A;
 
    while(!st.empty() || curr)
    {
        while(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
 
        curr = st.top();
        st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}
 
int Solution::kthsmallest(TreeNode* A, int B)
{
    vector<int> v = inorderTraversal(A);
    return v[B-1];
}