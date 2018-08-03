/*
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

LINK: https://www.interviewbit.com/problems/insertion-sort-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A)
{
    ListNode *head = NULL;
    ListNode *temp = A;
 
    while(temp)
    {
        ListNode *nxt = temp->next;
        if(head == NULL || head->val>=temp->val)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            ListNode *curr = head;
            while(curr->next!=NULL && curr->next->val < temp->val)
                curr = curr->next;
            temp->next = curr->next;
            curr->next = temp;
        }
        temp = nxt;
    }
    return head;
}
