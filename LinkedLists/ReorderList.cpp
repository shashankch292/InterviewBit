/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

LINK: https://www.interviewbit.com/problems/reorder-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseList(ListNode* head)
{
    ListNode *prev,*curr,*next;
    curr = head;
    prev = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
 
ListNode* Solution::reorderList(ListNode* A)
{
    ListNode *slow = A, *fast = A->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
 
    ListNode *head1 = A;
    ListNode *head2 = slow->next;
    slow->next = NULL;
 
    head2 = reverseList(head2);
 
    while(head1 && head2)
    {
        ListNode *next1 = head1->next, *next2 = head2->next;
 
        head1->next = head2;
        head2->next = next1;
        head1 = next1;
        head2 = next2;
    }
 
    if(head2)
        head1->next = head2;
 
    return A;
}