/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

LINK: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode *temp = NULL, *ptemp = head;
    int cnt=1;
 
    while(ptemp->next!=NULL)
    {
        if(ptemp->next->val == pval)
        {
            ptemp = ptemp->next;
            cnt++;
        }
        else
        {
            if(cnt<=1)
            {
                if(temp==NULL)
                    head = temp = ptemp;
                else
                {
                    temp->next = ptemp;
                    temp = ptemp;
                }
            }
            ptemp = ptemp->next;
            pval = ptemp->val;
            cnt=1;
        }
    }
 
    if(cnt<=1)
    {
        if(temp==NULL)
            head = temp = ptemp;
        else
        {
            temp->next = ptemp;
            temp = ptemp;
        }
    }
 
    if(temp==NULL)
        return temp;
    temp->next=NULL;
 
    return head;
}