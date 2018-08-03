/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

LINK: https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B)
{
    if(A==NULL)
        return A;
 
    ListNode *temp = A;
    int cnt=0;
    while(temp)
    {
        temp = temp->next;
        cnt++;
    }
 
    int n=cnt-B;
    if(n<=0)
    {
        A = A->next;
        return A;
    }
    temp = A;
 
    for(int i=0;i<n-1;i++)
        temp = temp->next;
    temp->next = temp->next->next;
 
    return A;
}
