/*
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST          

LINK: https://www.interviewbit.com/problems/recover-binary-search-tree/
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
 
void correct(TreeNode *root, TreeNode* &fst, TreeNode* &mid, TreeNode* &lst, TreeNode* &prev)
{
    if(!root)
        return;
 
    correct(root->left, fst, mid, lst, prev);
 
    if(prev && prev->val>root->val)
    {
        if(!fst)
        {
            fst = prev;
            mid = root;
        }
        else
            lst = root;
    }
 
    prev = root;
 
    correct(root->right, fst, mid, lst, prev);
}
 
vector<int> Solution::recoverTree(TreeNode* A)
{
    TreeNode *fst, *mid, *lst, *prev;
    fst = mid = lst = prev = NULL;
 
    correct(A,fst,mid,lst,prev);
 
    vector<int> res;
 
    if(fst && lst)
    {
        res.push_back(fst->val);
        res.push_back(lst->val);
    }
    else
    if(fst && mid)
    {
        res.push_back(mid->val);
        res.push_back(fst->val);
    }
 
    sort(res.begin(), res.end());
 
    return res;
}