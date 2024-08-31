/*Inteview BIT : https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/
Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.
*/
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        ListNode* temp;//for internal looping
        int count = 0,k;

        while(curr != NULL){
            k = curr->val;
            count = 1;
            temp = curr->next;
            while(temp != NULL && temp->val == k){
                count++;
                temp = temp->next;
            }

            if(count > 1){
                prev->next = temp;
                curr = temp;
                
            }
            if(count == 1){
                prev = curr;
                curr = curr->next;
                
            }
        }
        return dummy->next;
     
    
}