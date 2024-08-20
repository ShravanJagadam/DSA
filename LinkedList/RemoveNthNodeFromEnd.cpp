/*
Remove Nth Node from List End
Programming
Linked Lists
easy
40.9% Success

218

20

Bookmark
Asked In:
Problem Description
 
 

Given a linked list A, remove the B-th node from the end of the list and return its head.

For example, Given linked list: 1->2->3->4->5, and B = 2. After removing the second node from the end, the linked list becomes 1->2->3->5.

NOTE: If B is greater than the size of the list, remove the first node of the list.

NOTE: Try doing it using constant additional space.



Problem Constraints
 1 <= |A| <= 106 



Input Format
 The first argument of input contains a pointer to the head of the linked list. 

 The second argument of input contains the integer B. 



Output Format
 Return the head of the linked list after deleting the B-th element from the end. 



Example Input
 Input 1: 

A = [1, 2, 3, 4, 5]
B = 2
 Input 2: 

A = [1]
B = 1


Example Output
 Output 1: 

[1, 2, 3, 5]
 Output 2: 

 [] 


Example Explanation
Explanation 1:

In the first example, 4 is the second last element.
Explanation 2:

In the second example, 1 is the first and the last element.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    //use slow and fast pointer approach 
    //move the fast pointer B+1 ahead times ahead
    
    ListNode* sptr = A;
    ListNode* fptr = A; 
    for(int i =0; i<B+1; i++){
        if(fptr != NULL)
            fptr = fptr->next;
        else
            break;
    }
    
    if(fptr == NULL)
        return A->next;
    while(fptr != NULL){
        sptr = sptr->next;
        fptr = fptr->next;
    }
    sptr->next = sptr->next->next;
    return A;  
    
}


/*
Delete the Nth node from end

Approach1 : traverse and calculate the length of the LL, calculate the node number 
to be deleted from the end 
Traverse to the previous node and unlink it
The above approach requires 2 traversals of the LL

Approach 2: Only one traversal 
usign slow and fast pointer approach 
slowptr = head;
fastptr = head;
move fastptr  N+1 times, then move both the ptrs and same pace
when fastptr reach the end of the LL, slowptr is on the node just before the 
Nth node, unlink its next Node.

*/