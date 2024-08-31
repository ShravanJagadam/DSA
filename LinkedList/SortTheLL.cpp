/*Interview BIt : https://www.interviewbit.com/problems/sort-list/
Sort List
Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* s1, ListNode* s2){
    
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(s1 != NULL && s2 != NULL){
        if(s1->val < s2->val){
            temp->next = s1;
            s1 = s1->next;
            temp = temp->next;
        }
        else{
            temp->next = s2;
            s2 = s2->next;
            temp = temp->next;
        }
    }
    if(s1 != NULL)
        temp->next = s1; 
    else    
        temp->next = s2;
    
    return dummy->next; 
}

ListNode* findMid(ListNode* A, bool flag){
    if(A ==  NULL || A->next == NULL)
        return A;
    ListNode* s = A; 
    ListNode* f = A; 
    
    while(f->next != NULL && f->next->next != NULL){//odd length or even length first mid element
        s = s->next;
        f = f->next->next;
    }
    if(f->next == NULL || flag == true)
        return s;
    return s->next;
}
 
ListNode* MS(ListNode* A){
    
    if(A->next == NULL){//didvide the LL until a len of the LL is 1
        return A;
    }
    
    //get the mid 
    ListNode* mid = findMid(A,true);
    
    ListNode* h1 = mid->next;//store the next of mid
    mid->next = NULL;//divide the LL into two halves(breaking link)
    
    ListNode* s1 = MS(A);
    ListNode* s2 = MS(h1);//s1 and s2 being the heads of the sorted LL
    
    return merge(s1,s2);
    
    
}

ListNode* Solution::sortList(ListNode* A) {
    //Use mergesort()
    //divide the lli until there is single node and then sort and merge the lli
    
    if(A == NULL || A->next == NULL)
        return A;
    
    return MS(A);
    
}
/*
Approach : Use Mergesort
1.find the mid using findMid 
2.Store the next node of the mid, else you will loose track to it after breaking
3.Break the link between mid node and its next node(dividing the LL into 2 equal halaves)
4.Consider this 2 problems as different problems are solve them and merge them
*/