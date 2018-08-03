/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

LINK: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head)
{
    if(head==NULL)
        return head;
 
    int pval = head->val;
    ListNode *temp = head->next, *ptemp = head;
 
    while(temp!=NULL)
    {
        if(temp->val == pval)
        {
            temp = temp->next;
        }
        else
        {
            ptemp->next = temp;
            ptemp = temp;
            pval = ptemp->val;
            temp = temp->next;
        }
    }
 
    ptemp->next = temp;
    return head;
}