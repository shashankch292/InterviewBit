/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.

LINK: https://www.interviewbit.com/problems/reverse-link-list-ii/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n)
{
    if(m==n)
        return A;
    ListNode *temp = A;
    int i=1;
    while(i<m-1)
    {
        temp = temp->next;
        i++;
    }
    ListNode *prev = temp->next, *cur = temp->next->next, *next=NULL;
    if(m==1)
    {
        prev = temp;
        cur = temp->next;
        n++;
    }
 
    while(i<n-1)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        i++;
    }
 
    if(m==1)
    {
        A->next = cur;
        A = prev;
    }
    else
    {
        temp->next->next = cur;
        temp->next = prev;
    }
    return A;
}