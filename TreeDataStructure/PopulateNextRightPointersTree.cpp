/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 Note:
You may only use constant extra space.
Example :

Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 Note 1: that using recursion has memory overhead and does not qualify for constant space.
Note 2: The tree need not be a perfect binary tree.

LINK: https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
TreeLinkNode* getNext(TreeLinkNode* root)
{
    TreeLinkNode* temp = root->next;
    while(temp)
    {
        if(temp->left)
            return temp->left;
        if(temp->right)
            return temp->right;
        temp = temp->next;
    }
    return NULL;
}
 
void Solution::connect(TreeLinkNode* A)
{
    if(A==NULL)
        return;
 
    A->next = NULL;
 
    while(A)
    {
        TreeLinkNode* temp = A;
        while(temp)
        {
            if(temp->left)
            {
                if(temp->right)
                    temp->left->next = temp->right;
                else
                    temp->left->next = getNext(temp);
            }
            if(temp->right)
                temp->right->next = getNext(temp);
 
            temp = temp->next;
        }
        if(A->left)
            A = A->left;
        else
        if(A->right)
            A = A->right;
        else
            A = getNext(A);
    }
}