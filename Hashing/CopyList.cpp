/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.

LINK: https://www.interviewbit.com/problems/copy-list/
*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A)
{
    RandomListNode *head = new RandomListNode(0);
 
    RandomListNode *temp1 = A, *temp2 = head;
 
    while(temp1)
    {
        temp2->label = temp1->label;
        temp2->random = temp1->random;
        RandomListNode *next = temp1->next;
        temp1->next = temp2;
        temp1 = next;
        if(temp1)
        {
            temp2->next = new RandomListNode(0);
            temp2 = temp2->next;
        }
    }
 
    temp2 = head;
 
    while(temp2)
    {
        if(temp2->random)
        {
            temp2->random = temp2->random->next;
        }
 
        temp2 = temp2->next;
    }
 
    return head;
}