/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

LINK: https://www.interviewbit.com/problems/merge-two-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B)
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