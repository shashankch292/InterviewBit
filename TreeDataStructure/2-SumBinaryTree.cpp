/*
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0

LINK: https://www.interviewbit.com/problems/2sum-binary-tree/
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
int Solution::t2Sum(TreeNode* A, int B)
{
    stack<TreeNode*> s1,s2;
    TreeNode* temp1 = A;
    TreeNode* temp2 = A;
 
    while(!s1.empty() || !s2.empty() || temp1 || temp2)
    {
        if(temp1 || temp2)
        {
            if(temp1)
            {
                s1.push(temp1);
                temp1 = temp1->left;
            }
            if(temp2)
            {
                s2.push(temp2);
                temp2 = temp2->right;
            }
        }
        else
        {
            if(s1.top() == s2.top())
                break;
 
            int num1 = s1.top()->val;
            int num2 = s2.top()->val;
 
            if(num1+num2 == B)
                return 1;
 
            if(num1+num2 < B)
            {
                temp1 = s1.top()->right;
                s1.pop();
            }
            else
            {
                temp2 = s2.top()->left;
                s2.pop();
            }
        }
    }
    return 0;
}
