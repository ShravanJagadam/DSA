/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL || head->next == NULL)
            return false;
        ListNode* s = head;
        ListNode* f = head->next->next;

        while(f != NULL && f->next != NULL){
            s = s->next;
            f = f->next->next;
            if(s == f )
                return true;
        }
        return false;        
    }
};
/*
1.If there is a cycle the slow and
fast will definetely meet the at some point in the loop(cycle) */