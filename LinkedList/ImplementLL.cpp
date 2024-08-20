class Node{
public:
    int val; 
    Node* next; 

    Node(int v){
        val = v;
        next = NULL;
    }
};



class MyLinkedList {

public:
    Node* head; 
    int size;
public:
    MyLinkedList() {
        head = new Node(0);//let this be the dummy node
        size = 0;
    }
    
    int get(int index) {

        if(index < 0 || index >= size) return -1;

        Node* curr = head;
        for(int i =0;i<index+1; i++)
        {
            curr = curr->next;
        }
        return curr->val;
    }
    void addAtHead(int val) {
       
       addAtIndex(0,val);
    
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        
        if(index < 0 || index > size)
            return;
        Node* curr = head;
        Node* newNode = new Node(val);

        size++;
        for(int i =0;i<index; i++)
            curr = curr->next;

        newNode->next = curr->next;
        curr->next = newNode;        

    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return; 

        Node* curr = head;
        for(int i =0;i<index; i++)
            curr = curr->next;
        curr->next = curr->next->next;
        size--;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */