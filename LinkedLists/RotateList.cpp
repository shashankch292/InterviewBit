/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

LINK: https://www.interviewbit.com/problems/rotate-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B)
{
    if(A==NULL)
        return A;
 
    ListNode *temp = A, *head = A;
    int cnt=0;
    while(temp)
    {
        temp = temp->next;
        cnt++;
    }
 
    B = B%cnt;
    if(B==0)
        return A;
    B = cnt-B;
 
    temp = A;
    for(int i=0;i<B-1;i++)
        temp = temp->next;
 
    head = temp->next;
    temp->next = NULL;
    temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = A;
 
    return head;
}