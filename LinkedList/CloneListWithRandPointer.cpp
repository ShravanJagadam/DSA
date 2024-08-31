/*
Leetcode :  138
138. Copy List with Random Pointer
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL ) return head;
        /*
        A->for each"curr" node create a copy and attach it after "curr" node
        B->Link the random pointers 
        C->separate the ip and op ll 
        
        */
        //A
        //A->A'->B->B'->C->C'
        Node* t = head;
        Node* nxt;
        while(t!= NULL){
            nxt = t->next;
            t->next = new Node(t->val);
            t->next->next = nxt;
            t = t->next->next;
        }
        //B
        t=head;

        while(t != NULL && t->next != NULL){
            if(t->random != NULL)
                t->next->random = t->random->next;
            t = t->next->next;
        }
        //C
        Node* head2 = head->next;
        Node* h2 = head2;
        while(head != NULL && h2 != NULL && h2->next!=NULL){
            head->next=h2->next;
            h2->next = h2->next->next;
            head = head->next;
            h2 = h2->next;
        }
        head->next = NULL;//the last node of the original list is till connected to the its correspodning new node 
        return head2;

        
    }
};

/*
Approach 1;
3steps
A:
clone the list without the random pointers in the below way 
A->A'->B->B'->C->C'->....
A->original node 
A'->Its corresponding node
B:
Link random pointers
C:
seprate the oiginal list and new list

Approach2: 

step1: clone the SLL separately 
A'->B'->c'->NULL
Step 2: Map is used to store the {oiginla node , correspoding new node}
But in this approach we are using extra space.
*/