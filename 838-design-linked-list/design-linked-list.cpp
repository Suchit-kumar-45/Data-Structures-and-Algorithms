class MyLinkedList {
public:
    class Node{
        public:
        int val;
        Node* next;
        Node(int v)
        {
            val=v;
            next=NULL;
        }
    };
    Node* head;
    int size;
    MyLinkedList() {
        head=NULL;
        size=0;
        
    }
    
    int get(int index) {
        int i=0;
        Node* temp=head;
        if(index>=size || index<0)
        {
            return -1;
        }
        while(i<index)
        {
            temp=temp->next;
            i++;
        }
        return temp->val;
        
    }
    
    void addAtHead(int val) {
        Node* newnode=new Node(val);
        newnode->next=head;
        head=newnode;
        size++;
        
    }
    
    void addAtTail(int val) {
        Node* temp=head;
        Node* newNode= new Node(val);
        if(head==NULL){
            head=newNode;
            size++;
            return;
        }
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
        size++;
        
    }
    
    void addAtIndex(int index, int val) {
        Node* curr=head;
        Node* prev=NULL;
        int i=0;
        Node* newNode=new Node(val);
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        while(i<index)
        {
            prev=curr;
            curr=curr->next;
            i++;
        }
        
        prev->next=newNode;
        newNode->next=curr;
        size++;
        
    }
    
    void deleteAtIndex(int index) {
        int i=0;
        Node* curr=head;
        Node* prev=NULL;
        if(index>=size || index<0)
            return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        while(i<index)
        {
            prev=curr;
            curr=curr->next;
            i++;
        }
        prev->next=curr->next;
        delete curr;
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