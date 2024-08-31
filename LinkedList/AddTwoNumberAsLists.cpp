/*
Interview BIT : https://www.interviewbit.com/problems/add-two-numbers-as-lists/
Add Two Numbers as Lists

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list

So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* solve(ListNode* r1, ListNode* r2, ListNode* curr){
    ListNode* head = curr;
    ListNode* temp = head;
    int sum = 0, carry = 0,digit;
    ListNode* prev;
    while(r1 != NULL && r2 != NULL){
        sum = (r1->val) + (r2->val)+carry;
        digit = sum%10;
        carry = sum/10;   
        
        temp->val = digit; 
        r1 = r1->next; 
        r2 = r2->next;
        if(temp->next == NULL)//consider the test case l1 : 5;l2 = 5, 
                prev = temp;
       
        temp = temp->next; 
        
    }
    //Now carry might not be zero we have to add that to the next node
    
    while(temp != NULL){
        sum = (temp->val) + carry;
        digit = sum%10;
        carry = sum/10;
        
        temp->val = digit; 
        if(temp->next == NULL)// Whenevr we are at the last node, we store that in prev, and use it when carry != 0
            prev = temp;
        temp = temp->next;
    }
    //after adding to the last node still the carry may not be zero
    if(carry != 0){
        prev->next = new ListNode(carry);
    }
    return head;
    
}
 
ListNode* revLL(ListNode* h){
    ListNode* prev = NULL; 
    ListNode* nxt; 
    while(h != NULL){
        nxt = h->next;
        h->next = prev; 
        prev= prev->next;
        h = nxt;
    }
    return prev;//as prev has the last node
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* t1 = A; 
    ListNode* t2 = B;
    
    long long int s1 = 0, s2 = 0;
    while(t1 != NULL){
        s1++;
        t1 = t1->next;
    } //find the size of both the LL, and we overwrite the val in the larger LL
    while(t2 != NULL ) {
        s2++;
        t2 = t2->next;
    }
    
    //revers A and B 
    ListNode* r1 = A;
    ListNode* r2 = B;
    
    //Add the corresponding node val and get the single digit and carry and overwrite in the LL of larger size
    
    if(s1>s2){
        return solve(r1,r2,r1);
    }
    else{
        return solve(r1,r2,r2);
    }
}
/*
Approach : 
find the LL having greater size and use that LL to overwrite the values after each addition 

Traverse and add corresponding node values from both the LL and also the carry 

Overwrite the sum%10 in the LL having greater size and update the carry as sum/10;

Once any one the LL finshes, still the carry may not be 0; 

Continue traversing the LL and get the sum = (node->val)+ carry 

After finishing traveseing this LL as well , still the carry may not be 0 

So we need the last node pointer to the LL to attached a new node with val as carry 

So we store that in prev

Edge cases:

L1 : 5
L2 : 5

Both l1 & l2 becomes NULL at the same time , but the carry is not 0.
below is the soltuion using a single Loop

*/
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode dummy_head = new ListNode(0);
        ListNode curr = dummy_head;
        while(l1 != null || l2 != null || carry != 0)
        {
            int value1 = l1 != null ? l1.val :0;
            int value2 = l2 != null ? l2.val :0;

            int sum = value1 + value2 + carry;
            ListNode node = new ListNode(sum%10);
            
            carry = sum/10;

            curr.next = node;
            curr = curr.next;

            l1 = l1 != null ? l1.next: null ;
            l2 = l2 != null ? l2.next: null;

        }
        return dummy_head.next;
    }
}