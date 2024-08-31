/*
Leetcode 86. Partition List
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* d1 = new ListNode(-1); //stores all the nodes < x
        
        ListNode* d2 = new ListNode(-2);
        ListNode* h1 = d1;
        ListNode* h2 = d2;

        while(head != NULL){
            if(head->val < x)
            {
                d1->next = head;
                d1 = d1->next;
                head= head->next;
            }
            else{
                d2->next = head;
                d2 = d2->next;
                head = head->next;
            }
        }
        d2->next = NULL;
        d1->next = h2->next;
        h2->next = NULL;

        return h1->next;

        
    }
};
/*
Maintain 2 separate LLs*/