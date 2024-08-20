/*Leetcode : 1721
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
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
    ListNode* swapNodes(ListNode* head, int k) {
        
        //traverse k-1 to get hold of the kth node from the begining
        
        ListNode* cur = head;
        ListNode* left;
        for(int i =0;i<k-1; i++)
            cur = cur->next;
        
        left = cur;

        ListNode* right = head;

        while(cur->next != NULL){
            right= right->next;
            cur = cur->next;
        }
        //swap the values in left and right
        int kk = left->val;
        left->val = right->val;
        right->val = kk;

        return head; 
    }
};


/*Approach :Distance from the begining to the kth node is equal to the distance between kth node from end and the last node.

traverse k-1 times and get the kth node from the begining (say left)

Intialise another node from the head(right), one node from the left(curr) and 

Start moving both the pointer 1  step ahead until curr node reaches the last node 

Now the right node is on the kth node from end.  


*/