/*
Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]


Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.

LINK: https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
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
 
map<int, vector<pair<int,int> > > mp;
 
bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first < b.first;
}
 
void traverse(TreeNode* root, int x, int d)
{
    if(!root)
        return;
    mp[x].push_back({d,root->val});
 
    traverse(root->left,x-1,d+1);
    traverse(root->right,x+1,d+1);
}
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A)
{
    mp.clear();
    traverse(A,0,0);
 
    vector< vector<int> > res;
 
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        vector<pair<int,int> > v = it->second;
        stable_sort(v.begin(), v.end(), comp);
        vector<int> vv;
        for(int i=0;i<v.size();i++)
            vv.push_back(v[i].second);
        res.push_back(vv);
    }
    return res;
}