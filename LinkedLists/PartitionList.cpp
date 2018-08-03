/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

LINK: https://www.interviewbit.com/problems/partition-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B)
{
    ListNode *lhead = NULL, *rhead = NULL;
    ListNode *templ = NULL, *tempr = NULL;
    ListNode *temp = A;
 
    while(temp)
    {
        if(temp->val < B)
        {
            if(templ==NULL)
                lhead = templ = temp;
            else
            {
                templ->next = temp;
                templ = temp;
            }
        }
        else
        {
            if(tempr==NULL)
                rhead = tempr = temp;
            else
            {
                tempr->next = temp;
                tempr = temp;
            }
        }
        temp = temp->next;
    }
 
    if(lhead==NULL)
        return rhead;
    if(rhead==NULL)
        return lhead;
    templ->next = rhead;
    tempr->next = NULL;
    return lhead;
}