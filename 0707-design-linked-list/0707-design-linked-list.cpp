class MyLinkedList {
    private:
    struct Node{
        int val;
        Node* next;
        Node(int v ) : val(v) , next(nullptr) {}
    };
    Node* dummyHead;
    int size;
public:
    MyLinkedList() {
        dummyHead  =new Node(-1);
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        Node* curr = dummyHead->next;
        for(int i = 0; i < index; i++){
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0 , val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 ) index = 0;
        if(index > size) return;
        Node* prev = dummyHead;
         for(int i = 0; i < index; i++){
            prev  =prev->next;
        }
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
       if(index < 0 || index >= size) return;
       Node* prev = dummyHead;
       for(int i = 0; i < index; i++){
        prev = prev->next;
       }
       Node* toDel = prev->next;
       prev->next = toDel->next;
       delete toDel;
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