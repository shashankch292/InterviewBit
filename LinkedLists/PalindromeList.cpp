/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

LINK: https://www.interviewbit.com/problems/palindrome-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int ispalin(ListNode **left, ListNode *right)
{
    if(right==NULL)
        return 1;
 
    int ck = ispalin(left, right->next);
    if(ck==0)
        return 0;
 
    int ckn = 0;
    if(((*left)->val) == (right->val))
        ckn=1;
 
    *left = (*left)->next;
    return ckn;
}
 
int Solution::lPalin(ListNode* head)
{
    return ispalin(&head, head);
}