/*Given a linked list A of length N and an integer B.

You need to reverse every alternate B nodes in the linked list A.

LINK - https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

Example Input
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
 B = 3
Input 2:

 A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
 B = 2

Example Output
Output 1:

 7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
Output 2:

 4 -> 1 -> 6 -> 6 -> 10 -> 4
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::solve(ListNode* A, int B) {
	if (A == NULL || A->next == NULL) {
		return A;
	}
	ListNode* tail = A, *head;
	ListNode* curr = A, *prev, *nxt;
	for (int i = 0; i < B; i++) {
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	head = prev;
	if (curr) {
		tail->next = curr;
		for (int i = 0; i < B; i++) {
			tail = curr;
			curr = curr->next;
		}
	}
	ListNode* temp_head = solve(curr, B);
	tail->next = temp_head;
	return head;
}