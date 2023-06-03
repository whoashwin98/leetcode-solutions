// https://leetcode.com/problems/design-linked-list

class Node {
    public:
    int val;
    Node* next;
    Node(int _val) {
        val = _val;
        next = NULL;
    }
};

class MyLinkedList {
    Node* head;
    Node* tail;
public:
    MyLinkedList() {
        head = tail = NULL;
    }
    
    int get(int index) {
        if(head == NULL) return -1;

        Node* temp = head;
        int i = 0;
        while(i < index) {
            temp = temp->next;
            i++;
        }

        return temp ? temp->val : -1;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);

        if(head == NULL) {
            head = tail = node;
        }

        else {
            node->next = head;
            head = node;
        }
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);

        if(head == NULL) head = tail = node;

        else {
            tail->next = node;
            tail = node;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
            return;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* node = new Node(val);
        int i=0;

        while(curr != NULL && i < index) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        prev->next = node;
        node->next = curr;
    }
    
    void deleteAtIndex(int index) {
        if(index == 0) {
            head = head->next;
            return;
        }

        Node* prev = NULL;
        Node* curr = head;
        int i=0;

        while(curr != NULL && i < index) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        prev->next = curr->next;
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