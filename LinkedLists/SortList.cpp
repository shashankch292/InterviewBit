/*
Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5

LINK: https://www.interviewbit.com/problems/sort-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* merge(ListNode* A, ListNode* B)
{
    if(A==NULL)
        return B;
    if(B==NULL)
        return A;
 
    ListNode *tempA = A, *tempB = B, *head=NULL;
 
    if(A->val<B->val)
    {
        head = A;
        tempA = tempA->next;
    }
    else
    {
        head = B;
        tempB = tempB->next;
    }
 
    ListNode *temp = head;
 
    while(tempA!=NULL && tempB!=NULL)
    {
        if(tempA->val < tempB->val)
        {
            temp->next = tempA;
            temp = tempA;
            tempA = tempA->next;
        }
        else
        {
            temp->next = tempB;
            temp = tempB;
            tempB = tempB->next;
        }
    }
 
    if(tempA!=NULL)
        temp->next=tempA;
    if(tempB!=NULL)
        temp->next=tempB;
 
    return head;
}
 
ListNode* Solution::sortList(ListNode* head)
{
    if(!head || !head->next)
        return head;
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
 
    ListNode *left = head, *right = slow->next;
    slow->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return merge(left, right);
}    