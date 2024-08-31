/*InterviewBit : https://www.interviewbit.com/problems/rotate-list/

Rotate List

Problem Description
 
 

Given a list, rotate the list to the right by k places, where k is non-negative.


Problem Constraints
1 <= B <= 109


Input Format
The first argument is ListNode A, pointing to the head of the list.
The second argument is an integer B, representing the value of k.


Output Format
Return the rotated list.


Example Input
A = 1->2->3->4->5->NULL
B = 2


Example Output
4->5->1->2->3->NULL


Example Explanation
Given list: A = 1->2->3->4->5->NULL
Given B = 2;
After rotating A once, A = 5->1->2->3->4->NULL
After rotating A again, A = 4->5->1->2->3->NULL
Hence after rotating the given list A, for B = 2, return 4->5->1->2->3->NULL

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A == NULL || A->next == NULL)
        return A;
    int sz = 0;
    ListNode* t = A; 
    ListNode* lastNode;
    while(t != NULL)
    {
        sz++;
        if(t->next == NULL)
            lastNode = t;//store the last node to link it to the first node
        t = t->next;
    }
    B = B%sz;//B == 0 , then there is no need to rotate the LL
    if(B == 0)
        return A;
    ListNode* s = A; 
    ListNode* f = A;
    //Move fast ahead by B+1 times, so as to find the node "after which we have to break the link"
    //But before breaking the link, store its next node, that would be the head of the LL
    for(int i =0;i<B+1; i++)
        f = f->next;
    
    while(f != NULL){
        s = s->next;
        f = f->next;
    }
    
    ListNode* head = s->next;
    s->next = NULL;
    lastNode->next = A;
    return head;
    
}
