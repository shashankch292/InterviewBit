/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

LINK: https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* head)
{
    if(!head || !head->next)
        return head;
 
    ListNode *fst = head, *sec = head->next;
    fst->next = swapPairs(sec->next);
    sec->next = fst;
    head = sec;
    return head;
}
