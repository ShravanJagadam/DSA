/*
Leetcode : 143. Reorder List
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
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
    ListNode*  revLL(ListNode* head){
        if(head->next == NULL)
            return head;
        ListNode* t = revLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return t;
    }

    ListNode* findMid(ListNode* head,bool flag){
        ListNode* s = head; 
        ListNode* f = head; 

        while(f->next != NULL && f->next->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        if(f->next == NULL || flag == true)//odd no of nodess || even no of nodes (return first mid node)
            return s;
        return s->next;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        ListNode* mid = findMid(head,true);
        ListNode* h2 = mid->next;
        ListNode* head2 =revLL(h2); //

        int xr = 1; 
        ListNode* t1 = head;
        ListNode* nxt1;
        ListNode* nxt2;
        ListNode* curr = head;
        while(head != NULL && head2 != NULL){
            if(xr == 1){
                nxt1 = head->next;
                curr->next = head2;
                curr = curr->next;
                head = nxt1;
                xr = xr ^ 1;
            }else{
                nxt2 = head2->next;
                curr->next = nxt1;
                curr = curr->next;
                head2 = nxt2;
                xr = xr^1;
            }
        }
        curr->next = NULL;// the last node is pointing to something undesired, hence make it NULL
    }
};

/*
Approach : 
1.Break the LL into 2 halves and then rev the 2nd LL 
2.
Join 1st node of (unreversed LL) to 1st node of reversed LL, then
Join 1st node of (reversed LL) to 2nd node of (unreversed LL),then
Join 2nd node of (unreversed LL) to 2nd node of reversed LL,then.
.
.
*/