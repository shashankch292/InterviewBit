/*
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

LINK: https://www.interviewbit.com/problems/preorder-traversal/
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
vector<int> Solution::preorderTraversal(TreeNode* A)
{
    vector<int> res;
    stack<TreeNode*> st;
 
    st.push(A);
    TreeNode* curr;
 
    while(!st.empty())
    {
        curr = st.top();
        st.pop();
        res.push_back(curr->val);
 
        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
    }
    return res;
}