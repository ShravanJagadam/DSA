
//Iterative Approach
ListNode* revLL(ListNode* st){//recursive approach
    if(st == NULL || st->next == NULL)
        return st;

    ListNode* prev = NULL;
    ListNode* curr = st;
    ListNode* nxt;

    while(curr != NULL)
    {
        nxt = curr->next;//store the next node
        curr->next = prev;
        prev = curr;
        curr = nxt;

    }
    return prev;
}

//Recursive Approach
ListNode* revLL(ListNode* st){//recursive approach
        if(st->next == NULL)
            return st;
        
        ListNode* t = revLL(st->next);
        st->next->next = st;
        st->next = NULL;
        return t;
}