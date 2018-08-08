/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/symmetric-binary-tree/
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
int Solution::isSymmetric(TreeNode* A)
{
    vector<int> v = inorderTraversal(A);
    int n = v.size();
 
    for(int i=0;i<n/2;i++)
    {
        if(v[i]!=v[n-i-1])
            return 0;
    }
    return 1;
}