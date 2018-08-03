/*
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

LINK: https://www.interviewbit.com/problems/k-reverse-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head, int k)
{
    ListNode *prev,*curr,*next,*templ,*tempr;
    curr = templ = head;
    prev = tempr = NULL;
    int i=1,flag=0;
 
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
 
        if(i==k)
        {
            if(flag==0)
            {
                head = prev;
                tempr = curr;
                flag = 1;
            }
            else
            {
                templ->next = prev;
                templ = tempr;
                tempr = curr;
            }
            i=0;
            prev = NULL;
        }
        i++;
    }
 
    return head;
}
